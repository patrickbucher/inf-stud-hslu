const {InfluxDB} = require('@influxdata/influxdb-client');

const url = 'https://us-central1-1.gcp.cloud2.influxdata.com';
const token = '_FqHl41fRtXujwKqOg1eUQRKYcS2Pdofpzy6lD7HCIGQL3pGZVasqTANogqzZVmOKAW4xxkxb-j2ogGaSo_95g==';
const org = '15e4889842bc70a0';
const bucket = 'timecube';

class InfluxDataStore {

    constructor() {
        const client = new InfluxDB({url: 'https://us-central1-1.gcp.cloud2.influxdata.com', token: token});
        this.queryApi = client.getQueryApi(org);
    }

    getData(from, to, identifier, callback) {
        const data = new Array();
        const query = `from(bucket: "${bucket}")` +
            `|> range(start:${from}, stop:${to})` +
            `|> filter(fn:(r) => r.identifier == "${identifier}")`;
        this.queryApi.queryRows(query, {
            next(row, tableMeta) {
                const o = tableMeta.toObject(row);
                const measurement = {
                    'time': o._time,
                    'identifier': o.identifier,
                    'side': o._value,
                };
                data.push(measurement);
            },
            complete() {
                callback(data);
            },
            error(error) {
                console.error(error);
            }
        });
    }

}

module.exports = InfluxDataStore;
