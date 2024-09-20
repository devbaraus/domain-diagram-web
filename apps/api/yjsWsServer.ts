import WebSocket from 'ws';
import * as Y from 'yjs';
import { WebsocketProvider } from 'y-websocket';

// Mapa para armazenar os documentos Yjs compartilhados
const docs = new Map<string, Y.Doc>();

export const startYjsWebSocketServer = (server: any) => {
    const wss = new WebSocket.Server({ server });

    wss.on('connection', (ws, req) => {
        const urlParts = req.url?.split('/');
        const docId = urlParts && urlParts[1]; // Assumindo que o docId será enviado na URL

        if (!docId) {
            ws.close();
            return;
        }

        // Obtenha ou crie um novo documento Yjs para o docId
        let doc = docs.get(docId);
        if (!doc) {
            doc = new Y.Doc();
            docs.set(docId, doc);
        }

        // Conectar o WebSocket ao documento Yjs
        const wsProvider = new WebsocketProvider(`ws://localhost:${process.env.PORT || 3000}`, docId, doc);

        wsProvider.on('status', (event: { status: string }) => {
            console.log(event.status); // Logs 'connected' or 'disconnected'
        });

        // Enviar atualizações para o documento
        ws.on('message', (message) => {
            const decodedMessage = JSON.parse(message.toString());
            if (decodedMessage && decodedMessage.update) {
                Y.applyUpdate(doc, decodedMessage.update);
            }
        });

        // Enviar atualizações aos clientes
        doc.on('update', (update) => {
            ws.send(JSON.stringify({ update }));
        });

        ws.on('close', () => {
            console.log('Client disconnected');
        });
    });
};
