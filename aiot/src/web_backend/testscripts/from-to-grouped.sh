#!/usr/bin/env bash

curl -X POST localhost:8000/from-to-grouped -H "Content-Type: application/json" --data @from-to.json | jq
