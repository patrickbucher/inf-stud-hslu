# Theoriefragen

## Datenbanktheorie

1. Was ist der Unterschied zwischen eier Datenbank und einem Informationssystem?
    - Eine Datenbank kann ein Teil eines Informationssystems sein.
    - Ein Informationssystem verfügt zusätzlich über eine Software zur Interaktion mit dem Benutzer.
2. Was ist der Unterschied zwischen einer Datenbank und einem Dateisystem?
    - Eine Datenbank verfügt zusätzlich über ein Verwaltungssystem.
3. Was ist der Unterschied zwischen einer SQL- und einer NoSQL-Datenbank?
    - NoSQL-Datenbanken sind nicht relational.
    - NoSQL-Datenbanken verwenden nicht SQL als Abfragesprachen.
4. Was ist der Unterschied zwischen Datenbanken und Datenmanagement?
    - Im Datenmanagement geht es um den Zugriff und die Verwaltung von Datenbeständen.
    - Datenbanken sind ein Werkzeug des Datenmanagement und dienen zur strukturierten Datenverwaltung.
5. Was ist eine mögliche Definition des Begriffs Datenbanken?
    - Eine Datenbank ist ein Softwaresystem zur Speicherung, Verwaltung und Manipulation strukturierter Daten, die den Zugriff auf den Datenbestand regelt und dazu eine Abfragesprache bietet.
6. Warum ist eine XML-Datei keine Datenbank?
    - Eine XML-Datei ist höchstens ein _Datenbestand_.
    - Sie bietet keine Verwaltungstools und keine Abfragesprache.
7. Welche Vor- und Nachteile hat eine Datenbank gegenüber einem Dateisystem?
    + Eine Datenbank ermöglicht einfaches Auffinden von Daten mittels Abfragesprache.
    + Die Daten einer Datenbank können in Beziehung zueinander gesetzt werden.
    + Eine Datenbank ermöglicht konkurrierenden Zugriff auf die Daten, ohne dass dabei Anomalien auftreten.
    + Eine Datenbank bietet Möglichkeiten zur Zugriffsverwaltung.
    - Eine Datenbank erfordert eine Verwaltungssoftware/Engine.
    - Die Abfragesprache einer Datenbank muss zuerst erlernt werden, sie ist weniger intuitiv als der Zugriff auf ein Dateisystem.
    - Eine Datenbank ist schwieriger zu handhaben als ein Dateisystem.

## Entity-Relationship-Modelle

1. Welche Assoziationstypen gibt es?
    - 1 (genau 1)
    - c (0 oder 1)
    - m (1 oder mehrere)
    - mc (0, 1 oder mehrere)
2. Was ist der Unterschied zwischen Generalisierung und Aggregation?
    - Die Aggregation beschreibt eine "ist Teil von"-Beziehung.
    - Die Generalisierung beschreibt eine "ist ein"-Beziehung (Verallgemeinerung).
3. Was ist der Unterschied zwischen Generalisierung und Spezialisierung?
    - Die Lesart!
    - Generalisierung geht vom Speziellen zum Allgemeinen.
    - Spezialisierung geht vom Allgemeinen zum Speziellen.
4. Wann ist eine Spezialisierung vollständig?
    - Wenn zu jedem Eintrag eines Obertyps auch mindestens ein Eintrag eines Untertyps existieren muss.
5. Wann ist eine Spezialisierung disjunkt?
    - Wenn zu jedem Eintrag eines Obertyps nur genau ein Eintrag existiert aber auf keinen Fall mehrere.

## Relationale Schemas

1. Wie wird der Begriff der Redundanz definiert?
    - Redundanz liegt vor, wenn Sachverhalte mehrfach abgespeichert werden.
2. Wozu werden die Normalformen eingesetzt, und aus welchem Grund?
    - Mithilfe der Normalformen lässt sich das Auftreten von Redundanzen verhindern.
    - Dadurch werden Anomalien vermieden.
3. Was ist eine Löschanomalie? Erklären Sie dies anhand eines konkreten Beispiels.
    - Bei einer Löschanomalie gehen bei der Löschung eines Eintrags zu viele Informationen verloren.
    - Beispiel: Enthält eine Mitarbeiter-Tabelle nur noch einen einzigen Mitarbeiter mit dem Wert "Buchhaltung" in der Spalte "Abteilung", und wird dieser Eintrag gelöscht, verschwindet sogleich die Abteilung "Buchhaltung" aus dem System -- und nicht nur der Buchhalter!
4. Was ist eine funktionale Abhängigkeit?
    - B ist von A funktional abhängig, wenn jeder Wert von A einen Wert von B bestimmt.
    - Beispiel: Die Postleitzahl (A) bestimmt den Ort (B).
