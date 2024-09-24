import { prisma } from '../db';
import MessageResponse from '../interfaces/MessageResponse';
import { jwtMiddleware } from '../middlewares';
import { Prisma, Project } from '@prisma/client';
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

router.get<{ id: string }, Omit<Project, 'markup' | 'diagram'> | MessageResponse>('/:id', async (req, res) => {
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


const updateSchema = z.object({
    name: z.string().min(3).max(32),
    members: z.array(z.object({
        role: z.string(),
        email: z.string(),
    })),
    public: z.boolean(),
    embed: z.boolean(),
}).partial();

type ProjectUpdateRequest = z.infer<typeof updateSchema>;

router.put<{ id: string }, Project | MessageResponse, ProjectUpdateRequest>('/:id', async (req, res) => {
    const { user } = res.locals;
    const { id } = req.params;

    const parsed = updateSchema.safeParse(req.body);

    if (!parsed.success) {
        res.status(400).json({
            message: 'Validation failed',
        });
        return;
    }

    const { name, public: isPublic, embed, members } = parsed.data;

    const foundUsers = await prisma.user.findMany({
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

router.delete<{ id: string }, Project | MessageResponse>('/:id', async (req, res) => {
    const { user } = res.locals;
    const { id } = req.params;

    const project = await prisma.project.findUnique({
        where: {
            id: parseInt(id),
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