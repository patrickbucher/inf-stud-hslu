# Einleitung und Grundlagen

- Wozu Requirements Engineering?
    - Der Umgang mit Anforderungen ist eine signifikante Ursache für
      Projektfehlschläge.
    - Bessere Kommunikation von Anforderungen reduziert die Anzahl
      gescheiterter Projekte.
    - Ein grosser Teil der Fehler in Systemprojekten entsteht bereits im
      Requirements Engineering.
    - Mangelhafte Anforderungen werden durch die Entwickler (unbewusst)
      vervollständigt und (falsch) interpretiert. Mängel an Anforderungen sind:
        - fehlende oder unklar formulierte Anforderungen
        - Anforderungen widerspiegeln nicht Kundenwünsche und erfüllen nicht
          dessen Bedürfnisse
        - die Formulierungen von Anforderungen erlauben
          Interpretationsspielraum
        - Stakeholder verschweigen Sachverhalte, die sie als selbstverständlich
          erachten
        - Beteiligte haben unterschiedlichen Erfahrungs- und Wissensstand
    - Je später ein Fehler im Entwicklungsprozess behoben wird, desto höher
      fallen die Kosten für dessen Korrektur aus.
    - Fehlerfreie und vollständige Anforderungen sind die Basis für eine
      erfolgreiche Systementwicklung.
- Was ist eine Anforderung?
    - Eine dokumentierte Repräsentation einer Bedingung oder Fähigkeit
        - die ein Benutzer zur Lösung eines Problems/zur Erreichung eines Ziels
          benötigt
        - die ein (Teil)system zur Erfüllung einer Vorgabe (Vertrag, Norm,
          Spezifikation) benötigt
- Was ist ein Stakeholder?
    - Ein Stakeholder ist direkt oder indirekt von einem Projekt betroffen.
    - Ein Stakeholder hat direkten oder indirekten Einfluss auf die
      Anforderungen eines Projekts.
- Was ist die Aufgabe des Requirements Engineering?
    - Die Anforderungen der Stakeholder
        - zu ermitteln (detaillieren, verfeinern)
        - zweckmässig zu dokumentieren (natürliche Sprache, Modelle)
        - zu überprüfen und abzustimmen (bestimmten Qualitätskriterien
          entsprechend)
        - über den ganzen Projektlebenszyklus hinweg zu verwalten
          (strukturieren, für Rollen aufarbeiten, konsistent ändern und
          umsetzen)
- Wie ist das Requirements Engineering in verschiedene Vorgehensmodelle
  eingebettet?
    - Schwergewichtige Vorgehensmodelle (V-Modell, Wasserfallmodell):
      abgeschlossene, zeitlich befristete erste Phase
    - Leichtgewichtige Vorgehensmodelle (eXtreme Programming, Scrum):
      kontinuierlicher, phasenübergreifender Prozess
- Welche Rolle spielt die Kommunikation beim Requirements Engineering?
    - Der Austausch von Informationen benötigt eine gemeinsame Sprache
      (Glossar, formale Beschreibungssprache wie UML).
    - Vereinfachungen im sprachlichen Ausdruck führen zu Ungenauigkeiten und
      ergeben dadurch Interpretationsspielraum.
- Wie sieht die Rolle des Requirements Engineers aus?
    - Der Requirements Engineer pflegt meist als Einziger direkten Kontakt zu
      allen Stakeholdern.
    - Er muss sich in die verschiedenen Fachgebiete der Stakeholder
      einarbeiten, um die Bedürfnisse hinter den Aussagen der Stakeholder zu
      erkennen.
    - Er dient als Übersetzer zwischen dem Fachgebiet und den
      Entwicklern/Architekten.
- Welche Fähigkeiten braucht ein Requirements Engineer?
    1. Analytisches Denken: schnelles Verstehen unbekannter Fachgebiete
    2. Empathie: erkennen, was der Stakeholder tatsächlich benötigt
    3. Kommunikationsfähigkeit: zuhören, die richtigen Fragen stellen und
    nachfragen
    4. Konfliktlösungsfähigkeit: Konflikte erkennen, zwischen Parteien
    vermitteln und den Konflikt auflösen
    5. Moderationsfähigkeit: zwischen verschiedenen Meinungen vermitteln,
    Diskussionen leiten
    6. Selbstbewusstsein: mit Kritik umgehen können, selbstsicher auftreten
    7. Überzeugungsfähigkeit: Anforderungen der Stakeholder verteidigen,
    Konsens unter Stakeholdern herstellen und Entscheidungen herbeiführen
- Welche Arten von Anforderungen gibt es?
    1. Funktionale Anforderungen: geforderte Funktion, die ein System anbieten
    soll
        - Beispiel: Zu jeder Person sollen zwei Adressen erfasst werden können.
    2. Qualitätsanforderung: betrifft Performanz, Verfügbarkeit,
    Zuverlässigkeit, Skalierbarkeit, Portabilität
        - grosser Einfluss auf die Systemarchitektur
        - auch als «nicht funktionale Anforderung» bezeichnet
        - werden häufig unzureichend dokumentiert
        - sollen möglichst frühzeitig ermittelt, dokumentiert und unter
          Stakeholdern abgestimmt werden
        - sollen möglichst objektiv überprüfbar und mit quantitativen Angaben
          konkretisiert sein
        - können durch funktionale Anforderungen konkretisiert werden (z.B.
          Forderung nach erneuter Passworteingabe bei bestimmten Aktionen zur
          Erhöhung der Sicherheit)
        - Beziehung zu funktionalen Anforderungen sollten explizit festgehalten
          werden.
        - Beispiel: 95% aller Anfragen sollen in weniger als einer Sekunde
          beantwortet werden können.
    3. Randbedingungen/Rahmenbedingungen: von Projektbeteiligten nicht
    beeinflussbare Gegebenheiten (Systemlandschaft, Freigabetermin, Budget,
    Projektpersonal)
        - werden nicht umgesetzt, müssen aber berücksichtigt werden
        - schränken die Umsetzungsmöglichkeiten ein
        - Beispiel: Das Projekt muss innert drei Monaten abgeschlossen sein.
- Welche Arten von Qualitätsanforderungen gibt es?
    1. Performanz: Antwortzeiten, Ressourcenverbrauch
    2. Sicherheit: Nachweisbarkeit, Authentizität, Vertraulichkeit, Integrität
    3. Zuverlässigkeit: Verfügbarkeit, Fehlertoleranz, Wiederherstellbarkeit
    4. Benutzbarkeit: Barrierefreiheit, Erlernbarkeit, Bedienbarkeit
    5. Wartbarkeit: Wiederverwendbarkeit, Analysierbarkeit, Modifizierbarkeit,
    Prüfbarkeit
    6. Übertragbarkeit: Anpassbarkeit, Installierbarkeit, Austauschbarkeit
- Was ist das Ziel des Requirements Engineering?
    - Das vollständige Dokumentieren von Kundenanforderungen in guter Qualität.
    - Das frühzeitige Erkennen und beheben von Fehlern.
