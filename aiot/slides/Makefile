PDFPARAMS=-s -t beamer --pdf-engine=xelatex -V lang=en -V urlcolor=blue -V linkcolor=blue -V theme:metropolis -V aspectratio:169 -V fontsize:11pt
FONTS=-V mainfont='Vollkorn' -V sansfont='Lato' -V monofont='Inconsolata'
DATE=-V date="`date +'%d.%m.%Y'`"

all: slides.pdf

slides.pdf: slides.md
	pandoc $(PDFPARAMS) $(FONTS) $(DATE) $^ -o $@

clean:
	rm -f slides.pdf
