PDFPARAMS=--toc -N -s -t latex --pdf-engine=xelatex -V documentclass=scrartcl -V papersize=a4 -V lang=de -V urlcolor=blue -V linkcolor=blue
EPUBPARAMS=--toc -N -s -t epub -V lang=de
FONTS=-V mainfont='DejaVu Serif' -V sansfont='DejaVu Sans' -V monofont='DejaVu Sans Mono'
DATE=-V date="`date +'%d.%m.%Y'`"

all: notizen.pdf notizen.epub

notizen.pdf: *.md graphs/*.png
	pandoc $(PDFPARAMS) $(FONTS) $(DATE) *.md -o notizen.pdf

notizen.epub: *.md graphs/*.png
	pandoc $(EPUBPARAMS) $(DATE) *.md -o notizen.epub

clean:
	rm -f notizen.pdf notizen.epub
