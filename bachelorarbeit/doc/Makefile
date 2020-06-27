.PHONY: all clean

all: document.pdf

document.pdf: document.tex document.bbl document.toc
	xelatex document.tex

document.bbl: document.aux document.bib
	bibtex document >bibtex.out || exit 1

document.aux: document.tex
	xelatex document.tex | tee xelatex.out

document-pdfa.pdf: document.pdf
	gs -dPDFA -dBATCH -dNOPAUSE -sColorConversionStrategy=UseDeviceIndependentColor -sDEVICE=pdfwrite -dPDFACompatibilityPolicy=2 -sOutputFile=$@ $^

clean:
	rm -f *.bbl *.toc *.aux *.out *.blg *.log *.lof *.lot *.lol *.lol *.out *.err *.for
