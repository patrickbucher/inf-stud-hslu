#!/usr/bin/env python3

from influxdb_client import InfluxDBClient

bucket = "timecube"
client = InfluxDBClient.from_config_file("config.ini")

query = f'from(bucket: "{bucket}") |> range(start: -1h)'
tables = client.query_api().query(query, org=client.org)
print(client.org)
for table in tables:
    print(table)
    for row in table.records:
        print(row.values)
        print("---")
