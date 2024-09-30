import * as yjs from './yjs'
import { WebSocketServer } from 'ws';
import { LeveldbPersistence } from 'y-leveldb';
import * as Y from 'yjs';
import { prisma } from './db';
import { verifyToken } from './utils/jwt';

// Mapa para armazenar os documentos Yjs compartilhados
// const db = new LeveldbPersistence('persistence');
const persistence = {
    bindState: async (docName: any, content: string, ydoc: any) => {
        // const persistedYdoc = await db.getYDoc(docName);
        // const newUpdates = Y.encodeStateAsUpdate(ydoc);

        // db.storeUpdate(docName, newUpdates);
        // Y.applyUpdate(ydoc, Y.encodeStateAsUpdate(persistedYdoc));

        // // if (ydoc.share.size === 0) {
        // //     ydoc.getText('monaco').insert(0, content);
        // // }

        // ydoc.on('update', async (update: any) => {
        //     db.storeUpdate(docName, update);
        // });
    },
    writeState: async (docName: any, ydoc: any) => {
        try {
            const content = ydoc.getText('monaco').toJSON();

            await prisma.project.update({
                where: { id: Number(docName) },
                data: {
                    markup: content,
                },
            });
        } catch (e) {
            if (e.code == 'P2025') {
                return;
            }

            throw e;
        }
    },
}

yjs.setPersistence(persistence);


export const startWebSocketServer = (server: any) => {
    const wss = new WebSocketServer({ server });


    wss.on('connection', async (ws, req) => {
        // Pega o docId da URL, caso esteja sendo utilizado.
        const url = new URL(req.url as string, 'http://localhost:3000');
        const urlParts = url.pathname.match(/\/([^\/]+)/);
        const token = url.searchParams.get('access_token');
        const docName = urlParts && urlParts[1];


        // if (token == null) {
        //     ws.close();
        //     return;
        // }

        // const isValid = await verifyToken(token);

        // if (!isValid) {
        //     ws.close();
        //     return;
        // }

        // const user = await prisma.user.findUnique({
        //     where: {
        //         id: Number(isValid.payload.sub)
        //     }
        // })

        // if (!user) {
        //     ws.close();
        //     return;
        // }

        if (docName == null) {
            ws.close();
            return;
        }

        const project = await prisma.project.findUnique({
            where: {
                id: Number(docName),
                // members: {
                //     some: {
                //         userId: user.id,
                //     }
                // }
            },
        });

        if (project == null) {
            ws.close();
            return;
        }

        let ydoc = yjs.docs.get(docName);

        if (!ydoc) {
            ydoc = new yjs.WSSharedDoc(docName);

            const ytext = ydoc.getText('monaco');
            ytext.insert(0, project.markup);

            yjs.docs.set(docName, ydoc);
        }

        yjs.setupWSConnection(ws, req, ydoc);
    })
};