import { NextFunction, Request, Response } from 'express';

import ErrorResponse from './interfaces/ErrorResponse';
import { verifyToken } from './utils/jwt';
import { prisma } from './db';

export function notFound(req: Request, res: Response, next: NextFunction) {
  res.status(404);
  const error = new Error(`🔍 - Not Found - ${req.originalUrl}`);
  next(error);
}

// eslint-disable-next-line @typescript-eslint/no-unused-vars
export function errorHandler(err: Error, req: Request, res: Response<ErrorResponse>, next: NextFunction) {
  const statusCode = res.statusCode !== 200 ? res.statusCode : 500;
  res.status(statusCode);
  res.json({
    message: err.message,
    stack: process.env.NODE_ENV === 'production' ? '🥞' : err.stack,
  });
}

type AuthMiddleware = (req: Request, res: Response, next: NextFunction) => Promise<boolean>;

export function guardMiddleware(combining: 'OR' | 'AND', ...guards: AuthMiddleware[]) {
  return async (req: Request, res: Response, next: NextFunction) => {
    let result = combining === 'AND';

    for (const guard of guards) {
      if (combining === 'AND') {
        result = result && await guard(req, res, next);
      } else {
        result = result || await guard(req, res, next);
      }
    }

    if (!result) {
      res.status(401).json({
        message: 'Unauthorized'
      });
      return;
    }

    next();
  }
}

export async function projectTokenMiddleware(req: Request, res: Response, next: NextFunction): Promise<boolean> {
  const embedToken = req.query.embed_token as string;
  const projectId = req.params.id;

  const project = await prisma.project.count({
    where: {
      id: Number(projectId),
      public: !embedToken ? true : undefined,
      embed: embedToken
    }
  });

  if (!project) {
    return false
  }


  res.locals.authenticated = true;
  res.locals.anonymous = true;

  return true
}


export async function jwtMiddleware(req: Request, res: Response, next: NextFunction) {
  const tokenHeader = req.headers.authorization;
  const tokenQuery = req.query.access_token;

  let token = '';

  if (tokenHeader) {
    token = tokenHeader.split(' ')[1];
  } else if (tokenQuery) {
    token = tokenQuery as string;
  }

  if (!token) {
    return false
  }

  let isValid;

  try {
    // Verifica se o token é válido
    isValid = await verifyToken(token);

    if (!isValid) {
      return false
    }
  } catch (error) {
    return false
  }


  const user = await prisma.user.findUnique({
    where: {
      id: Number(isValid.payload.sub)
    }
  })

  if (!user) {
    return false
  }

  res.locals.user = user;
  res.locals.authenticated = true;
  res.locals.anonymous = false;

  return true
}

export async function jwtWsMiddleware(ws: WebSocket, req: Request) {
  const token = req.url?.split('/')[1];

  if (!token) {
    ws.close();
    return;
  }

  // Verifica se o token é válido
  const isValid = await verifyToken(token);

  if (!isValid) {
    ws.close();
    return;
  }

  const user = await prisma.user.findUnique({
    where: {
      id: Number(isValid.payload.sub)
    }
  })

  if (!user) {
    ws.close();
    return;
  }

}