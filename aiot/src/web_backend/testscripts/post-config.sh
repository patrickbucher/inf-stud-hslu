#!/usr/bin/env bash

curl -X POST localhost:8000/config -H "Content-Type: application/json" --data @config.json
