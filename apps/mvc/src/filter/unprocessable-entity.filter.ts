import { ArgumentsHost, Catch, ExceptionFilter, HttpException, UnprocessableEntityException } from '@nestjs/common';

import { Request, Response } from 'express';

@Catch(UnprocessableEntityException)
export class UnprocessableEntityFilter implements ExceptionFilter {
  catch(exception: HttpException, host: ArgumentsHost) {
    const ctx = host.switchToHttp();
    const response = ctx.getResponse<Response>();
    const request = ctx.getRequest<Request>();
    const status = exception.getStatus();

    response
      .status(status)
      .render(response.locals.template, {
        toasts: [
          {
            message: exception.message,
            type: 'error',
          },
        ],
      });
  }
}
