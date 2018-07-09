all: sequenzdiagramm.png klassendiagramm.png rechennetzwerk.png arduino-statemachine.png

klassendiagramm.png: klassendiagramm.uml
	plantuml -Tpng klassendiagramm.uml

sequenzdiagramm.png: sequenzdiagramm.uml
	plantuml -Tpng sequenzdiagramm.uml

rechennetzwerk.png: rechennetzwerk.dot
	dot -Tpng rechennetzwerk.dot -o rechennetzwerk.png

arduino-statemachine.png: arduino-statemachine.dot
	dot -Tpng arduino-statemachine.dot -o arduino-statemachine.png

clean:
	rm -f sequenzdiagramm.svg sequenzdiagramm.png
