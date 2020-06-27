PDFPARAMS=-s -t beamer --pdf-engine=xelatex -V lang=de -V urlcolor=blue -V linkcolor=blue -V theme:metropolis -V aspectratio:169 -V fontsize:11pt
FONTS=-V mainfont='Vollkorn' -V sansfont='Lato' -V monofont='Inconsolata'
DATE=-V date="`date +'%d.%m.%Y'`"

all: zwischenpraesentation.pdf abschlusspraesentation.pdf

zwischenpraesentation.pdf: zwischenpraesentation.md
	pandoc $(PDFPARAMS) $(FONTS) $(DATE) $^ -o $@

abschlusspraesentation.pdf: abschlusspraesentation.md
	pandoc $(PDFPARAMS) $(FONTS) $(DATE) $^ -o $@

clean:
	rm -f zwischenpraesentation.pdf abschlusspraesentation.pdf
