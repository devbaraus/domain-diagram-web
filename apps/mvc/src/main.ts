import { NestFactory } from '@nestjs/core';
import { AppModule } from './app.module';
import { NestExpressApplication } from '@nestjs/platform-express';
import * as minimist from 'minimist';
import * as morgan from 'morgan';
import { engine } from 'express-handlebars';
import * as path from 'node:path';
import 'dotenv/config';
import { ValidationPipe } from '@nestjs/common';
import { UnprocessableEntityFilter } from './filter/unprocessable-entity.filter';

const argv = minimist(process.argv.slice(2));

async function bootstrap() {
  const app = await NestFactory.create<NestExpressApplication>(AppModule);
  // app.enableCors({
  //   origin: argv.origin || '*',
  //   methods: 'GET,HEAD,PUT,PATCH,POST,DELETE',
  //   credentials: true,
  // })

  app.engine(
    'hbs',
    engine({
      extname: 'hbs',
      defaultLayout: 'main',
      encoding: 'utf8',
      layoutsDir: path.join(__dirname, '..', '..', 'views', 'layouts'),
      partialsDir: path.join(__dirname, '..', '..', 'views', 'partials'),
      helpers: {
        route_home: () => '/',
        route_login: () => '/auth',
        route_register: () => '/auth/register',
        route_project: (id: string) =>
          ['string', 'number'].includes(typeof id) ? `/p/${id}` : '/p',
        route_embed: (id: string) =>
          ['string', 'number'].includes(typeof id) ? `/e/${id}` : '/e',
      },
    }),
  );
  app.set('view engine', 'hbs');
  app.set('views', path.join(__dirname, '..', '..', 'views'));
  app.useStaticAssets(path.join(__dirname, '..', '..', 'public'));

  app.use(morgan('dev'));

  app.useGlobalPipes(new ValidationPipe());
  app.useGlobalFilters(new UnprocessableEntityFilter());

  await app.listen(4000, '0.0.0.0', () => {
    console.log('Server is running on http://localhost:4000');
  });
}

bootstrap();
