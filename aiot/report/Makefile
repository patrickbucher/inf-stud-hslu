.PHONY: clean

report.pdf: report.aux report.toc report.bbl architecture.png
	xelatex report.tex

report.toc:
	xelatex report.tex

report.bbl: report.aux report.bib
	bibtex report

report.aux: report.tex
	xelatex report.tex

architecture.png: architecture.dot
	dot -Tpng $^ -o $@

clean:
	rm -f *.aux *.log *.toc *.bbl *.blg *.out
