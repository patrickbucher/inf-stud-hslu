# Entwicklungsprozess

## Projektplanung

## Versionskontrolle

- SCM: Source Code Management
- Aufgaben/Vorteile von SCM (Source Code Management)
    - hält zeitliche Entwicklung von Artefakten fest
    - erlaubt Rückgriff auf frühere Revisionen (Änderungsstände)
    - ermöglicht Zusammenarbeit an gemeinsamen Quellen im Team
    - automatisiertes Zusammenfügen von Änderungen (Merging) -- soweit möglich
      (Konflikte)
    - zentrale oder verteilte Datenhaltung -- oder beides
    - können fehlende Koordinaten _nicht_ ersetzen
    - machen Änderungen an Artefakten nachvollziehbar
        - als _Changesets_ innerhalb einer Transaktion gespeichert
        - $1..n$ Dateiartefakte werden vom konsistentem Zustand $z_1$ in den
          konsistenten Zustand $z_2$ überführt
    - sind _keine_ Backupsysteme
- Arbeit mit einem SCM
    - Grundlegende Operationen:
        - `checkout`: lokale Arbeitskopie von Repository erstellen
        - `update`: Änderungen von Repository in der lokalen Arbeitskopie
          aktualisieren
        - `log`: Revisionen von Artefakten einsehen
        - `diff`: Vergleich verschiedener Revisionen zweier Artefakte
        - `commit`: Änderungen in das Repository schreiben
    - Operationen verteilter SCM:
        - `clone`: lokale Kopie eines entfernten Repositories erzeugen
        - `fetch`: Änderungen eines entfernten Repositories herunterladen
        - `pull`: Änderungen eines entfernten Repositories lokal
          nachtragen/einpflegen
        - `push`: Lokale Änderungen auf entferntes Repository schreiben
    - Tagging: Markieren eines bestimmten Revisionsstands mit Namen oder
      Versionsnummer
        - CVS: Markierung auf Dateiebene
        - Subversion (SVN): Kopie in ein Verzeichnis
        - `git`, Mercurial (`hg`): Identifikation der Revision über das ganze
          Dateisystem des Repositories
    - Branching: Voneinander unabhängig bearbeitbare Entwicklungszweige
        - für Bugfixing, Prototypen (Tests, Experimente), neue Features
        - Branch wird entweder verworfen (abgebrochene Experimente) …
        - … oder in den Hauptzweig eingepflegt (Merge)
    - Inhalte: Was gehört ins Repository?
        - Ja: Quellcode (`*.java`), Konfigurationsdateien (`*.xml`),
          Dokumentation (`*.md`, `*.txt`)
        - Nein: Kompilate (`*.class`), generierte Dokumente (HTML-Reports)
        - Filterregeln: `.gitignore` (`git`) bestimmt, was ins Repository kommt
- Unterschiede zwischen verschiedenen SCM
    - zentral oder verteilt
    - optimistische oder pessimistische Lockverfahren
    - Versionierung anhand Datei, Verzeichnisstruktur oder Changeset
    - mit oder ohne Transaktionsunterstützung
    - weitere Features: Zugriffsprotokolle, Sicherheitsmassnahmen,
      Webserver-Integration
- Beispiele bekannter SCM:
    - CVS: zentral, robust, stabil, alt, Verbreitung rückläufig
    - Subversion: zentral, transaktionsorientiert, Versionierung auf
      Verzeichnisebene, flexibler und anspruchsvoller als CVS, als
      CVS-Nachfolger angetreten (bereits wieder rückläufig)
    - `git`: dezentral, weit verbreitet, «billiges» Branching (schnell und
      einfach), skalierbar (einfach und schnell bei kleinen Repositories,
      funktioniert auch für gigantische  Repositories -- Linux-Kernel),
      aufgrund dezentraler Struktur nicht ganz einfach zu verstehen
- Code-Hosting-Plattformen: GitLab, GitHub
    - Verwaltung von Teams (Berechtigungen), Projekten (Issue-Tracking)
    - Werkzeuge zur Bearbeitung von Merge-Requests (GitLab), Pull-Requests
      (GitHub)
    - Webseiten, Wikis, Durchsuchen des Source-Trees
    - Community-Gedanke (GitHub), Social Network für Nerds
- Praktische Empfehlungen für die Arbeit mit SCM
    - Vor Arbeitsbeginn das lokale Repository auf den neuesten Stand bringen
      (`pull` bzw. `checkout`)
    - Aussagekräftige `commit`-Messages verwenden, am besten mit Verweis auf
      Issue-/Tasknummer
    - Lieber öfters kleinere Änderungen als selten grössere Änderungen
      schreiben (weniger und kleinere Merge-Konflikte)

