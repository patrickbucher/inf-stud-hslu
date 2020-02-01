#!/bin/sh

gocloc --output-type=json --by-file ~/code | jq >slocstats.json || exit 1
go run buildtree.go <slocstats.json | jq >sourcetree.json
