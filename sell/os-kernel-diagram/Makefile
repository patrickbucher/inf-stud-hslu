os.png: os.eps
	convert -density 300 -bordercolor white -border 50x50 -flatten os.eps os.png

os.eps: os.ps
	ps2eps <os.ps >os.eps

os.ps: os.roff
	groff os.roff > os.ps

os.roff: os.pic
	pic os.pic > os.roff

clean:
	rm -f os.png os.eps os.ps os.roff
