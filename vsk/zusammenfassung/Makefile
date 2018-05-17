PARAMS=--pdf-engine=xelatex -V documentclass=scrartcl -V papersize=a4 -V lang=de
FONTS=-V mainfont='EB Garamond' -V sansfont='Open Sans' -V monofont='Fira Mono'
DATE=-V date="`date +'%d.%m.%Y'`"

vsk.pdf: 00-vsk.md 01-komponenten.md .pics
	pandoc -s -N --toc  $(PARAMS) $(FONTS) $(DATE) *.md -o vsk.pdf

.pics: komponentendiagramm.png
	plantuml komponentendiagramm.uml
	touch .pics

clean:
	rm -f .pics
