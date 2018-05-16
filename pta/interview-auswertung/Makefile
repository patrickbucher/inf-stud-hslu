text.pdf: text.tex text.bbl
	latex text
	pdflatex text
text.bbl: text.tex text.aux bibliographie.bib
	bibtex text
text.aux: text.tex
	latex text
