const redis = require('redis');
const {promisify} = require('util');

class RedisDataStore {

    constructor(address) {
        this.client = redis.createClient(address);
        this.client.on('error', () => {
            console.error(`unable to connect to redis at ${address}`);
        });
        this.client.on('ready', () => {
            console.log(`connected to redis at ${address}`);
            this.get = promisify(this.client.get).bind(this.client);
            this.set = promisify(this.client.set).bind(this.client);
        });
    }

    prefix(key) {
        return `timecube:${key}`;
    }

    sideConfigKey(identifier, sideNumber) {
        return this.prefix(`${identifier}:${sideNumber}`)
    }

    sideConfigKeys(identifier) {
        const keys = new Array();
        for (let i = 1; i <= 6; i++) {
            keys.push(this.sideConfigKey(identifier, i));
        }
        return keys;
    }

    getSideConfig(identifier) {
        const promises = new Array();
        for (const key of this.sideConfigKeys(identifier)) {
            promises.push(this.get(key).then(result => {
                return {'key': key, 'value': result};
            }));
        }
        return Promise.all(promises).then((results) => {
            const sides = {};
            for (const result of results)  {
                const side = result['key'].split(':').reverse()[0];
                sides[side] = result['value'];
            }
            return sides;
        });
    }
    
    setSideConfig(identifier, sides) {
        for (const [sideNumber, description] of Object.entries(sides)) {
            const key = this.sideConfigKey(identifier, sideNumber);
            this.set(key, description);
        }
    }
}

module.exports = RedisDataStore;
