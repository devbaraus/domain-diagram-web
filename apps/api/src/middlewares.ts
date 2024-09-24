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
    return res.status(401).json({
      message: 'Token not provided',
    });
  }

  let isValid;

  try {
    // Verifica se o token é válido
    isValid = await verifyToken(token);

    if (!isValid) {
      return res.status(401).json({
        message: 'Invalid token',
      });
    }
  } catch (error) {
    return res.status(401).json({
      message: 'Invalid token',
    });
  }


  const user = await prisma.user.findUnique({
    where: {
      id: Number(isValid.payload.sub)
    }
  })

  if (!user) {
    return res.status(401).json({
      message: 'Invalid token',
    });
  }

  res.locals.user = user;

  next();
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