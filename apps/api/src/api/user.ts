import { guardMiddleware, jwtMiddleware } from '../middlewares';
import { User } from '@prisma/client';
import express from 'express';
import _ from 'lodash';

const router = express.Router();

router.get<{}, Omit<User, 'password'>>('/me', guardMiddleware('OR', jwtMiddleware), (req, res) => {
    const { user } = res.locals

    res.json(_.omit(user, ['password']) as Omit<User, 'password'>);
})

// router.post<{}, Project | MessageResponse, ProjectCreateRequest>('/', async (req, res) => {
//     const schema = z.object({
//         name: z.string().min(3).max(32),
//         markup: z.string().optional(),
//     });

//     const parsed = schema.safeParse(req.body);

//     if (!parsed.success) {
//         res.status(400).json({
//             message: 'Validation failed',
//         });
//         return;
//     }

//     const { name, markup } = parsed.data;

//     const project = await prisma.project.create({
//         data: {
//             name,
//             markup: markup || '',
//             diagram: {}
//         }
//     })

//     res.json(project);
// })

// router.get<{}, Project[] | MessageResponse>('/', async (req, res) => {
//     const projects = await prisma.project.findMany();

//     res.json(projects);
// })

// router.get<{ id: string }, Project | MessageResponse>('/:id', async (req, res) => {
//     const { id } = req.params;

//     const project = await prisma.project.findUnique({
//         where: {
//             id: parseInt(id),
//         }
//     });

//     if (!project) {
//         res.status(404).json({
//             message: 'Project not found',
//         });
//         return;
//     }

//     res.json(project);
// })

// router.put<{ id: string }, Project | MessageResponse, ProjectCreateRequest>('/:id', async (req, res) => {
//     const { id } = req.params;

//     const schema = z.object({
//         name: z.string().min(3).max(32),
//         markup: z.string(),
//         diagram: z.object({}),
//     }).partial();

//     const parsed = schema.safeParse(req.body);

//     if (!parsed.success) {
//         res.status(400).json({
//             message: 'Validation failed',
//         });
//         return;
//     }

//     const { name, markup, diagram } = parsed.data;

//     const project = await prisma.project.update({
//         where: {
//             id: parseInt(id),
//         },
//         data: {
//             name,
//             markup,
//             diagram
//         }
//     })

//     res.json(project);
// })



export default router;
