FROM node:lts-slim AS builder

RUN npm install -g npm@latest

WORKDIR /app

COPY package*.json ./

RUN npm install

COPY . .

RUN npx prisma generate

RUN npm run build

FROM node:lts-slim AS runner

RUN apt-get update -y && apt-get install -y openssl

RUN npm install -g npm@latest pm2

WORKDIR /app

COPY --from=builder /app/package*.json ./

RUN npm install --only=production

COPY --from=builder /app/prisma ./prisma

RUN npx prisma generate

COPY --from=builder /app/dist ./dist

EXPOSE 3000

CMD ["pm2-runtime", "dist/index.js"]