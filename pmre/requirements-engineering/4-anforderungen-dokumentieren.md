# Anforderungen dokumentieren

- Was ist eine Anforderungsspezifikation?
    - eine systematisch dargestellte, vorgegebenen Kriterien genügende Sammlung
      von Anforderungen
- Welche Rolle spielt die Dokumentation in einem Projekt?
    - unterstützende Funktion bei der Kommunikation
    - Festhalten der Sachverhalte in einer für alle Adressaten genügenden
      Qualität
- Wozu werden Anforderungen dokumentiert?
    - Anforderungen als Basis der Systementwicklung: Anforderungen wirken sich
      direkt oder indirekt auf das Projekt und dessen Erfolg aus.
    - Rechtliche Relevanz: Anforderungen sind rechtlich verbindlich und helfen
      bei der Klärung rechtlicher Konflikte.
    - Komplexität: Anforderungen werden dokumentiert, um den Überblick über
      komplexe Systeme behalten zu können.
    - Zugreifbarkeit: Eine für alle Beteiligten verfügbare Dokumentation
      ermöglicht diesen eine schnelle Einarbeitung.
- Aus welchen Perspektiven können Anforderungen dokumentiert werden?
    1. Strukturperspektive: statisch-strukturelle Perspektive auf das System
        - Struktur von Ein- und Ausgabedaten
        - Nutzungs- und Abhängigkeitsbeziehungen (zu Diensten externer Systeme)
    2. Funktionsperspektive: Informationen/Daten des Systems
        - die im Systemkontext manipuliert werden
        - die in den Systemkontext einfliessen
    3. Verhaltensperspektive: zustandsorientierte Reaktion des Systems auf
    Ereignisse
        - Bedingungen für Zustandswechsel
        - Effekte des Systems auf den übrigen Systemkontext
- Welche Arten von Dokumentation gibt es?
    - natürliche Sprache (Prosa)
        - `+` vielseitig einsetzbar
        - `+` funktioniert für alle Arten von Anforderungen
        - `+` Notation allen Stakeholdern von Anfang an bekannt
        - `-` mehrdeutig
        - `-` Vermischung der Perspektiven
    - konzeptuelle Modelle
        - `+` isolierte Betrachtung der Perspektiven
        - `+` Kompaktheit
        - `+` für geübten Leser verständlicher
        - `+` Eindeutigkeit
        - `-` setzt spezifische Modellierungskenntnisse voraus
    - zweckmässige Kombinationen der beiden
        - Nachteile der einen Form durch Vorteile der anderen Form verringern
        - Beispiel: natürlichsprachliche Kommentare in UML-Diagrammen
- Was sind die wichtigsten Diagramme zur Dokumentation?
    - Use-Case-Diagramm: Überblick über ein System
        - zur Verfügung gestellte Funktionen
        - Verbindungen zu externen Interaktionspartnern
    - Klassendiagramm: statische Struktur von Daten
        - dokumentiert Abhängigkeiten zum Systemkontext
        - stellt komplexe Beriffsysteme von Fachgebieten strukturiert dar
    - Aktivitätsdiagramm: Geschäftsprozesse und andere Abläufe
        - dokumentiert Ablauflogik eines Use Case
        - spezifiziert Verarbeitungslogik einzelner Operationen
    - Zustandsdiagramm: ereignisgesteuertes Verhalten
        - Zustände eines Systems
        - Ereignisse und Bedingungen für Zustandsübergänge
        - Effekte auf den Systemkontext
- Wie kann eine Dokumentation strukturiert werden?
    - Standardisierte Dokumentstrukturen
        - erleichtern die Einarbeitung
        - ermöglichen eine schnelle Erfassung von Inhalten
        - ermöglichen selektives Lesen/Überprüfen
        - ermöglichen automatisches Prüfen (auf Vollständigkeit)
        - ermöglichen einfache Wiederverwendung von Inhalten
    - Angepasste Standardinhalte
        - Adaption standardisierter Dokumentstrukturen
        - erfordern minimale Inhalte
- Was sind die wichtigsten standardisierten Dokumentstrukturen?
    - Rational Unified Process (RUP): für objektorientierte Methoden entwickelt
        - Auftraggeber erstellt Business Model (Geschäftsregeln,
          -anwendungsfälle, -ziele)
        - Auftragnehmer erstellt Software Requirements Specification
          (Dokumentation der Softwareanforderungen)
    - Standard ISO/IEC/IEEE 29148:2011: für Dokumentation von
      Softwareanforderungen, Kapitel:
        - einführende Informationen (Zweck, Abgrenzung)
        - Auflistung referenzierter Dokumente
        - spezifische Anforderungen (funktionale, nicht-funktionale)
        - geplante Verifikationsmassnahmen
        - Anhänge (getroffene Annahmen, identifizierte Abhängigkeiten)
    - V-Modell
        - Auftraggeber erstellt Lastenheft (Gesamtheit der Forderungen zu
          Lieferung und Leistungen: «wozu»; Forderungen aus Anwendersicht)
        - Auftragnehmer erstellt Pflichtenheft auf Basis des Lastenhefts
          (Konkretisierung des Lastenhefts: Realisierungsvorgaben)
