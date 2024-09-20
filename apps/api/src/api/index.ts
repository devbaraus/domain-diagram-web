import express from 'express';
import authRouter from './auth'
import projectRouter from './project'
import userRouter from './user'

const router = express.Router();


router.use('/auth', authRouter);
router.use('/projects', projectRouter);
router.use("/users", userRouter);

export default router;
