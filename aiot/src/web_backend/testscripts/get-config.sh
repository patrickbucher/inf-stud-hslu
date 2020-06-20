#!/usr/bin/env bash

curl -X GET localhost:8000/config?identifier=3c583530-0152-4ed1-b15f-5bb0747e771e | jq
