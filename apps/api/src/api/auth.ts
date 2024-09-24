import { prisma } from '../db';
import { User } from '@prisma/client';
import express from 'express';
import { z } from 'zod';
import * as bcrypt from 'bcrypt';
import MessageResponse from '../interfaces/MessageResponse';

import _ from 'lodash';
import { signToken } from '../utils/jwt';

const router = express.Router();


type LoginRequest = {
    email: string;
    password: string;
};

type LoginResponse = {
    access_token: string;
    expires_at: number;
};

router.post<{}, Omit<User, 'password'> | MessageResponse, LoginRequest>('/register', async (req, res) => {
    const schema = z.object({
        name: z.string().min(3).max(32),
        email: z.string().email(),
        password: z.string().min(6).max(32),
    });

    const parsed = schema.safeParse(req.body);

    if (!parsed.success) {
        res.status(400).json({
            message: 'Validation failed',
        });
        return;
    }

    const { email, password, name } = parsed.data;

    const existingUser = await prisma.user.findUnique({
        where: {
            email,
        }
    })

    if (existingUser) {
        res.status(400).json({
            message: 'User already exists',
        });
        return;
    }

    const hashedPassword = await bcrypt.hash(password, 10);

    const user = await prisma.user.create({
        data: {
            name,
            email,
            password: hashedPassword,
        }
    });

    res.status(201).json(
        _.omit(user, ['password'])
    );
})

router.post<{}, LoginResponse | MessageResponse, LoginRequest>('/login',
    async (req, res) => {
        const schema = z.object({
            email: z.string().email(),
            password: z.string().min(6).max(32),
        })

        const parsed = schema.safeParse(req.body);

        if (!parsed.success) {
            res.status(400).json({
                message: 'Validation failed',
            });
            return;
        }

        const { email, password } = parsed.data;

        const user = await prisma.user.findUnique({
            where: {
                email,
            }
        })

        if (!user) {
            res.status(401).json({
                message: 'Invalid credentials',
            });
            return;
        }

        const isValid = await bcrypt.compare(password, user.password);

        if (!isValid) {
            res.status(401).json({
                message: 'Invalid credentials',
            });
            return;
        }

        const token = await signToken(user);

        res.status(200).json({
            access_token: token,
            expires_at: Date.now() + 1000 * 60 * 60 * 8,
        });
    })



export default router;
