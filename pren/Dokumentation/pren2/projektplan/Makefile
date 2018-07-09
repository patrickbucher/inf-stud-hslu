all: Projektplan_Gruppe-7.pdf

projektplan.pdf: projektplan.tex 0-titelseite.tex
	xelatex projektplan.tex && xelatex projektplan.tex

Projektplan_Gruppe-7.pdf: projektplan.pdf detail-sheet.pdf
	gs -dBATCH -dNOPAUSE -q -sDEVICE=pdfwrite -sOutputFile=Projektplan_Gruppe-7.pdf projektplan.pdf detail-sheet.pdf

clean:
	rm -f *.aux *.log *.out *.toc
