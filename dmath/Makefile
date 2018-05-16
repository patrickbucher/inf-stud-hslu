FILE=dmath

dmath: $(FILE).pdf

clean:
	rm -f *.log
	rm -f *.aux
	rm -f *.toc

$(FILE).pdf: $(FILE).latex
	pdflatex $(FILE).latex
	pdflatex $(FILE).latex
