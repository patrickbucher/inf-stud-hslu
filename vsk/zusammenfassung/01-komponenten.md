# Komponenten

Herkunft: _componere_ (lat.) = zusammensetzen

![Komponentendiagramm (UML2)](komponentendiagramm.png){width=80%}

## Definition

Eine Software-Komponente

1. ist ein Software-Element
2. passt zu einem bestimmten Komponentenmodell
3. folgt einem bestimmten _Composition Standard_
4. kann ohne Änderungen mit anderen Komponenten verknüpft und ausgeführt werden

## Eigenschaften

Software-Komponenten

1. sind eigenständig ausführbare Softwareeinheiten
2. sind über ihre Schnittstellen austauschbar definiert
3. lassen sich unabhängig voneinander entwickeln
4. können kunden- und anwendungsspezifisch oder anwendungsneutral und wiederverwendbar sein
    - COTS (Commercial off-the-shelf): Software «von der Stange»
5. können installiert und deployed werden
5. können hierarchisch verschachtelt sein


## Komponentenmodelle

Komponentenmodelle

- sind konkrete Ausprägungen des Paradigmas der komponentenbasierten Entwicklung
- definieren die genaue Form und Eigenschaften einer Komponente
- definieren einen _Interaction Standard_ 
    - wie können die Komponenten miteinander über Schnittstellen kommunizieren (Schnittstellenstandard)
    - wie werden die Abhängigkeiten der Komponenten voneinander festgelegt
        - von der Komponente verlange Abhängigkeiten: _Required Interfaces_
        - von der Komponente angebotene Abhängigkeiten: _Provided Interfaces_
- definieren einen _Composition Standard_ 
    - wie werden die Komponenten zu grösseren Einheiten zusammengefügt
    - wie werden die Komponenten ausgeliefert (Deployment)
