import * as yjs from './yjs'
import { WebSocketServer } from 'ws';
import { LeveldbPersistence } from 'y-leveldb';
import * as Y from 'yjs';
import { prisma } from './db';

// Mapa para armazenar os documentos Yjs compartilhados
const db = new LeveldbPersistence('persistence');
const persistence = {
    bindState: async (docName: any, content: string, ydoc: any) => {
        const persistedYdoc = await db.getYDoc(docName);
        const newUpdates = Y.encodeStateAsUpdate(ydoc);

        db.storeUpdate(docName, newUpdates);
        Y.applyUpdate(ydoc, Y.encodeStateAsUpdate(persistedYdoc));

        // if (ydoc.share.size === 0) {
        //     ydoc.getText('monaco').insert(0, content);
        // }

        ydoc.on('update', async (update: any) => {
            db.storeUpdate(docName, update);
        });
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
        const docName = urlParts && urlParts[1];

        if (docName == null) {
            ws.close();
            return;
        }

        const project = await prisma.project.findUnique({
            where: {
                id: Number(docName),
            },
        });

        if (project == null) {
            ws.close();
            return;
        }

        yjs.setupWSConnection(ws, req, { docName: docName, content: project.markup });
    })
};



function logDocContent(doc: Y.Doc) {
    console.log('Logging Y.Doc content:');

    // Iterate over all shared types in the document
    doc.share.forEach((type, key) => {
        console.log(`Type: ${type.constructor.name}, Key: ${key}`);

        if (type instanceof Y.Map) {
            logMapContent(type);
        } else if (type instanceof Y.Array) {
            logArrayContent(type);
        } else if (type instanceof Y.Text) {
            logTextContent(type);
        }
    });
}

// Helper function to log Y.Map content
function logMapContent(map: Y.Map<any>) {
    console.log('Y.Map content:');
    map.forEach((value, key) => {
        console.log(`  Key: ${key}, Value: ${value}`);
    });
}

// Helper function to log Y.Array content
function logArrayContent(arr: Y.Array<any>) {
    console.log('Y.Array content:');
    arr.toArray().forEach((item, index) => {
        console.log(`  Index: ${index}, Item: ${item}`);
    });
}

// Helper function to log Y.Text content
function logTextContent(text: Y.Text) {
    console.log('Y.Text content:');
    console.log(`  Text: ${text.toString()}`);
}