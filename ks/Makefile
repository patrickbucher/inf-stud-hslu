PARAMS=--pdf-engine=xelatex -V documentclass=scrartcl -V classoption=smallheadings -V papersize=a4 -V lang=de -V urlcolor=blue
FONTS=-V mainfont="Linux Libertine" -V sansfont="Linux Biolinum"
DATE=-V date="`date +'%d.%m.%Y'`"

all: anfang.pdf deckblatt.pdf innerschweiz.pdf Innerschweiz_Patrick-Bucher.docx korrektur.pdf nachlese.pdf projekt.pdf sorry-story.pdf

nachlese.pdf: nachlese.tex
	xelatex nachlese.tex

%.pdf: %.md
	pandoc -s $(PARAMS) $(FONTS) $(DATE) $< -o $@ 

Innerschweiz_Patrick-Bucher.docx: innerschweiz.md
	pandoc -s -V lang=de innerschweiz.md -o Innerschweiz_Patrick-Bucher.docx

clean:
	rm -f *.log *.aux
