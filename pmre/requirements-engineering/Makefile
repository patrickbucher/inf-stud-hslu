PDFPARAMS=--toc -N -s -t latex --pdf-engine=xelatex -V documentclass=scrartcl -V papersize=a4 -V lang=de -V urlcolor=blue -V linkcolor=blue
EPUBPARAMS=-N -s -t epub -V lang=de
FONTS=-V mainfont='DejaVu Serif' -V sansfont='DejaVu Sans' -V monofont='DejaVu Sans Mono'
DATE=-V date="`date +'%d.%m.%Y'`"

all: basiswissen-requirements-engineering.pdf basiswissen-requirements-engineering.epub

basiswissen-requirements-engineering.pdf: *.md pics/*.png
	pandoc $(PDFPARAMS) $(FONTS) $(DATE) *.md -o basiswissen-requirements-engineering.pdf

basiswissen-requirements-engineering.epub: *.md pics/*.png
	pandoc $(EPUBPARAMS) $(DATE) *.md -o basiswissen-requirements-engineering.epub

clean:
	rm -f basiswissen-requirements-engineering.pdf basiswissen-requirements-engineering.epub
