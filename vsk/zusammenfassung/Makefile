PARAMS=--pdf-engine=xelatex -V documentclass=scrartcl -V papersize=a4 -V lang=de -V urlcolor=blue -V linkcolor=blue
FONTS=-V mainfont='Droid Serif' -V sansfont='Droid Sans' -V monofont='Droid Sans Mono'
DATE=-V date="`date +'%d.%m.%Y'`"

FILES=00-vsk.md 01-komponenten.md 02-entwicklungsprozess.md 03-verteilte-systeme.md

vsk.pdf: $(FILES)
	pandoc -s -N $(PARAMS) $(FONTS) $(DATE) $(FILES) -o vsk.pdf
