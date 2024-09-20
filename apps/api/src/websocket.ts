import { WebSocketServer } from 'ws';
import * as Y from 'yjs';
const setupWSConnection = require('y-websocket/bin/utils').setupWSConnection;

// Mapa para armazenar os documentos Yjs compartilhados
const docs = new Map<string, Y.Doc>();

export const startWebSocketServer = (server: any) => {
    const wss = new WebSocketServer({ server });


    wss.on('connection', (ws, req) => {
        // Pega o docId da URL, caso esteja sendo utilizado.
        const urlParts = req.url?.split('/');
        const projectId = urlParts && urlParts[1]; // Exemplo: /my-doc-id

        console.log('Connection to Yjs WebSocket established', projectId);

        let doc: Y.Doc | undefined;

        if (projectId) {
            doc = docs.get(projectId);
            if (!doc) {
                doc = new Y.Doc();
                docs.set(projectId, doc);
            }

            // Setup da conexão WebSocket com Yjs
            setupWSConnection(ws, doc, { docName: projectId });
        }

        // Monitorar atualizações no documento Yjs
        doc?.on('update', async () => {
            // Quando o documento for atualizado, salvar no banco de dados
            const text = doc.getText('content');
            // const updatedContent = convertYjsDocToString(doc);
            // await saveDocumentToDB(docId, updatedContent);
            console.log(`Documento ${projectId} salvo no banco de dados`);
        });

        ws.on('close', () => {
            console.log(`Conexão fechada para o documento ${projectId}`);
        });
    });
};