- Was sind die minimalen Inhalte für angepasste Dokumentstrukturen?
    - Einleitung: dokumentübergreifende Informationen zur Gewährung eines
      Überblicks
        - Zweck: «warum?», Zielgruppe, Leserkreis
        - Systemumfang: Name, Vorteile und Ziele des zu entwickelnden Systems
        - Stakeholder: Auflistung mit relevanten Informationen
        - Definitionen, Akronyme, Abkürzungen
        - Referenzen: auf andere Dokumente
        - Übersicht: Erläuterung weiterer Inhalte und Struktur/Aufbau des
          Anforderungsdokuments
    - Allgemeine Übersicht: Verständnis der Anforderungen erhöhen
        - Systemumfeld: System- und Kontextabgrenzung
        - Architekturbeschreibungen: Schnittstellen, Beschränkungen
        - Systemfunktionalität: grobe Funktionalität (Use Cases)
        - Nutzer und Zielgruppen
        - Randbedingungen: mögliche Beeinträchtigungen
        - Annahmen: Annahmen über den Systemkontext, auf denen die
          Anforderungen beruhen
    - Anforderungen: funktionale und nicht-funktionale
    - Anhang: weiterführende Unterlagen, Hintergrundinformationen
    - Index: Inhaltsverzeichnis, nachgetragener(!) Index
- Wozu werden Anforderungsdokumente verwendet?
    - grundsätzlich: als Grundlage für verschiedene Projektaufgaben
    - Planung: Ableitung von Arbeitspaketen und Meilensteinen
    - Architekturentwurf: auf Basis detaillierter Anforderungen und
      Randbedingungen
    - Implementierung: auf Basis des Architekturentwurfs
    - Test: Testfälle zur Überprüfung des Systems
    - Änderungsmanagement: Ausmass von Änderungen abschätzen
    - Systemnutzung und Systemwartung: Art des Fehlers (Implementierung,
      Bedienung) analysieren
    - Vertragsmanagement: Anforderungsdokument als Vertragsgegenstand
- Welche Qualitätskriterien gelten für das Anforderungsdokument?
    - Eindeutigkeit und Konsistenz: Anforderungen eindeutig und untereinander
      widerspruchsfrei
    - Klare Struktur:
        - grosser Umfang erfordert gute Struktur
        - gute Struktur erlaubt selektives Lesen
    - Modifizierbarkeit und Erweiterbarkeit:
        - Anforderungen müssen geändert, hinzugefügt und entfernt werden können
        - Anforderungsdokument sollte der Versionsverwaltung des Projekts
          unterliegen
    - Vollständigkeit:
        - alle Anforderungen mit allen relevanten Informationen (Eingaben,
          Ereignisse, Reaktionen, Fehler- und Ausnahmefälle) dokumentiert
        - formale Gesichtspunkte: Beschriftung von Grafiken, Diagrammen,
          Tabellen; Quellen- und Abkürzungsverzeichnisse
    - Verfolgbarkeit (Traceability): zwischen Anforderungsdokument und anderen
      Dokumenten
- Welche Qualitätskriterien gelten für einzelne Anforderungen?
    - abgestimmt: für alle Stakeholder korrekt und notwendig
    - eindeutig: Interpretationsspielraum ausgeschlossen
    - notwendig: von allen Stakeholdern akzeptiert, die Gegebenheiten im
      Systemkontext widerspiegelnd
    - konsistent: in sich widerspruchsfrei
    - prüfbar: durch Test oder Messung nachweisbar
    - realisierbar: mit gegebenen organisatorischen, rechtlichen, technischen
      und finanziellen Rahmenbedingungen
    - verfolgbar:
        - Ursprung und Beziehungen zu anderen Dokumenten nachvollziebar
        - eindeutige Identifikation vorhanden und konsequent genutzt
    - vollständig: Anforderung ist vollständig beschrieben oder als
      unvollständig («tbd»: «to be determined») markiert (suchbarer Text,
      Statusfeld)
    - verständlich: für alle Stakeholder
- Was sollte ein Glossar beinhalten?
    - generell: Definition einer konsistenten projektspezifischen und/oder
      projektübergreifenden Terminologie zur Vermeidung von Missverständnissen
    - Kontextspezifische Fachbegriffe
    - Abkürzungen und Akronyme
    - Alltägliche Begriffe mit spezieller Bedeutung im Projektkontext
    - Synonyme (verschiedene Begriffe gleicher Bedeutung)
    - Homonyme (Begriff mit verschiedenen Bedeutungen)
- Welche Anforderungen sollte ein Glossar erfüllen?
    - zentrale Verwaltung des Glossars: genau ein verbindlich gültiges Glossar
    - Verantwortlickeit: eine konkrete Person
    - projektübergreifend gepflegt
    - allgemein zugänglich
    - Herkunft von Begriffen ausgewiesen
    - unter allen Stakeholdern abgestimmt
    - einheitlich strukturiert (mittel Schablone)
