# Komponenten

Herkunft: _componere_ (lat.) = zusammensetzen

![Komponentendiagramm (UML2)](komponentendiagramm.png){width=360px}

## Begriffe und Architekturen

### Der Komponentenbegrif

- Definition: Eine Software-Komponente
    1. ist ein Software-Element
    2. passt zu einem bestimmten Komponentenmodell
    3. folgt einem bestimmten _Composition Standard_
    4. kann ohne Änderungen mit anderen Komponenten verknüpft und ausgeführt werden
- Eigenschaften: Software-Komponenten
    1. sind eigenständig ausführbare Softwareeinheiten
    2. sind über ihre Schnittstellen austauschbar definiert
    3. lassen sich unabhängig voneinander entwickeln
    4. können kunden- und anwendungsspezifisch oder anwendungsneutral und wiederverwendbar sein
        - COTS (Commercial off-the-shelf): Software «von der Stange»
    5. können installiert und deployed werden
    6. können hierarchisch verschachtelt sein
- Komponentenmodelle
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
- Beispiele verbreiteter Komponentenmodelle:
    - Microsoft .NET
    - EJB (Enterprise Java Beans)
    - OSGi (Open Services Gateway Initiative)
    - CORBA (Common Object Request Broker Architecture)
    - DCOM (Distributed Component Object Model)

### Der Nutzen von Komponenten

- Packaging: _Reuse Benefits_
    - Komplexität durch Aufteilung reduzieren (_Divide and Conquer_)
    - Wiederverwendung statt Eigenentwicklung spart Entwicklungszeit und Testaufwand
    - erhöhte Konsistenz durch Verwendung von Standardkomponenten
    - Möglichkeit zur Verwendung bestmöglichster Komponente auf dem Markt
- Service: _Interface Benefits_
    - erhöhte Produktivität durch Zusammenfügen bestehender Komponenten
    - erhöhte Qualität aufgrund präziser Spezifikationen und vorgetesteter Software
- Integrity: _Replacement Benefits_
    - erweiterbare Spezifikation durch inkrementelle Entwicklung und inkrementelles Testing
    - parallele und verteilte Entwicklung durch präzise Spezifizierung und Abhängigkeitsverwaltung
    - Kapselung begrenzt Auswirkungen von Änderungen und verbessert so wie Wartbarkeit

### Der Entwurf mit Komponenten

- Komponentenbasierte Enwicklung
    - steigende Komplexität von Systemen, Protokollen und Anwendungsszenarien
    - Eigenentwicklung wegen Wirtschaftlichkeit und Sicherheit nicht ratsam
    - Konstruktion von Software aus bestehenden Komponenten immer wichtiger
    - Anforderungen (aufgrund mehrmaliger Anwendung) an Komponenten höher als an reguläre Software
- Praktische Eigenschaften
    - Einsatz einer Komponente erfordert nur Kenntnisse deren Schnittstelle
    - Komponenten mit gleicher Schnittstelle lassen sich gegeneinander austauschen
    - Komponententests sind Blackbox-Tests
    - Komponenten lassen sich unabhängig voneinander entwickeln
    - Komponenten fördern die Wiederverwendbarkeit
- Komponentenspezifikation
    - Export: angebotene/unterstützte Interfaces, die von anderen Komponenten genutzt werden können
    - Import: benötigte/verwendete Interfaces von anderen Komponenten
    - Kontext: Rahmenbedingungen für den Betrieb der Komponente
    - Verhalten der Komponente

### Komponenten in Java

- Komponenten in Java SE
    - Komponenten als normale Klassen implementiert
    - Komponenten können, müssen sich aber nicht and die _Java Beans Specification_ halten
        - Default-Konstruktor
        - Setter/Getter
        - Serialisierbarkeit
        - PropertyChange
        - Vetoable
        - Introspection
    - Weitergehende Komponentenmodelle in Java EE
        - Servlets
        - Enterprise Java Beans
- Austauschbarkeit
    - Die Austauschbarkeit von Komponenten wird durch den Einsatz von Schnittstellen erleichtert.
    - Schnittstellen werden als Java-`Interface` definiert und dokumentiert (JavaDoc).
    - Eine Komponente implementieren eine Schnittstelle als Klasse.
        - mehrere, alternative Implementierungen möglich
        - Austauschbarkeit über Schnittstellenreferenz möglich
    - Beispiel: API von JDBC (Java Database Connectivity)
        - von Sun/Oracle als API definiert
        - von vielen Herstellern implementiert (JDBC-Treiber für spezifische Datenbanksysteme)
        - Datenbankaustausch auf Basis von JDBC möglich
