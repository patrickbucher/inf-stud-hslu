# Einführung

## Programmiersprache

- Programmiersprache: formal konstruierte Sprache, entworfen um Befehle an
  Maschinen (speziell Computer) zu übermitteln; zum Schreiben von Programmen,
  welche
    - das Verhalten von Maschinen kontrollieren, oder
    - Algorithmen (schrittweises Verfahren zur Lösung eines Problems)
      beschreiben.
- Programme einer Sprache sind definiert durch:
    - Syntax: formale Struktur, Muster
    - Semantik: Bedeutung, Interpretation
- Turing-Vollständigkeit: universelle Programmierbarkeit, notwendige Bedingung
  für eine Programmiersprache
    - (turing-vollständige) Programmiersprachen sind prinzipiell gleich
      mächtig!
    - Kann ein Problem in _einer_ turing-vollständigen Programmiersprache
      gelöst werden, kann es in _allen_ turing-vollständigen
      Programmiersprachen gelöst werden.
    - Programmierparadigmen und -sprachen haben ihre Stärken und Schwächen.

## Programmierparadigma

- Programmierparadigma: fundamentaler Programmierstil, eine bestimmte Art die
  Struktur und Elemente einer Software aufzubauen.
    - Paradigma: Denkweise, Lehrmeinung, Weltanschauung
- Programmierparadigmen:
    - imperativ: _Wie_ ist ein Problem zu lösen? Schrittweise Anleitung in
      Befehlen; Angabe von _einzelnen Berechnungsschritten_ (Lösungsweg)
        - strukturiert (Pascal): Sequenzen, Auswahl, Wiederholung (ohne `goto`)
        - prozedural (C): strukturiert mit Prozeduren/Funktionen/Unterprogrammen
            - Unterscheidung zwischen globalem und lokalem Gültigkeitsbereich
        - objektorientiert (Java): prozedural mit kommunizierenden Objekten
    - deklarativ: _Was_ ist gegeben? Definition der Berechnungslogik ohne
      Angabe des Kontrollflusses. Beschreibung des Ergebnisses, nicht des Weges
      dorthin
        - funktional (Scheme): Definition von Funktionen, Rückgabewert nur von
          Parametern und nicht vom Zustand abhängig (referenzielle Transparenz)
        - logisch (Prolog): Herleitung der Lösung aufgrund gegebener Fakten und
          Regeln
- Programmiersprachen kombinieren meist ein Hauptparadigma mit anderen
  Paradigmen. Bei der imperativen Programmierung beinhalten "höhere" Paradigmen
  die Eigenschaften "tieferer" Paradigmen:
    - Assembler: imperativ
    - Pascal: strukturiert (und imperativ)
    - C: prozedural (und sturkturiert (und imperativ))
    - Java: objektorientiert (und prozedural (und strukturiert (und
      imperativ))) -- mit funktionalen Elementen