5. Was ist eine volle funktionale Abhängigkeit?
    - B ist von A vollständig funktional abhängig, wenn A ein zusammengesetztes Schlüsselattribut ist, und B nur durch den gesamten Schlüssel A bestimmbar ist, d.h. kein Teilattribut von A weggelassen werden darf.
    - Beispiel: Die Spalte "aufgewendete Arbeitsstunden" ist vom zusammengesetzten Schlüssel "ProjektNr" und "MitarbeiterNr" voll funktional abhängig.
6. Was ist eine transitive Abhängigkeit?
    - C ist von A transitiv abhängig, wenn C von B und B von C abhängig ist.
    - Beispiel: Die Rechnungssumme ist (u.a.) vom Artikelpreis abhängig. Der Artikelpreis ist von der Artikelnummer abhängig.
7. Welchen Bezug haben diese Abhängigkeiten zu den Normalformel 1-3?
    - Bei der 1. Normalform treten funktionale Abhängigkeiten auf.
    - Bei der 2. Normalform treten nur noch voll funktionale Abhängigkeiten auf.
    - Bei der 3. Normalform treten keine transitiven Abhängigkeiten mehr auf.
8. Was ist der Unterschied zwischen einer Tabelle und einer Relation?
    - Eine Relation ist ein technologieneutrales, abstraktes Konzept.
    - Eine Tabelle ist die Umsetzung einer Relation in einer relationalen Datenbank.
9. Welches sind die zwei wichtigen Schlüsseleigenschaften?
    - Eindeutigkeit
    - Minimalität
10. Warum braucht es für einfach-komplexe und einfach-einfache Beziehungsmengen keine Beziehungstabelle?
    - Diese Beziehungen könnten mit einem Fremdschlüssel in einer der beiden Tabelle umgesetzt werden.
11. Wozu braucht es die siebte Regel [Regel R7: Aggregation, Seite 55/56]?
    - Aggregationen müssen als Beziehungstabelle umgesetzt werden.
    - Ansonsten liessen sich komplex-komplexe Beziehungen nicht umsetzen.

## SQL-Grundlagen

- Welche Benutzergruppen gibt es und wie interagieren sie mit der Datenbank?
    - Datenbankarchitekten legen die Struktur der Tabellen fest.
    - Datenbankspezialisten definieren, installieren und überwachen die
      Datenbank über die Systemtabellen.
    - Anwendungsprogrammierer verwenden eine Datenbanksprache, um die
      Datenbestände über eine Programmierschnittstelle auszuwerten und zu
      manipulieren.
    - Datenanalysten führen Abfragen auf Wunsch von Anwendern aus
      Fachabteilungen aus.
- Was ist der Unterschied zwischen mengenorientierten und relationalen
  Operatoren?
    - Mengenorientierte Operatoren verbinden zwei Mengen miteinander.
    - Relationale Operatoren erlauben es, eine Menge auf eine gewünschte
      Teilmenge zu reduzieren.
- Wie ist der Zusammenhang von Kreuzprodukt und Division?
    - Division: `R'=R÷S`
    - Kreuzprodukt: `R'×S⊆R`
    - Die Division ist die Umkehroperation des Kreuzprodukts.
- Was ist der Zusammenhang von mengenorientierten Abfragesprachen und der
  Relationenalgebra?
    - Die fünf Primitiven der Relationenalgebra (Vereinigung, Differenz,
      kartesisches Produkt, Projektion und Selektion) bieten alles, um eine
      mengenorientierte Abfragesprache umzusetzen.
- Wie wird die Selektion in SQL umgesetzt?
    - mittels `WHERE`-Klausel
- Wie wird die Projektion in SQL umgesetzt?
    - mittels `SELECT`-Klausel
- Wie wird der Join in SQL umgesetzt?
    - Mit der `JOIN`-Klausel in seinen verschiedenen Varianten (left, right,
      inner, natural).
    - Mit der `FROM`-Klausel (kartesisches Produkt) unter Einschränkung der
      Ergebnismenge, Beispiel:
        - `FROM mitarbeiter, projekt WHERE mitarbeiter.id = projekt.leiterId`
- Wie zeigt sich die Eigenschaft von SQL, dass sie _deskriptiv_ ist?
    - Mit SQL beschreibt man das gewünschte Ergebnis einer Operation, nicht die
      einzelnen Schritte, wie dieses Ergebnis zu Stande kommt.
- Was bedeutet die Aussage, dass SQL _relational vollständig_ ist?
    - Mit SQL lassen sich sämtliche Operationen ausführen, die in der
      relationalen Algebra vorgesehen sind. SQL ist also eine Umsetzung der
      relationalen Algebra.
