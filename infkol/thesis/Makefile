all: OAuth2_Bucher-Christensen.pdf

OAuth2_Bucher-Christensen.pdf: paper.pdf
	cp paper.pdf OAuth2_Bucher-Christensen.pdf

paper.pdf: paper.tex paper.bbl paper.toc auth-grant.png
	xelatex paper.tex && xelatex paper.tex

paper.toc: paper.tex
	xelatex paper.tex

paper.aux: paper.tex
	xelatex paper.tex

paper.bbl: paper.aux paper.bib
	bibtex paper

auth-grant.png: auth-grant.dot
	dot -Tpng auth-grant.dot -o auth-grant.png

clean:
	rm -f *.bbl *.toc *.aux *.out *.blg *.log *.lof *.lot
