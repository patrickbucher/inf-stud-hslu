#!/bin/sh

output="availability-capacity-management"
title="Availability- und Capacity-Management"
author="Lukas Arnold, Patrick Bucher"
date="`date +%d.%m.%Y`"

pandoc -s -S -N -t latex *.md -o "$output".pdf \
    -V title="$title" \
    -V author="$author" \
    -V date="$date" \
    -V papersize=a4 \
    -V documentclass=scrartcl \
    -V classoption=11pt \
    -V fontfamily='ebgaramond,helvet' \
    -V lang='de'

pandoc -s -S -N -t beamer slides/*.md -o "$output"-slides.pdf \
    -V title="$title" \
    -V author="$author" \
    -V date="$date" \
    -V theme="metropolis" \
    -V classoption="aspectratio=169" \
    -V lang='de'

# separate slides

pandoc -s -S -N -t beamer slides/3a*.md -o availability-management-slides.pdf \
    -V title="Availability Management" \
    -V author="Patrick Bucher" \
    -V date="$date" \
    -V theme="metropolis" \
    -V classoption="aspectratio=169" \
    -V lang='de'

pandoc -s -S -N -t beamer slides/3b*.md -o capacity-management-slides.pdf \
    -V title="Capacity Management" \
    -V author="Lukas Arnold" \
    -V date="$date" \
    -V theme="metropolis" \
    -V classoption="aspectratio=169" \
    -V lang='de'

pandoc -s -S -N -t html5 *.md -o "$output".html -c style.css \
    -V title="$title" \
    -V author="$author" \
    -V date="$date" \
    -V lang='de'
