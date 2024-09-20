import app from './servers/httpServer';
import { createServer } from 'http';
import { startWebSocketServer } from './servers/wsServer';
import { startYjsWebSocketServer } from './servers/yjsWsServer';

const PORT = process.env.PORT || 3000;
const HOST = process.env.HOST || '0.0.0.0';

const server = createServer(app.callback());

// Inicializa WebSocket regular
// startWebSocketServer(server);

// Inicializa WebSocket para Yjs
startYjsWebSocketServer(server);

server.listen(PORT, () => {
    console.log(`Server is running on http://${HOST}:${PORT}`);
});
