all: carbon-fibre.pdf

clean:
	rm -f *.bbl *.aux *.blg *.toc *.log *.lof

carbon-fibre.pdf: carbon-fibre.latex carbon-fibre.bbl carbon-fibre.toc
	pdflatex carbon-fibre.latex

carbon-fibre.bbl: carbon-fibre.bib carbon-fibre.aux
	bibtex carbon-fibre

carbon-fibre.toc: carbon-fibre.latex
	pdflatex carbon-fibre.latex

carbon-fibre.aux: carbon-fibre.latex
	pdflatex carbon-fibre.latex
