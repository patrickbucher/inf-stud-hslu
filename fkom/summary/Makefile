PFLAGS = -S -s -V papersize=a4 -V documentclass=scrartcl -V classoption=11pt -V fontfamily=ebgaramond,helvet -V lang=de

all: vier-wesentliche-merkmale.pdf verstaendlichkeit.pdf

clean:
	rm *.pdf

vier-wesentliche-merkmale.pdf: vier-wesentliche-merkmale.md
	pandoc $(PFLAGS) vier-wesentliche-merkmale.md -o vier-wesentliche-merkmale.pdf

verstaendlichkeit.pdf: verstaendlichkeit.md verstaendigung.png
	pandoc $(PFLAGS) verstaendlichkeit.md -o verstaendlichkeit.pdf

verstaendigung.png: verstaendigung.dot
	dot -Tpng verstaendigung.dot -o verstaendigung.png
