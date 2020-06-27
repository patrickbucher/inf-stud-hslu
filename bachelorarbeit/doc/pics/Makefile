.PHONY: all

PICTURES=architektur-variante-http.png architektur-variante-queue-1.png architektur-variante-queue-2.png datenfluss-variante-http-1.png datenfluss-variante-http-2.png datenfluss-variante-queue-1.png datenfluss-variante-queue-2.png projektplan.png phase1.png phase2.png phase3.png class-body-part.png class-joint-detection.png class-ratingen-score.png class-generic.png sequenzdiagramm-score-endpoint.png

all: $(PICTURES)

architektur-variante-http.png: architektur-variante-http.uml
	plantuml $^

architektur-variante-queue-1.png: architektur-variante-queue-1.uml
	plantuml $^

architektur-variante-queue-2.png: architektur-variante-queue-2.uml
	plantuml $^

datenfluss-variante-http-1.png: datenfluss-variante-http-1.uml
	plantuml $^

datenfluss-variante-http-2.png: datenfluss-variante-http-2.uml
	plantuml $^

datenfluss-variante-queue-1.png: datenfluss-variante-queue-1.uml
	plantuml $^

datenfluss-variante-queue-2.png: datenfluss-variante-queue-2.uml
	plantuml $^

projektplan.png: projektplan.dot
	dot -Tpng $^ -o $@

phase1.png: phase1.dot
	dot -Tpng $^ -o $@

phase2.png: phase2.dot
	dot -Tpng $^ -o $@

phase3.png: phase3.dot
	dot -Tpng $^ -o $@

class-body-part.png: class-body-part.uml
	plantuml $^

class-joint-detection.png: class-joint-detection.uml
	plantuml $^

class-ratingen-score.png: class-ratingen-score.uml
	plantuml $^

class-generic.png: class-generic.uml
	plantuml $^

sequenzdiagramm-score-endpoint.png: sequenzdiagramm-score-endpoint.uml
	plantuml $^

clean:
	rm -f $(PICTURES)
