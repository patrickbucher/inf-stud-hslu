#!/bin/sh

# Usage: md2pdf [input] [title]

output="sla-budget_arnold-bucher.pdf"
title="$2"

pandoc -S -s -N \
    --variable title="Testat-Übung 08" \
    --variable subtitle="SLA \& Budget" \
    --variable author="Lukas Arnold, Patrick Bucher" \
    --variable date=`date +%d.%m.%Y` \
    --variable papersize=a4 \
    --variable documentclass=scrartcl \
    --variable classoption=13pt \
    --variable fontfamily='times' \
    --variable lang=de \
    *.md -o $output
