FROM node:14.2.0-alpine3.11
WORKDIR /usr/src/app
COPY package*.json ./
RUN npm ci --only=production
COPY src/* ./
EXPOSE 8000
CMD ["node", "server.js"]
