PFLAGS = -S -s -V papersize=a4 -V documentclass=scrartcl -V classoption=11pt,smallheadings -V fontfamily='ebgaramond,helvet' -V lang=de

all: repetitionsfragen_information-security-management.pdf  repetitionsfragen_frameworks.pdf krypto-3uhr-fragen.pdf krypto-3uhr-fragen.html

repetitionsfragen_information-security-management.pdf: repetitionsfragen_information-security-management.md
	pandoc $(PFLAGS) repetitionsfragen_information-security-management.md -o repetitionsfragen_information-security-management.pdf

repetitionsfragen_frameworks.pdf: repetitionsfragen_frameworks.md
	pandoc $(PFLAGS) repetitionsfragen_frameworks.md -o repetitionsfragen_frameworks.pdf

krypto-3uhr-fragen.pdf: krypto-3uhr-fragen.md
	pandoc $(PFLAGS) krypto-3uhr-fragen.md -o krypto-3uhr-fragen.pdf

krypto-3uhr-fragen.html: krypto-3uhr-fragen.md
	pandoc -S -s -t html5 krypto-3uhr-fragen.md -o krypto-3uhr-fragen.html
