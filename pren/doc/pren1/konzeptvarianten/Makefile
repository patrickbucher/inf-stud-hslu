all: konzeptvarianten.pdf hightech.png optimiert.png blockschaltbild.png

konzeptvarianten.pdf: konzeptvarianten.tex hightech.png optimiert.png blockschaltbild.png
	xelatex konzeptvarianten.tex && xelatex konzeptvarianten.tex

hightech.png: hightech.dot
	dot hightech.dot -Tpng -o hightech.png

optimiert.png: optimiert.dot
	dot optimiert.dot -Tpng -o optimiert.png

blockschaltbild.png: blockschaltbild.dot
	dot blockschaltbild.dot -Tpng -o blockschaltbild.png

clean:
	rm -f *.aux *.log *.out *.toc *.lof
