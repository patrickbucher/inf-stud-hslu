rm -f '3.4-Produktautomat.pdf'

title='Produktautomat'
author='Patrick Bucher, Melvin Werthmüller'

pandoc -N -S -s \
    --variable title="$title" \
    --variable author="$author" \
    --variable papersize=a4 \
    --variable documentclass=scrartcl \
    --variable classoption=smallheadings,11pt \
    --variable fontfamily=times \
    --variable lang=de\
    *.md -o '3.4-Produktautomat.pdf'
