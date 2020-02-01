PDF_PARAMS=-s --pdf-engine=xelatex -V documentclass=scrartcl -V papersize=a4 -V lang=de -V fontsize=11pt -V geometry=left=2cm,right=2cm,top=2cm,bottom=4cm -V urlcolor=blue
FONT_PARAMS=-V mainfont="DejaVu Serif" -V sansfont="DejaVu Sans" -V monofont="DejaVu Sans Mono"
DATE=-V date="`date +'%Y-%m-%d'`"

.PHONY: all clean

all: Project-Idea.pdf Components.pdf

Project-Idea.pdf: Project-Idea.md
	pandoc $(PDF_PARAMS) $(FONT_PARAMS) $(DATE) $^ -o $@

Components.pdf: Components.md
	pandoc $(PDF_PARAMS) $(FONT_PARAMS) $(DATE) $^ -o $@

clean:
	rm -f Project-Idea.pdf Components.pdf
