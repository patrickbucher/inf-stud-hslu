SLIDE_PARAMS=-s -t beamer --pdf-engine=xelatex -V lang=en -V theme:metropolis -V aspectratio:169 -V fontsize:11pt
DOC_PARAMS=-s --pdf-engine=xelatex -V documentclass=scrartcl -V papersize=a4 -V lang=en -V fontsize=11pt
SLIDE_FONTS=-V mainfont='Lato' -V sansfont='Lato' -V monofont='Inconsolata'
DOC_FONTS=-V mainfont='Vollkorn' -V sansfont='Lato' -V monofont='Inconsolata'

all: SourceCodeFolderAnalysisSlides.pdf SourceCodeFolderAnalysis.pdf

SourceCodeFolderAnalysisSlides.pdf: Slides.md treemap.png
	pandoc $(SLIDE_PARAMS) $(SLIDE_FONTS) Slides.md -o $@

SourceCodeFolderAnalysis.pdf: Project.md treemap.png
	pandoc $(DOC_PARAMS) $(DOC_FONTS) Project.md -o $@

clean:
	rm -f SourceCodeFolderAnalysisSlides.pdf SourceCodeFolderAnalysis.pdf
