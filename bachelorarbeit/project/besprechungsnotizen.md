# Besprechung vom 13.03.2020

Risiko in Phase 1

- Was, wenn kein Modell lauffähig ist?
	- Gegenmassnahme definieren: Dummy-Modelle verwenden
        - Risiko nicht eingetreten: body_part und joint_detection lauffähig, rau_score trainiert
- Name "`rau_score`" überprüfen
    - Ratingen-Score: Skala 1-6 für jedes Gelenk
    - Rau-Score: Durchschnitt/Summe (?) über alle Gelenke
- Performance
	- evtl. GPU
	- Mindestspeicher erforderlich
	- mit CPU freier
	- evtl. asynchron versuchen

- dokumentieren, möglichst bald
- Ist-Zustand dokumentieren
	- Schwierigkeiten
	- Vorgehen
	- Ideen und Konzepte

- bis wann muss Architekturentscheid fallen?
	- evtl. ohne Experte

# Besprechung vom 27.03.2020

- Modelle lauffähig
	- Inputs/Outputs beschrieben
	- Inputs (Arrays mit mehreren Inputs) erlauben verschiedene Architektur-Varianten
- aktuelle Phase:
	- Tests definieren (Modelle technisch funkitionstüchtig)
	- Planung Phase II
- nächste Phase: Architektur
	- Idee: Dummy-Prototyp
- Validierung: Durchschnittswert von mehreren Prognosen
	- einfache Metrik: Accuracy overall, Problematik wegen Inbalance (downsampling anderer Klassen, upsampling: Daten mehrfach verwenden)
	- Möglichkeit komplette Datensätze nachzuvollziehen (von Röntgenbild bis Endscore)
		- bei SCQM nachfragen: neue Daten verlangen (Röntgenbild zu Ratingen-Score, soviele wie möglich)
		- möglichst bald, NDA möglich
	- Phase 2: Evaluationsworkflow (Übereinstimmung wichtiger als rohe Score als Metrik)
- wichtig: möglichst alles festhalten
- Kontakt mit italenischem Professor aufnehmen

Fragen:

- "Verdankung": selber verfassen (SCQM, Auftraggeber, Hilfestellungen)

# Besprechung vom 17.04.2020

- Erledigt seit letzter Besprechung
    - Evaluation
        - Testdaten ausgewählt und gesammelt (ab Jahr 2019)
        - Skript zum Selektieren von Testdaten (linke Hände und Rest)
        - Klassifikation von Testdaten (ca. 50%)
        - Untersuchung der Modelle im Bezug auf Datentypen
        - Recherche zu möglichen Evaluationsvarianten
    - Architektur
        - Recherche zu Integrationsarten mit Vor- und Nachteilen
        - Diskussion zu Web-Services/HTTP
        - Architekturvarianten ausgearbeitet, überarbeitet
        - Einarbeitung in Messaging-Systeme (ZeroMQ, RabbitMQ)
    - Prototyp(en) mit HTTP, ZeroMQ, RabbitMQ
        - aufgesetzt
- Zu erledigen bis Ende der Phase (19. April)
    - Projektplanung Phase 3
- Zu erledigen bis Zwischenpräsentation
    - Prototyp (textuelle Räpresentation)
        - implementieren
        - für Live-Demo vorbereiten
    - Slides fertigstellen
- verzögert
    - definitive und begründete Technologieevaluation (Go, Python, RabbitMQ, JSON)
