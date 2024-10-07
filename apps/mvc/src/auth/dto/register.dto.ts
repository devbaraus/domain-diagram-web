import { IsEmail, IsString, Length } from 'class-validator';

export class RegisterDto {
  @IsEmail()
  email: string;

  @IsString()
  @Length(3, 30)
  name: string;

  @IsString()
  @Length(8, 30)
  password: string;
}
