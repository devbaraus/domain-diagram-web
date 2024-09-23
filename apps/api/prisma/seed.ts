import { PrismaClient } from '@prisma/client'
import * as bcrypt from 'bcrypt';

const prisma = new PrismaClient()

async function main() {
    await prisma.user.upsert({
        where: { email: 'alice@prisma.io' },
        update: {},
        create: {
            email: 'me@baraus.dev',
            name: 'Bruno Alves',
            password: await bcrypt.hash('Admin1234)', 10),
            projects: {
                create: {
                    role: 'OWNER',
                    project: {
                        create: {
                            name: 'My First Project',
                        }
                    }
                }
            }
        },
    })
}

main()
    .then(async () => {
        await prisma.$disconnect()
    })
    .catch(async (e) => {
        console.error(e)
        await prisma.$disconnect()
        process.exit(1)
    })