PARAMS=-N --toc --pdf-engine=xelatex -V documentclass=scrartcl -V papersize=a4 -V lang=de -V urlcolor=blue -V linkcolor=blue
FONTS=-V mainfont="Droid Serif" -V sansfont="Droid Sans" -V monofont="Droid Sans Mono"
DATE=-V date="`date +'%d.%m.%Y'`"

all: fallstudie-bucher-christensen-kiser.pdf

fallstudie-bucher-christensen-kiser.pdf: fallstudie.md datenfluss.png
	pandoc -s $(PARAMS) $(FONTS) $(DATE) fallstudie.md -o $@

datenfluss.png: datenfluss.dot
	dot -Tpng $^ -o $@

clean:
	rm -f fallstudie-bucher-christensen-kiser.pdf
