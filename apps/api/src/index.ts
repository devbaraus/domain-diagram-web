import app from './app';
import { createServer } from 'http';
import { startWebSocketServer } from './websocket';

require('dotenv').config();

const PORT = process.env.PORT || 3000;
const HOST = process.env.HOST || '0.0.0.0';

const server = createServer(app);

// Inicializa WebSocket regular
startWebSocketServer(server);

// Inicializa WebSocket para Yjs

server.listen(PORT, () => {
  console.log(`Server is running on http://${HOST}:${PORT}`);
});