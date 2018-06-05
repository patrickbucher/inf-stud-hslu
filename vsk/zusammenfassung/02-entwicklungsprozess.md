# Entwicklungsprozess

## Projektplanung

## Source-Code-Management, Build und Dependency-Management

## Build-Server

## Integrations- und Systemtesting

## Entwurfsmuster

## Testing

## Continuous Integration

## Review

## Konfigurationsmanagement

## Deployment

![Deploymentdiagramm](pics/deploymentdiagramm.png)

## Code-Qualität

### Kommentare

- Schlechter Code soll nicht kommentiert sondern umgeschrieben werden.
    - Kommentare dienen oft als Ausrede für schlechten Code.
    - Selbsterklärender Code ist besser als jeder Kommentar.
    - Gute Namen ersparen viele Kommentare.
- Kommentare sind kein Qualitätsmerkmal sondern ein (manchmal) notwendiges
  Übel.
    - Code wird geändert, ohne dass die Kommentare nachgeführt werden.
    - Die Wahrheit liegt im Code, Kommentare können «lügen».
- Akzeptable Kommentare
    - Copyright (Lizenzbedingungen)
    - temporäre `TODO`/`FIXME`-Einträge
    - Kommentare zur Hervorhebung unauffälliger aber wichtiger Dinge
    - zusätzliche Erklärungen zur Absicht des Codes
    - Warnungen
- Schlechte Kommentare
    - Redundante Kommentare: `file.save(); // save the file` 
    - Irreführende Kommentare: `extension = ".xml"; // txt file`
    - erzwungene Kommentare: JavaDoc für Getter- und Setter-Methoden
    - Tagebuch- und Changelog-Kommentare: Versionskontrolle verwenden
    - Positionsbezeichner und Banner: `// 3) now save the changes`
    - Zuschreibungen und Nebenbemerkungen: `created by XYZ (xyz@foo.com)`
    - Auskommentierter Code: Kann dank Versionskontrolle gelöscht werden
    - HTML-formatierte Kommentare: Im Code schlecht lesbar
    - Zu viele und unnötige Informationen: `// written on my balcony at 5:00 am`

### Namensgebung

- Namen von Klassen sollten gut überlegt sein, da sie ihn lange behalten.
    - Noch wichtiger bei Interfaces!
- Kriterien für gute Namen:
    - zweckbeschreibend (schlecht: `ThingDoer`, gut: `TreeWalker`)
    - korrekt und ohne Fehlinformationen (schlecht: `ConnectionSingleton` wenn
      gar kein Singleton implementiert wird)
    - differenzierend
        - schlecht: `int a; float b; char c;`
        - gut: `int divisor; float dividend; char decimalSeparator;`
    - gut aussprechbar und suchbar sein
        - schlecht: `int n_pâtés_mangées; String достопримечательность; float l0lOl0lOl0lOfAc70r; double schnäderegägs;`
        - gut: `int pates_eaten; String attraction; float lolFactor; double babble;`
    - möglichst keine Codierungen enthalten
        - schlecht: `int range_0x00_0xff; int clr00ff00;`
        - gut: `int rangeFirstByte; int rgbGreen;`
- Heuristiken zur Namensgebung:
    1. Beschreibende Namen wählen
    2. Namen passend zur Abstraktionsebene wählen
    3. Standardnomenklatur verwenden
    4. Eindeutige Namen wählen
    5. Namenlänge abhängig von Geltungsbereich
    6. Codierungen vermeiden
    7. Nebeneffekte in Namen miteinbeziehen

### Weitere Massnahmen

- Reviews
    - Effizienteste Methode zur Verbesserung der Code-Qualität
    - Zu Beginn alleine oder in kleinen Teams, später mit mehreren Teilnehmern
    - In vertrauensvoller Atmosphäre, nicht als QS-Massnahme oder in Verbindung
      mit KPIs
- Weitergabe von Erfahrungen im informellen Austausch
    - Mit Snacks (5 Minuten) als Anreiz, vor/nach Vormittags-/Nachmittagspause
- Bemühungen für sauberen Code als Motivation und zur Erinnerung optisch
  präsent halten
- Werkzeuge: Checkstyle, PMD, Findbugs, SonarQube etc.
- Pfadfinderregel: Den Platz (Code) sauberer verlassen als man ihn angetroffen
  hat.
