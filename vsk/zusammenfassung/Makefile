PARAMS=--pdf-engine=xelatex -V documentclass=scrartcl -V papersize=a4 -V lang=de
FONTS=-V mainfont='Droid Serif' -V sansfont='Droid Sans' -V monofont='Droid Sans Mono'
DATE=-V date="`date +'%d.%m.%Y'`"

vsk.pdf: 00-vsk.md 01-komponenten.md 02-entwicklungsprozess.md
	pandoc -s -N --toc  $(PARAMS) $(FONTS) $(DATE) *.md -o vsk.pdf
