import { randomBytes } from 'crypto';
import { prisma } from '../db';
import MessageResponse from '../interfaces/MessageResponse';
import { guardMiddleware, jwtMiddleware, projectTokenMiddleware } from '../middlewares';
import { Prisma, Project } from '@prisma/client';
import express from 'express';
import { z } from 'zod';

const router = express.Router();

function generateToken() {
    return randomBytes(16).toString('hex');
}


router.post<{}, Project | MessageResponse>('/', guardMiddleware('OR', jwtMiddleware), async (req, res) => {
    const schema = z.object({
        name: z.string().min(3).max(32),
        markup: z.string(),
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
            markup,
            diagram: {},
            embed: generateToken(),
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

router.get<{}, Project[] | MessageResponse>('/', guardMiddleware('OR', jwtMiddleware), async (req, res) => {
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

router.get<{ id: string }, Omit<Project, 'markup' | 'diagram'> | MessageResponse>('/:id', guardMiddleware('OR', projectTokenMiddleware, jwtMiddleware), async (req, res) => {
    const { user } = res.locals;
    const { embed_token } = req.query
    const { anonymous } = res.locals;

    const schema = z.object({
        id: z.coerce.number().positive()
    }).partial();

    const parsed = schema.safeParse(req.params);

    if (!parsed.success) {
        res.status(400).json({
            message: 'Validation failed',
        });
        return;
    }

    const { id } = parsed.data;


    const project = await prisma.project.findUnique({
        where: {
            id: id,
            public: anonymous ? embed_token ? undefined : true : undefined,
            embed: embed_token ? String(embed_token) : undefined,
            members: embed_token ? undefined : {
                some: {
                    userId: user.id,
                }
            }
        },
        select: {
            id: true,
            embed: true,
            name: true,
            public: true,
            status: true,
            members: {
                include: {
                    user: true,
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

router.put<{ id: string }, Project | MessageResponse>('/:id', guardMiddleware('OR', jwtMiddleware), async (req, res) => {
    const paramSchema = z.object({
        id: z.coerce.number().positive()
    }).partial();

    const paramParsed = paramSchema.safeParse(req.params);

    if (!paramParsed.success) {
        res.status(400).json({
            message: 'Validation failed',
        });
        return;
    }

    const { id } = paramParsed.data;

    const schema = z.object({
        name: z.string().min(3).max(32),
        members: z.array(z.object({
            role: z.string(),
            email: z.string(),
        })),
        public: z.boolean(),
        embed: z.boolean(),
    }).partial();

    const { user } = res.locals;


    const parsed = schema.safeParse(req.body);

    if (!parsed.success) {
        res.status(400).json({
            message: `Validation failed ${parsed.error.issues}`,
        });
        return;
    }

    const { name, public: isPublic, embed, members } = parsed.data;

    let foundUsers: {
        id: number;
        email: string;
        name: string;
        password: string;
        active: boolean;
    }[] = [];

    if (members) {
        foundUsers = await prisma.user.findMany({
            where: {
                email: {
                    in: members?.map(member => member.email) ?? []
                }
            }
        });

        if (foundUsers.length !== members?.length) {
            res.status(400).json({
                message: 'Some users not found',
            });
            return;
        }
    }

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
            name,
            public: isPublic,
            embed,
            members: members ? {
                deleteMany: {},
                createMany: {
                    data: members?.map(member => ({
                        role: member.role,
                        userId: foundUsers.find(u => u.email === member.email)?.id,
                    })) ?? []
                }
            } : undefined
        }
    })

    res.json(project);
})

router.delete<{ id: string }, Project | MessageResponse>('/:id', guardMiddleware('OR', jwtMiddleware), async (req, res) => {
    const { user } = res.locals;

    const schema = z.object({
        id: z.coerce.number().positive()
    }).partial();

    const parsed = schema.safeParse(req.params);

    if (!parsed.success) {
        res.status(400).json({
            message: 'Validation failed',
        });
        return;
    }

    const { id } = parsed.data;

    const project = await prisma.project.findUnique({
        where: {
            id: id,
            members: {
                some: {
                    userId: user.id,
                    role: 'OWNER',
                }
            }
        },
    })

    if (!project) {
        res.status(404).json({
            message: 'Project not found',
        });
        return;
    }

    await prisma.$transaction([
        prisma.projectMember.deleteMany({
            where: {
                projectId: project.id,
            }
        }),
        prisma.project.delete({
            where: {
                id: project.id,
            }
        })
    ])



    res.json(project);
})


export default router;
