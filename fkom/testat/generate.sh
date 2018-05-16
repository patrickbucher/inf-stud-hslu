#!/bin/bash

title="Linux und Textdateien"
subtitle="Effizient arbeiten mit einfachen Mitteln"

# picture
dot -Tsvg graphic.dot > graphic.svg
convert -density 600 graphic.svg graphic.png

# html output
pandoc -s -S webtext.md \
    -H style.header \
    -V author="Patrick Bucher" \
    -V date=`date +%d.%m.%Y` \
    -V title="$title" \
    -V subtitle="$subtitle" \
    -V lang=de \
    -o webtext.html

# pdf output
pandoc -S -s \
    --variable title="$title" \
    --variable subtitle="$subtitle" \
    --variable author="Patrick Bucher" \
    --variable date=`date +%d.%m.%Y` \
    --variable papersize=a4 \
    --variable documentclass=scrartcl \
    --variable classoption=11pt \
    --variable fontfamily='times' \
    --variable lang=de \
    --variable urlcolor=blue \
    webtext.md -o webtext.pdf
