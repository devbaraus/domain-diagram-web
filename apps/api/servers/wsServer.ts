import WebSocket from 'ws';

export const startWebSocketServer = (server: any) => {
    const wss = new WebSocket.Server({ server });

    wss.on('connection', (ws) => {
        ws.on('message', (message) => {
            console.log(`Received message: ${message}`);
            ws.send('Hello from server');
        });

        ws.send('Connected to WebSocket server');
    });
};
