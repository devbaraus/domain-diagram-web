import { Injectable, UnprocessableEntityException } from '@nestjs/common';
import { PrismaService } from '../database/prisma.service';
import * as bcrypt from 'bcrypt';

type RegisterCommand = {
  name: string;
  email: string;
  password: string;
};

@Injectable()
export class AuthService {
  constructor(private readonly prisma: PrismaService) {}

  async register({ name, email, password }: RegisterCommand) {
    const existingUser = await this.prisma.user.findUnique({
      where: {
        email,
      },
    });

    if (existingUser) {
      throw new UnprocessableEntityException('User already exists');
    }

    const hashedPassword = await bcrypt.hash(password, 10);

    return this.prisma.user.create({
      data: {
        name,
        email,
        password: hashedPassword,
      },
    });
  }
}
