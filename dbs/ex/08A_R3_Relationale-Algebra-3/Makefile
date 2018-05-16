all: uebungen.pdf

uebungen.pdf: uebungen.md 2a.png 2b.png 2c.png 3a.png 3b.png 3c.png 4a.png 4b.png 4c.png
	md2pdf uebungen.md

%.png: %.dot
	dot -Tpng $< -o $@

clean:
	rm -f *.png
