PDFPARAMS=-s -t beamer --pdf-engine=xelatex -V lang=en -V urlcolor=blue -V linkcolor=blue -V theme:metropolis -V aspectratio:169 -V fontsize:11pt
FONTS=-V mainfont='Vollkorn' -V sansfont='Lato' -V monofont='Inconsolata'
DATE=-V date="`date +'%Y-%m-%d'`"

all: wellbean.pdf

wellbean.pdf: wellbean.md logo.png architecture-lr.png
	pandoc $(PDFPARAMS) $(FONTS) $(DATE) wellbean.md -o $@

clean:
	rm -f wellbean.pdf