## Build 

## Dependency-Management

## Build-Server

## Integrations- und Systemtesting

## Entwurfsmuster

## Testing

## Continuous Integration

## Review

## Konfigurationsmanagement

## Deployment

- Beim Deployment geht es um folgende Aspekte:
    1. Verteilung von Software und Dokumentation per Datenträger oder Web
    2. Installation: Software auf Zielsystem kopieren
    3. Konfiguration: Einstellung der Software auf jeweilige Anforderungen
    4. Organisation: Informatin, Schulung, Support, Planung, Produktion
- Wann findet Deployment statt?
    - Am Ende eines (erfolgreichen) Projekts.
    - Bei iterativen Entwicklungsmodellen öfters (Continuous Delivery erfordert
      Continuous Deployment)
    - Fortlaufendes Deployment einzelner Iterationsergebnisse (Build, Sprint,
      Meilenstein) auf Entwicklungs- und Testsysteme (Staging)
- Die Deployment-Dokumentation umfasst:
    - Technische Aspekte
        - [Deploymentdiagramme](#deploymentdiagramm): Zuordnung der Komponenten
          zu Systemen/Hardware (Zeigt Nodes, Komponenten pro Node und deren
          Verbindungen miteinander)
        - Installations- und Deinstallationsprogramme bzw. -skripte
        - Konfigurationen (Standardkonfiguration, Beispiele, kunden- und
          umgebungsspezifisch)
        - Installationsmedium/Bezugsquelle (physischer Datenträger, URL, Login)
        - Repositories zur Ablage der Binaries
    - Organisatorische Aspekte
        - Konfigurationsmanagement: Aus welchen Komponenten wird der Release
          gebildet?
        - Installations- und Bedienungsanleitung
        - Erwartungsmanagement: Welche Funktionalität ist vorhanden?
        - Bereitstellung von Support (intern/extern, 1st Level/2nd Level etc.)
- Installation und Deinstallation
    - Möglichst automatisierbar und dadurch reproduzierbar
    - Vollständige und saubere Deinstallation muss möglich sein
    - Vollautomatische Softwareverteilung (setzt bestimmte Merkmale voraus)
    - Unterschiedliche Bedürfnisse nach Benutzergruppe:
        - Endbenutzer: Interaktive Installation mit Setup-Wizard
        - Administrator: Möglichst automatisierbare Installation
        - Entwickler/Tester: Auf eigene Bedürfnisse zugeschnittene Installation
- Konfiguration von Anwendungen
    - Zielkonflikt: Software soll out-of-the-box laufen, aber möglichst auf die
      eigenen Bedürfnisse anpassbar sein (am liebsten out-of-the-box auf eigene
      Bedürfnisse konfiguriert)
    - Konfigurationsmanagement: Wer hat welche Version, welche Lizenzen, welche
      Umgebung? Welche Kombinationen sind lauffähig? Welche Update-Schritte
      funktionieren? Welche Szenarien wurden getestet?
- Deployment-Manuals
    - Installationsanleitung (möglichst klein mit automatisierter Installation)
        - Gehen auf verschiedene Konfigurationsvarianten und Voraussetzungen
          (Hardware/Software) ein
        - Behandelt einzuhaltende Abfolgen
    - Bedienungsanleitung (Release Notes)
        - neue Funktionen
        - neue Bedingungen zum Betreiben der Software
        - neue Datenformate und Protokolle
        - Manuell aus verschiedenen Quellen zusammengestellt: Commit-Messages,
          Bugfix-Meldungen, Feature-Beschriebe (User Stories) etc.
- Deployment-Support: Muss in jedem Fall bereitgestellt werden!
- Release und Versionierung
    - Eindeutige Versionsbezeichnung (technische Version, Tag im
      Versionskontrollsystem, evtl. zusätzliche «Marketing-Versionierung»)
    - Semantic Versioning: x.y.z [Semver.org](https://semver.org)
        - x: Major (bei inkompatiblen Änderungen hochgezählt)
        - y: Minor (beim Hinzufügen rückwärtskompatibler Funktionalität
          hochgezählt)
        - z: Patch (bei Fehlerkorrekturen hochgezählt)
    - Ein Blick auf die neue Versionsnummer soll Klarheit geben, was sich
      geändert hat.
    - Zeitbasierte Modelle: Ubuntu, Gnome: alle 6 Monate, Arch: monatlicher
      Snapshot
- Technisches Deployment: Beispiel Java
    - Verteilung einzelner `.class`-Dateien: inakzeptabel, fehleranfällig
    - Verteilung von `.jar`-Archiven (Java Archive): gezippte `.class`-Dateien
      mit zusätzlichen Ressourcen und Meta-Daten (`META-INF/MANIFEST.MF`, u.a.
      für `CLASSPATH`-Angaben)
        - `.war`-Dateien (Web Archive) für Webcontainer (`META-INF/web.xml`)
        - `.ear`-Dateien (Enterprise Archive) für Applikationsserver
          (`META-INF/application.xml`)
    - Einzelne (kombiniert zu Shadow-Archiven) oder mehrere `.jar`-Dateien
      (erfordert `CLASSPATH`-Angabe)
    - Zusätzliche `.jar`-Dateien für Quellcode und Dokumentation möglich:
        - `foobar.jar`: Ausführbar (`.class`-Dateien)
        - `foobar-doc.jar`: Dokumentation (JavaDoc)
        - `foobar-src.jar`: Quellcode (`.java`-Dateien), v.a. bei Open Source

![Deploymentdiagramm](pics/deploymentdiagramm.png){#deploymentdiagramm}

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
    - Zu viele und unnötige Informationen: `// written on my balcony at 5:00
      am`

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
        - schlecht: `int n_pâtés_mangées; String достопримечательность; float
          l0lOl0lOl0lOfAc70r; double schnäderegägs;`
        - gut: `int pates_eaten; String attraction; float lolFactor; double
          babble;`
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

### Funktionen

- Funktionen sollen klein sein.
    - Faustregel: Eine Bildschirmhöhe nicht überschreiten (mit vernünftiger
      Schriftgrösse)
    - Vorteil: Kleine Funktionen sind schneller verständlich.
    - Konsequenz: Es gibt mehr Funktionen und evtl. auch mehr Klassen, da
      Klassen nicht zu viele Methoden haben sollen. Dies wirkt sich positiv auf
      die Testbarkeit aus.
- Jede Funktion hat nur eine Aufgabe, welche sie gut erledigt
  (Unix-Philosophie).
    - Finden der Aufgabe: mit einen «to»-Satz: «to sort an array», «to
      establish a connection»
    - Abschnitte in Funktionen deuten auf die Verletzung dieses Prinzips hin.
- Jede Funktion arbeitet auf nur einer Abstraktionsebene (_Single Level of
  Abstraction_).
    - Eine Funktion, die Zeilen zählt, sollte sich nicht mit Encodings
      befassen.
    - Eine Funktion, die Zahlen rundet, sollte sich nicht mit Little- und
      Big-Endian kümmern.
    - Verletzung dieses Prinzips: Codeerosion/Zerfall (schlechter Code als
      Magnet für mehr schlechten Code)
- Die `switch`-Anweisung sollte vermieden werden.
    - `switch` deutet auf mehrere Aufgaben hin (verletzt
      Single-Responsibility-Prinzip)
    - `switch` muss bei jeder Erweiterung angepasst werden (verletzt
      Open-Closed-Prinzip)
    - `switch`-Konstrukte treten im Code oft mehrmals auf (verletzt
      Dont-Repeat-Yourself-Prinzip)
    - Lösung: Polymorphe Konstrukte (z.B. Strategy-Pattern, Funktionsreferenz)
- Die Anzahl der Funktionsargumente sollte klein gehalten werden.
    - Vertauschungsgefahr bereits ab zwei Argumenten
    - Lesbarkeit verschlechtert sich mit Anzahl Funktionsargumente
      (Zeilenumbrüche oder horizontales Scrolling)
    - Je mehr Funktionsargumente übergeben werden müssen, desto eher wird eines
      falsch gesetzt.
        - Ausprobieren von Kombinationen ist die Folge.
        - Die Dokumentation muss konsultiert werden.
    - Die eindimensionale Metrik aus _Clean Code_ («je weniger
      Funktionsargumente, desto besser») ist mit Vorsicht zu geniessen!
        - `summe = addiere(summand1, summand2);` (strukturierte bzw.
          funktionale Lösung)
        - `summe = summand1.addiere(summand2);` (objektorientierte Lösung)
        - `summierer.a = summand1; summierer.b = summand2; summe =
          summierer.summiere()`
        - Bei der dritten «Lösung» gibt es _keine_ Funktionsparameter, sie ist
          aber die denkbar schlechteste, da sie einen bestimmten Kontext
          voraussetzt.
    - Es gibt Funktionen, die _aus fachlicher Sicht_ viele Parameter benötigen:
        - `Point p1 = new Point(13, 27);` (x- und y-Koordinate)
        - `Color salmon = new RGB(255, 153, 153);` (RGB-Farbe)
        - `Color translucentSalmon = new RGBA(255, 153, 153, 0.5);` (mit
          Alphakanal)
        - `Color salmon = new
          RGBBuilder().red(255).green(153).blue(153).build()` («schöner» aber
          schwerer lesbar, gerade wenn eine ungebräuchliche Reihenfolge wie
          «BRG» oder «GBR» gewählt wird)
    - Heuristik: Die Funktion soll unter Beibehaltung der Parametertypen und
      Weglassung der Parameternamen noch verständlich sein.
        - Gut: `createPoint3D(int, int, int);` -- x, y und z sind intuitiv
        - Schlecht: `createFile(String, int, boolean);` -- Dateiname intuitiv,
          andere Parameter nicht
        - Besser: `createFileIfNotExists(String, Permissions);`
            - `boolean`-Flag als zusätzliche Funktion mit sprechendem Namen
            - `int`-Dateiberechtigungen (`0x664` für `rw-rw-r--`) als
              Parameterobjekt mit entsprechendem Typnamen
- Auf Flag-Argumente sollte verzichtet werden; besser mehrere Funktionen mit
  sprechenden Namen.
    - `openFile("foo.txt", true)` -- was bedeutet `true`?
    - `openFileCreateIfNotExists("foo.txt");`
- Auf ungewollte Nebeneffekte sollte verzichtet werden.
    - Beispiel: `checkPassword(username, password)` erstellt eine Session, wenn
      die Credentials korrekt sind.
    - Die Funktion führt eine zusätzliche, verborgene Aufgabe aus (Verletzung
      _Single Responsibility Principle_)
    - Nebeneffekte können zu Race-Conditions führen, was bei der Fehlersuche
      problematisch ist.
    - Nebeneffekte sollen über den Funktionsnamen «kommuniziert» werden (z.B.
      `tryLogin` für obiges Beispiel).
- Output-Argumente sollen vermieden werden.
    - Der Rückgabewert sollte das Ergebnis einer Funktion beinhalten.
    - Verletzung: `writeInto(buffer, text)` -- Der Parameter `buffer` enthält
      das Ergebnis der Operation, nicht der Rückgabewert.
    - Bei objektorientierten Sprachen sind Output-Argumente einfach vermeidbar.
- Funktionen sollen entweder «etwas tun» (einen Seiteneffekt haben) oder
  «antworten» (Informationen von einem Objekt liefern), nie beides.
    - Beispiel `map.set(key, val)` liefert `boolean` zurück
        - `true`, wenn das Attribut gesetzt wurde
        - `false`, wenn es das Attribut `key` _nicht_ gibt (nicht, wenn es
          nicht geklappt hat!)
        - Der Code ist schwer zu verstehen und kann zu Missverständnissen
          führen.
    - Rückgabewerte von Funktionen verleiten zum Aufruf innerhalb einer
      Bedingung:
        - `if (!map.set("x", 42))` -- ist schwer zu interpretieren
    - Lösung: Aufteilung in zwei Methoden!
        1. `map.hasAttribute(key):boolean` (Rückgabewert)
        2. `map.setAttribute(key, val):void` (Seiteneffekt)
- Exceptions sind Fehlercodes vorzuziehen.
    - Trennung Programmablauf und Fehlerbehandlung
    - Fehlercodes verleiten zum Aufrufen von Funktionen an Orten, wo
      Bedingungen verlangt werden.
    - Fehlercodes können zu tief verschachteltem Code führen.
    - Fehlerbehandlung ist eine Aufgabe, eine Funktion sollte nur eine Aufgabe
      erfüllen.
        - Die eine Funktion wirft eine Exception.
        - Die andere Funktion beginnt mit `try` und ruft erstere auf.
- Eine gute Namensgebung ist wichtig, aber schwer.
    - Lange Namen sind sprechender, jedoch mühsamer in der Handhabung.
    - Faustregel (Rob Pike): Lange Namen für grosse Gültigkeitsbereiche, kurze
      Namen für kleine Gültigkeitsbereiche:
        - `absolutePathToFileSystemTableFile` ist für den globalen Scope
          sinnvoll.
        - `i` für den Arrayindex und `n` für die Anzahl Elemente sind in einem
          `for`-Loop völlig ausreichend, da konventionell. 
- Code Smells für Funktionen (_Clean Code_): «When it stinks, change it.»
    1. Zu viele Argumente: Können zu Verwechslung und Unübersichtlichkeit
    führen.
    2. Output-Argumente: Entsprechen nicht der Erwartung des Aufrufers.
    3. Flag-Argumente: Deuten auf Funktionen mit mehreren Aufgaben hin.
    4. Tote Funkeionen: Was nicht aufgerufen wird, soll gleich gelöscht werden.

### Unit-Tests

- Grundlagen des Unit-Testings
    - Definition _Unit Test_: «A unit test is an automated piece of code that
      invokes a unit of work in the system and then checks a single assumption
      about the behaviour of that unit of work.»
    - Unit-Tests geben ein schnelles Feedback, ob etwas grundsätzlich
      funktioniert.
    - Unit-Tests sind die Basis für jedes Refactoring: Was vorher funktioniert,
      muss auch nachher noch funktionieren.
- Qualität von Testcode
    - Testcode ist kein Wegwerfcode und sollte die gleich hohe Qualität wie der
      getestete Code haben (Namensgebung, Struktur, Verständlichkeit).
        - Testcode lebt oft länger als Produktivcode, da Produktivcode
          refactored wird, aber anschliessend immer noch die gleichen Testfälle
          bestehen muss.
        - Testcode ist auch eine Form von Dokumentation des Produktivcodes.
    - Testcode muss gut lesbar sein. Es soll mit möglichst wenig Code möglichst
      viel ausgesagt werden. Eigenschaften für guten Testcode sind:
        1. Klarheit
        2. Einfachheit
        3. Ausdrucksdichte
- Test Driven Development
    - Test- und Produktivcode werden in kurzen, aufeinanderfolgenden Zyklen
      (Sekunden bis Minuten) geschrieben. Der Testcode eilt dem Produktivcode
      immer nur wenig voraus.
    - Gesetze des Test Drive Development:
        1. Produktiver Code darf erst implementiert werden, wenn es dafür einen
        Unit-Test gibt.
        2. Dieser Unit-Test darf nur gerade so viel Code enthalten, dass er
        fehlerfrei kompiliert, aber der Test scheitert.
        3. Man ergänzt jeweils nur gerade so viel produktiven Code, bis dass
        der Test erfolgreich durchläuft.
- Aufbau und Organisation von Tests
    - Domänenspezifische Testsprache: durch Schreiben eigener Assert-Methoden
        - der Name der Assert-Methode soll möglichst aussagekräftig sein
    - Pro Testfall sollte möglichst nur eine Assertion verwendet werden
    - Pro Testfall sollte nur eine Sache getestet werden. Es gelten die
      Prinzipien:
        - SOC: Separation of Concerns (Verschiedene Klassen werden durch
          verschiedene Tests abgedeckt.)
        - SRP: Single Responsibility Principle (Jeder Testfall kümmert sich um
          genau eine Sache.)
        - SLA: Single Level of Abstraction (Ein Testfall operiert nicht auf
          verschiedenen Abstraktionsstufen.)
    - Viele kleine Testfälle mit wenig Assertions erlauben eine gezieltere --
      und schnellere -- Ausführung von Tests.
    - BOC-Pattern:
        - Build: Erstellen der Testdaten
        - Operate: Manipulieren der Testdaten
        - Check: Verifizieren der Ergebnisse
    - AAA-Pattern:
        - Arrange: Ausgangssituation schaffen
        - Act: Aktion ausführen
        - Assert: Ergebnis überprüfen
    - FIRST-Prinzip:
        - Fast: Tests sollen schnell sein.
        - Independent: Tests sollen unabhängig voneinander ausführbar sein.
        - Repeatable: Tests sollen immer auf jeder Umgebung ausführbar sein.
        - Self-Validating: Das Testergebnis muss sofort ersichtlich sein
          (failure/success).
        - Timely: Tests sollten rechtzeitig und möglichst vor dem Produktivcode
          geschrieben werden.
- Test-Heuristiken von Clean Code:
    1. Unzureichende Tests vermeiden: Eine möglichst hohe Testabdeckung
    anstreben.
    2. Coverage-Werkzeug verwenden: Nicht abgedeckte Codeteile ermitteln.
    3. Triviale Tests umsetzen: Nichts ist zu trivial, um nicht getestet zu
    werden.
    4. Ignorieren von Tests: Nur temporär und mit `@Ignore` statt
    auskommentieren.
    5. Grenzbedingungen testen: Damit der ganze Wertebereich abgedeckt wird.
    6. Fehler-Nachbarschaft testen: Wo ein Fehler ist, ist auch oft ein
    zweiter.
    7. Muster des Scheiterns analysieren: Anhang Gemeinsamkeiten auf Ursachen
    schliessen.
    8. Coverage im Fehlerfall analysieren: Branch möglicherweise aufgrund von
    Tippfehler verpasst.
    9. Schnelle Tests: Damit sie oft und gerne ausgeführt werden.

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
