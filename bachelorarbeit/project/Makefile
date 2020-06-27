PDF_PARAMS=-s --pdf-engine=xelatex -V documentclass=scrartcl -V papersize=a4 -V lang=de -V fontsize=11pt
PDF_PARAMS_LANDSCAPE=-s --pdf-engine=xelatex -V documentclass=scrartcl -V papersize=a4 -V lang=de -V fontsize=11pt -V geometry=landscape
FONT_PARAMS=-V mainfont="Vollkorn" -V sansfont="Lato" -V monofont="Inconsolata"
DATE=-V date="`date +'%d.%m.%Y'`"

.PHONY: all

all: arbeitsjournal.pdf arbeitsjournal-pdfa.pdf

arbeitsjournal.pdf: arbeitsjournal.md
	pandoc $(PDF_PARAMS_LANDSCAPE) $(FONT_PARAMS) $(DATE) $^ -o $@

arbeitsjournal-pdfa.pdf: arbeitsjournal.pdf
	gs -dPDFA -dBATCH -dNOPAUSE -sColorConversionStrategy=UseDeviceIndependentColor -sDEVICE=pdfwrite -dPDFACompatibilityPolicy=3 -sOutputFile=$@ $^
