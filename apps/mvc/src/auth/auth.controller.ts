import {
  Body,
  Controller,
  Get,
  Post,
  Redirect,
  Render,
  Res,
} from '@nestjs/common';
import { AuthService } from './auth.service';
import { RegisterDto } from './dto/register.dto';

@Controller('auth')
export class AuthController {
  constructor(private readonly service: AuthService) {}

  @Get()
  @Render('auth/login')
  login() {
    return {};
  }

  @Get('register')
  @Render('auth/register')
  register() {
    return {};
  }

  @Post('register')
  @Redirect('/auth')
  async registerPost(@Res() res, @Body() body: RegisterDto) {
    res.locals.template = 'auth/register';

    await this.service.register(body);

    return;
  }
}