- Fragen
    - Modell `body_part` meldet eine Wahrscheinlichkeit für jedes Körperteil.
      Diese muss interpretiert werden (Schwellwert). Ist dieser Schwellwert als
      Hyperparameter zu betrachten? Wie ist ein sinnvoller Wert zu finden? Im
      Bezug auf die Evaluationsmetrik zu optimieren?
        - Vorschlag: höchste Wahrscheinlichkeit linke Hand und > 50%, Ausblick
        - Lösung: höchste Wahrscheinlichkeit nehmen (summiert auf 1),
          Konsequenzen beschreiben und im Ausblick erwähnen, evtl. Schwelle
          festlegen
        - Frage: gibt es eine "Nothing"-Klasse?
    - Evaluationsdatenset: muss ich im Bezug auf eine Hold-Out-Validation
      prüfen, ob es i.i.d. ist? (bereits viel Aufwand bei der Selektion:
      manuelle Klassifikation)
        - Vorschlag: nicht prüfen, aber im Ausblick erwähnen (abgrenzen), von i.i.d. ausgehen
    - Die beste Evaluationsmetrik (Cohen's Squared Kappa) bedingt zwei Scores
      pro Röntgenbild. Für die Testdaten liegt jedoch nur eine vor. Ein
      weiteres Scoring ist im Rahmen der Arbeit nicht möglich. Soll ich auf
      eine einfachere Variante ausweichen und diese auch umsetzen, oder nur die
      ideale Variante (im Ausblick?) beschreiben, wie man sie End-to-End
      implementieren könnte?
        - Vorschlag: implementieren, Testdaten fingieren (5-10)
    - Workflow: genügt es, die Technik zur Verfügung zu stellen, oder soll das
      System als ganzes effektiv evaluiert werden (Aussage über Performance
      machen)?
        - Vorschlag: im Ausblick erwähnen
    - Vorschlag: Beschreibung des idealen Ansatzes, Umsetzung einer
      vereinfachten Metrik (Verhältnis von "Almost Correct"-Predictions, +/-1),
      womit sich das Gesamtsystem End-to-End testen lässt.
    - Altenative: Die ideale Metrik mit erfundenen Daten umsetzen, um das
      Prinzip zu demonstrieren, und die Technik bereit zu haben.
      Platzhalter-Daten, Grössenordnung 10.
    - Kompromiss: Beide Metriken zur Verfügung stellen. (Problem: Zeitknappheit)
        - "Almost Correct +/-1": mit richtigen Daten
        - Cohen's Squared Kappa: mit Fake-Daten
            - evtl. Sampling für das Gewichten
        - anhand Testdaten kann nur von einem Arzt ausgegangen werden
             - Cohen's Kappa: nur eine Score nötig
             - Cohen's Squared Kappa: Ausblick evtl. Implementierung bei Zeit
- weitere Notizen
    - was, falls HTTP (synchron) zu langsam ist?
    - Geschichte erzählen
    - worum geht es?
    - Video als Teaser

# Besprechung vom 01.05.2020

- Status
    - Prototyp lauffähig, aber noch langsam
        - Modelle anders laden
        - zehn Services mit einem Modell (aufwändige Konfiguration)
        - ein Service mit zehn Modellen (schwergewichtig)
    - Dokumentation
        - Kapitel 1: fertig
        - Kapitel 2: Änderung an `ratingen_score`, sonst fertig
        - Kapitel 3: ca. 50% fertig
        - Kapitel 4: ca. 2/3 fertig
        - Kapitel 5: -
        - Kapitel 6: -
        - Kapitel 7: nur Notizen
        - Kapitel 8: Wahl der Programmiersprache teilweise, sonst noch nichts
    - Web Abstract: verfasst
    - Video: noch nichts
- Fragen
    - Codierung/Klassifizierung der Arbeit (Seite 2)
        - A: Einsicht (nehme ich an): je nach Auftraggeber
        - B: Rücksprache
        - C: Sperre
    - Verlinkung von GitHub-Repositories (nur URL, nicht APA) ok? Link und letztes Zugriffsdatum hinzufügen!
    - Abstract auf Seite 1
        - Titelseite: nur allgemeine Informationen
        - Abstract nicht auf Titelseite, aber ca. 2/3 Seite ist ok
        - eher Grafiken (Hand, Architektur)
        - Abstract vor Inhaltsverzeichnis (Management Summary)
    - Web Abstract: Metadaten oben ok?
- Cohen's Kappa
    - Accuracy der Übereinstimmung, Accuracy auch bei Zufall möglich
    - Cohen's Kappa kann mit Zufall umgehen
    - Interpretation: https://www.ncbi.nlm.nih.gov/pmc/articles/PMC3900052/
    - Metriken gut verstehen (wissen, was ich mache): Fragen könnten gestellt werden
    - scipy/scikit learn: implementierungen
    - evtl. Beispiel selber konstruieren, bevor Daten vorhanden sind
- eine Komponente mit allen Modellen ist schöner
    - default session: global
    - mit spezifischer Session arbeiten statt global session
- wie hoch könnte timeout sein?
    - sinnvollen Wert finden? Ausblick
    - vorerst mit arbiträrem Wert arbeiten, ca. 60 sec.
    - tensorflow-gpu: nimmt gesamtes CPU-Memory
        - auf GPU Session Limits setzen, nur so viel wie nötig
        - abklären wie
        - können alle 10 (12) Modelle in GPU gehalten werden?
    - ausprobieren, auch ohne GPU möglich
- kleines Frontend wäre schön, evtl. nach Abgabe noch machen
    - auch für Video sinnvoll, d.h. schon während Arbeit machen

# Besprechung vom 15.05.2020

- TODO
    - Go Benchmark mit 5+ Bildern
    - accuracy, recall, f1 score recherchieren und implementieren0
        - evtl. mit handgestrikten Beispielen (Unittests)
    - Abgabe von Quellcode
        - Transfer-Services: Datenmenge ok?
        - Seantis: Modelle abgeben
        - nur public-domain Bilder
    - Ausblick: Modelle aktualisieren
        - Versionsüberblick (verwendet vs. aktuell)
            - Update versuchen, Fehler analysieren
            - 1-4h
- Fragen
    - Ausblick: Modelle aktualisieren
        - schwer zu beschreiben, wenn man es nicht selber in Angriff nimmt
        - wie vorgehen?
    - Ausführung auf GPU?
        - Modelldaten knapp 1GB (möglich)
        - CUDA-Container mit spezieller Docker-Runtime nötig
        - Vorschlag: nicht machen, im Ausblick beschreiben
        - ok, kann weggelassen werden
        - Achsen in Matrix falsch
    - Evaluation
        - confidence interval für Kappa, aber nicht für quadratic kappa berechnet
        - finde ich wohl noch heraus...
    - weiteres Vorgehen ok?
    - Abgabe von Quellcode
        - ganzes Repository: mehrere Gigabyte (Modelle, Bilder)
        - nur Code abgeben?
        - Evaluation wäre mit CSV-Daten (wenige kb) lauffähig
    - Video ok?
    - Web-Abstract ok?
- Themen
    - Evaluation: Cohen's Quadratic Kappa > Cohen's Kappa: bekanntes Phänomen (tridiagonale Tabellen)
        - siehe Paper
        - Vorgehen: Fokus auf Dokumentation (Abgabe idealserweise noch im Mai, Wochenende 29./30.)
