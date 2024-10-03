import express from 'express';
import morgan from 'morgan';
import helmet from 'helmet';
import cors from 'cors';

import * as middlewares from './middlewares';
import api from './api';
import MessageResponse from './interfaces/MessageResponse';


const app = express();

app.use(morgan('dev'));
app.use(helmet());
app.use(cors({
  credentials: true,
  origin: process.env.CORS_ORIGIN?.split(','),
  methods: ['GET', 'POST', 'PUT', 'DELETE'],
  allowedHeaders: ['Content-Type', 'Authorization'],

}));
app.use(express.json());

app.get<{}, MessageResponse>('/', (req, res) => {
  res.json({
    message: '🦄🌈✨👋🌎🌍🌏✨🌈🦄',
  });
});

app.use('', api);

app.use(middlewares.notFound);
app.use(middlewares.errorHandler);

export default app;
