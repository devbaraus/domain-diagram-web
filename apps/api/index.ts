import app from './httpServer';
import { createServer } from 'http';
import { startWebSocketServer } from './wsServer';
import { startYjsWebSocketServer } from './yjsWsServer';

const PORT = process.env.PORT || 3000;

const server = createServer(app.callback());

// Inicializa WebSocket regular
startWebSocketServer(server);

// Inicializa WebSocket para Yjs
startYjsWebSocketServer(server);

server.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});
