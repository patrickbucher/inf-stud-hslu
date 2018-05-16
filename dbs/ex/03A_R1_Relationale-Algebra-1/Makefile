uebungen.pdf: uebungen.latex equivalence-relation.png
	pdflatex uebungen.latex && pdflatex uebungen.latex

clean:
	rm -f *.aux *.log

equivalence-relation.png: equivalence-relation.dot
	dot -Tpng equivalence-relation.dot -o equivalence-relation.png