- Deployment
    - über `.jar`-Dateien (Java Archive): gezippte Verzeichnisstrukturen bestehend aus
        - kompilierten Klassen und Interfaces als `.class`-Dateien
        - Metadaten in `META-INF/manifest.mf`
        - optional weitere Ressourcen (z.B. Grafiken, Textdateien)
    - Deployment von Schnittstelle und Implementierung zum einfacheren Austausch häufig in getrennten `.jar`-Dateien mit Versionierung, Beispiel (fiktiv):
        - `jdbc-api-4.2.1.jar` enthält die Schnittstelle
        - `jdbc-mysql-3.2.1.jar` enthält die MySQL-Implementierung
        - `jdbc-postgres-4.5.7.jar` enthält die PostgreSQL-Implementierung
        - Versionierung idealserweise im Manifest und im Dateinamen (Konsistenz beachten!)

## Schnittstellen

### Begriff und Konzept

- Der Begriff _Schnittstelle_ als Metapher
    - Beim Zerschneiden eines Apfels entstehen zwei spiegelsymmetrische Oberflächen.
    - Die Komponenten müssen so definiert werden, damit sie an der Schnittstelle zusammenpassen, als ob sie vorher auseinandergeschnitten worden wären.
    - Tatsächlich werden _Verbindungsstellen_ erstellt, welche Kombinierbarkeit sicherstellen.
    - Eine Schnittstelle tut nichts und kann nichts.
    - Schnittstellen trennen nichts, sie verbinden etwas:
        - Komponenten untereinander (Programmschnittstellen)
        - Komponenten mit dem Benutzer 
- Die Bedeutung von Schnittstellen (bei korrektem Gebrauch):
    1. machen Software leichter verständlich (man braucht nur die Schnittstelle und nicht die Implementierung zu kennen)
    2. helfen uns Abhängigkeiten zu reduzieren (Abhängigkeit nur von einer Schnittstelle, nicht von einer Implementierung)
    3. erleichtern die Wiederverwendbarkeit (bei der Verwendung bewährter Schnittstellen statt Eigenentwicklung)
- Die Beziehung zwischen Schnittstellen und Architektur:
    - System > Summe seiner Teile (Beziehungen zwischen den Teilen: durch Schnittstellen ermöglicht)
        - Schnittstellen & Beziehungen zwischen den Komponenten: wichtigste Architekturaspekte!
        - Mehrwert des Systems gegenüber Einzelkomponenten liegt in den Schnittstellen & Beziehungen der Komponenten zueinander
    - Spezialisten für Teilsysteme konzentrieren sich auf ihr Zeilproblem
        - Architekten halten das Gesamtsystem über Schnittstellen zusammen
        - Schnittstellen verbinden ein System mit der Aussenwelt und ermöglichen die Interaktion damit
- Kriterien für gute Schnittstellen
    1. Schnittstellen sollen _minimal_ sein:
        - wenige Methoden (mit möglichst geringen Überschneidungen in ihren Aufgaben)
        - geringe Anzahl von Parameters
        - setzen möglichst keine oder nur wenige globale Daten voraus
    2. Schnittstellen sollen _einfach zu verstehen_ sein
    3. Schnittstellen sollen _gut dokumentiert_ sein

### Dienstleistungsperspektive

- Die Schnittstelle als Vertrag:
    - Ein _Service Consumer_ schliesst einen Vertrag mit einem _Service Provider_ für eine _Dienstleistung_ ab
- Design by Contract (DbC): Das Zusammenspiel zwischen den Komponenten wir mit einem Vertrag geregelt
    - _Preconditions_: Zusicherungen, die der Aufrufer einhalten muss
        - Nutzer: Prüfen der Vorbedingungen vor der Ausführung
        - Anbieter: Überprüfung mittels Assertions
    - _Postconditions_: Nachbedingungen, die der Aufgerufene garantiert
        - Nutzer: Überprüfung mittels Assertions
        - Anbieter: Prüfen der Nachbedingungen nach der Ausführung
    - _Invarianten_: Über alle Instanzen einer Klasse geltende Grundannahmen ab deren Erzeugung
        - Anbieter: Überprüfung mittels Assertions

### Spezifikation von Schnittstellen

- Dokumentation von Schnittstellen
    - Umfang:
        - was ist wichtig für die Benutzung der Komponente
        - was muss der Programmierer versethen und beachten
    - Eigenschaften der Methoden:
        - Syntax (Rückgabewerte, Argumente, Typen, call by value/reference)
        - Semantik (was bewirkt die Methode)
        - Protokoll (synchron/asynchron)
        - Nichtfunktionale Eigenschaften (Performance, Robustheit, Verfügbarkeit)
    - Schnittstellen an der Systemgrenze fliessen in die Systemspezifikation ein
- öffentliche Schnittstellen werden als _API_ bezeichnet (Application Programming Interface)
    - objektorientierte API (sprachabhängig, z.B. API der JSE)
    - REST-API (Representational State Transfer, sprach- und plattformunabhängig, datenzentriert)
    - Messaging-API (sprach- und plattformunabhängig, z.B. Push-Notifications für Mobile Apps)
    - dateibasierte API (Informationsaustausch, Konfigurationsdateien)
