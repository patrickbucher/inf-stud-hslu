'use strict';

const express = require('express');
const redis = require('redis');
const cors = require('cors');
const bodyParser = require('body-parser');

const port = process.env.PORT || '8000';
const host = '0.0.0.0';

const RedisDataStore = require('./redis');
const redisStore = new RedisDataStore('redis://' + (process.env.REDIS || 'localhost:6379'));

const InfluxDataStore = require('./influxdb');
const influxStore = new InfluxDataStore();

const app = express();
app.use(bodyParser.json());
app.use(cors({
    origin: 'http://localhost:8080'
}));

app.options('/config', cors());

app.get('/config', (req, res) => {
    try {
        const identifier = req.query.identifier;
        if (identifier === '') {
            res.sendStatus(400);
            return
        }
        const sides = redisStore.getSideConfig(identifier);
        sides.then((payload) => res.send(payload));
    } catch(err) {
        console.error(err.message);
        res.sendStatus(500);
    }
});

app.post('/config', (req, res) => {
    try {
        const identifier = req.body.identifier;
        if (identifier === '') {
            res.sendStatus(400);
            return
        }
        const sides = req.body.sides;
        for (const [key, value] of Object.entries(sides)) {
            const side = parseInt(key);
            if (side < 1 || side > 6 || value.trim() === '') {
                res.sendStatus(400);
                return
            }
        }
        redisStore.setSideConfig(identifier, sides);
        console.log(`set side config for ${identifier}`);
        console.dir(sides);
        res.sendStatus(201);
    } catch(err) {
        console.error(err.message);
        res.sendStatus(500);
    }
});

app.post('/from-to', (req, res) => {
    try {
        const from = new Date(req.body.from).toISOString();
        const to = new Date(req.body.to).toISOString();
        const identifier = req.body.identifier;
        console.log(`from: ${from}, to: ${to}, identifier: ${identifier}`);
        if (from > to || !identifier) {
            res.sendStatus(400);
            return;
        }
        influxStore.getData(from, to, identifier, (data) => {
            res.send(data);
        });
    } catch(err) {
        console.error(err.message);
        res.sendStatus(500);
    }
});

app.post('/from-to-grouped', (req, res) => {
    try {
        const from = new Date(req.body.from).toISOString();
        const to = new Date(req.body.to).toISOString();
        const identifier = req.body.identifier;
        console.log(`from: ${from}, to: ${to}, identifier: ${identifier}`);
        if (from > to || !identifier) {
            res.sendStatus(400);
            return;
        }
        influxStore.getData(from, to, identifier, (data) => {
            const logbook = new Array();
            let lastSide = -1;
            let from = undefined;
            let to = undefined;
            for (let e of data) {
                if (e.side != lastSide) {
                    if (from != undefined) {
                        let diff = Math.floor((new Date(e.time) - new Date(from)) / 1000);
                        if (diff > 0) {
                            logbook.push({'from': from, 'to': e.time, 'side': lastSide, 'seconds': diff});
                        }
                    }
                    lastSide = e.side;
                    from = e.time;
                }
                to = e.time;
            }
            let diff = Math.floor((new Date(to) - new Date(from)) / 1000);
            logbook.push({'from': from, 'to': to, 'side': lastSide, 'seconds': diff});
            res.send(logbook);
        });
    } catch(err) {
        console.error(err.message);
        res.sendStatus(500);
    }
});

app.get('/canary', (req, res) => {
    res.send('time cube web backend up and running\n');
});

console.log(`listening on ${host}:${port}`)
app.listen(port, host);
