all: dokumentation.pdf

clean:
	rm -f *.bbl *.aux *.blg *.toc *.log *.lof *.lot *.idx *.ind *.out

redlichkeitserklaerung.pdf: redlichkeitserklaerung.tex
	xelatex redlichkeitserklaerung.tex

dokumentation.pdf: dokumentation.tex dokumentation.toc dokumentation.bbl
	xelatex dokumentation.tex && xelatex dokumentation.tex

dokumentation.toc: dokumentation.tex
	xelatex dokumentation.tex

dokumentation.aux: dokumentation.tex
	xelatex dokumentation.tex

dokumentation.bbl: dokumentation.aux dokumentation.bib
	bibtex dokumentation
