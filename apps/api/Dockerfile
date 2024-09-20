FROM node:lts AS builder

RUN npm install -g npm@latest

WORKDIR /app

COPY package*.json ./

RUN npm install

COPY . .

RUN npx prisma generate

RUN npm run build

FROM node:lts AS runner

RUN npm install -g npm@latest

WORKDIR /app

COPY --from=builder /app/package*.json ./

RUN npm install --only=production

COPY --from=builder /app/prisma ./prisma

RUN npx prisma generate

COPY --from=builder /app/dist ./dist

EXPOSE 3000

CMD ["node", "dist/index.js"]
