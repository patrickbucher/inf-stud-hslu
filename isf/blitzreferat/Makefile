all : paper.pdf slides.pdf

clean :
	rm -f *.bbl *.aux *.blg *.toc *.log *.nav *.snm *.out

paper.pdf: paper.tex paper.bbl paper.toc eme-clustered.png
	pdflatex paper.tex
	pdflatex paper.tex

paper.bbl: paper.bib paper.aux
	bibtex paper

paper.aux: paper.tex
	pdflatex paper.tex

slides.pdf: slides.tex eme-lr.png
	pdflatex slides.tex
	pdflatex slides.tex

eme-lr.png: eme-lr.dot
	dot -Tpng eme-lr.dot -o eme-lr.png

eme-td.png: eme-td.dot
	dot -Tpng eme-td.dot -o eme-td.png

eme-clustered.png: eme-clustered.dot
	dot -Tpng eme-clustered.dot -o eme-clustered.png
