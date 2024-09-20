import * as yjs from './yjs'
import { WebSocketServer } from 'ws';
import { LeveldbPersistence } from 'y-leveldb';
import * as Y from 'yjs';

// Mapa para armazenar os documentos Yjs compartilhados
const db = new LeveldbPersistence('persistence');
const persistence = {
    bindState: async (docName: any, ydoc: any) => {
        const persistedYdoc = await db.getYDoc(docName);
        const newUpdates = Y.encodeStateAsUpdate(ydoc);
        db.storeUpdate(docName, newUpdates);
        Y.applyUpdate(ydoc, Y.encodeStateAsUpdate(persistedYdoc));
        ydoc.on('update', async (update: any) => {
            db.storeUpdate(docName, update);
        });
    },
    writeState: () => {
        return new Promise((resolve) => {
            resolve(true);
        });
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

        if (!docName) {
            ws.close();
        }

        // Setup da conexão WebSocket com Yjs
        yjs.setupWSConnection(ws, req, { docName: docName });
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