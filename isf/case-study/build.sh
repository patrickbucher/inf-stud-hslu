name="fallstudie"
title="Fallstudie Heim-PC-Lösung"
author="Patrick Bucher"

rm -f $name.html
rm -f $name.pdf

pandoc -N -S -s --toc \
    --variable title="$title"\
    --variable author="$author" \
    --variable lang=de \
    *.md -o $name.html

pandoc -N -S -s --toc \
    --variable title="$title"\
    --variable author="$author" \
    --variable date=`date +%d.%m.%Y` \
    --variable papersize=a4 \
    --variable documentclass=scrartcl \
    --variable classoption=12pt \
    --variable fontfamily=ebgaramond,helvet \
    --variable lang=de \
    *.md -o $name.pdf
