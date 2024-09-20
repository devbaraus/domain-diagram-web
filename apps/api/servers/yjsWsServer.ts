import WebSocket from 'ws';
import * as Y from 'yjs';
import { setupWSConnection } from 'y-websocket/bin/utils';

// Mapa para armazenar os documentos Yjs compartilhados
const docs = new Map<string, Y.Doc>();

export const startYjsWebSocketServer = (server: any) => {
    const wss = new WebSocket.Server({ server });

    wss.on('connection', (ws, req) => {
        // Pega o docId da URL, caso esteja sendo utilizado.
        const urlParts = req.url?.split('/');
        const docId = urlParts && urlParts[1]; // Exemplo: /my-doc-id

        console.log('Connection to Yjs WebSocket established', docId);

        if (docId) {
            let doc = docs.get(docId);
            if (!doc) {
                doc = new Y.Doc();
                docs.set(docId, doc);
            }

            // Setup da conexão WebSocket com Yjs
            setupWSConnection(ws, doc, { docName: docId });
        }
    });
};
