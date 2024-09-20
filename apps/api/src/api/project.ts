import { prisma } from '../db';
import MessageResponse from '../interfaces/MessageResponse';
import { jwtMiddleware } from '../middlewares';
import { Project } from '@prisma/client';
import express from 'express';
import { z } from 'zod';

const router = express.Router();

router.use(jwtMiddleware)

type ProjectCreateRequest = {
    name: string;
    markup: string;
};


router.post<{}, Project | MessageResponse, ProjectCreateRequest>('/', async (req, res) => {
    const schema = z.object({
        name: z.string().min(3).max(32),
        markup: z.string().optional(),
    });

    const parsed = schema.safeParse(req.body);

    if (!parsed.success) {
        res.status(400).json({
            message: 'Validation failed',
        });
        return;
    }

    const { user } = res.locals;
    const { name, markup } = parsed.data;

    const project = await prisma.project.create({
        data: {
            name,
            members: {
                create: {
                    userId: user.id,
                    role: 'OWNER',
                }
            }
        }
    })

    res.json(project);
})

router.get<{}, Project[] | MessageResponse>('/', async (req, res) => {
    const { user } = res.locals;
    const projects = await prisma.project.findMany({
        where: {
            members: {
                some: {
                    userId: user.id,
                }
            }
        }
    });

    res.json(projects);
})

router.get<{ id: string }, Project | MessageResponse>('/:id', async (req, res) => {
    const { user } = res.locals;
    const { id } = req.params;

    const project = await prisma.project.findUnique({
        where: {
            id: parseInt(id),
            members: {
                some: {
                    userId: user.id,
                }
            }
        }
    });

    if (!project) {
        res.status(404).json({
            message: 'Project not found',
        });
        return;
    }

    res.json(project);
})

router.put<{ id: string }, Project | MessageResponse, ProjectCreateRequest>('/:id', async (req, res) => {
    const { user } = res.locals;
    const { id } = req.params;

    const schema = z.object({
        name: z.string().min(3).max(32),
    }).partial();

    const parsed = schema.safeParse(req.body);

    if (!parsed.success) {
        res.status(400).json({
            message: 'Validation failed',
        });
        return;
    }

    const { name, markup, diagram } = parsed.data;

    const project = await prisma.project.update({
        where: {
            id: parseInt(id),
            members: {
                some: {
                    userId: user.id,
                }
            }
        },
        data: {
            name
        }
    })

    res.json(project);
})



export default router;
