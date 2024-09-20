import Koa from 'koa';
import bodyParser from 'koa-bodyparser';
// import userRoutes from './routes/userRoutes';
// import { errorMiddleware } from './middlewares/errorMiddleware';
// import { startWebSocketServer } from './websockets/wsServer';

const app = new Koa();

app.use(bodyParser());
// app.use(errorMiddleware);
// app.use(userRoutes.routes());
// app.use(userRoutes.allowedMethods());

export default app;
