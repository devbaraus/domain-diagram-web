import { Prisma, PrismaClient } from '@prisma/client'

export const prisma = new PrismaClient();

// prisma.$extends({
//     model: {
//         user: {
//             async create(args: Prisma.UserCreateArgs) {
//                 return prisma.user.create({
//                     data: args.data,
//                 });
//             },
//         }
//     }

// })