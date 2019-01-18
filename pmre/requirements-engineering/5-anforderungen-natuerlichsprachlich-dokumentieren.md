# Anforderungen natürlichsprachlich dokumentieren

- Welche Bedeutung haben Transformationseffekte bei der Wahrnehmung und
  Darstellung auf das Requirements Engineering?
    - Der Requirements Engineer kann aus der Oberflächenstruktur (formulierte
      Anforderungen) durch gezieltes Nachfragen die Tiefenstruktur (tatsächlich
      Gemeintes) ermitteln.
- Welche Transformationsprozesse treten beim Formulieren von Anforderungen auf?
    1. Nominalisierung
        - umfassender Prozess wird unter Weglassung von Details zu einem
          Ereignis gemacht
        - Beispiel: «die Eingabe» statt «eingeben»
        - Ausnahmen und Ein-/Ausgabeparameter müssen ausreichend definiert sein
    2. Substantive ohne Bezugsindex
        - Begriffe sind unvollständig spezifiziert
        - Beispiel: «die Daten», «der Anwender»
        - Substantive müssen um weitere Informationen ergänzt werden
    3. Universalquantoren
        - Aussagen werden über sämtliche Objekte einer Menge gemacht
        - Beispiel: «nie», «immer», «alle», «keine»
        - Aussagen müssen hinterfragt und Ausnahmen definiert werden
    4. Unvollständig spezifizierte Bedingungen
        - bei Bedingungen wird nur der Positivfall definiert
        - Beispiel: «wenn …, dann …»
        - Negativfall («sonst») muss spezifiziert werden
    5. Unvollständig spezifierte Prozesswörter
        - bei Verben fehlen Subjekt und Objekte
        - Beispiel: «die Daten werden übertragen»
        - Subjekt (mittels Aktivformulierung) und weitere Parameter («von wo»,
          «wohin» beim Verb «übertragen») müssen definiert werden
- Wozu dienen Satzschablonen/Requirement Templates?
    - Zur Reduzierung obengenannter sprachlicher Effekte
    - Zur Erreichung syntaktisch eindeutig formulierter Anforderungen
- Wie muss eine Satzschablone aufgebaut sein?
    1. Verbindlichkeit festlegen: bindend, empfohlen, wünschenswert?
        - Modalverben: «müssen», «sollen», «können»
    2. Kern der Anforderung bestimmen: geforderte Funktionalität (Prozess)
    bezeichnen
        - Vorgänge oder Tätigkeiten: ausschliesslich Verben
    3. Aktivität des Systems charakterisieren
        1. selbständige Systemtätigkeit: «Das System muss _Prozesswort_ …»
        2. Benutzerinteraktion: «Das System muss _wem?_ die Möglichkeit bieten
        _Prozesswort_ …»
        3. Schnittstellenanforderung: «Das System muss fähig sein _Prozesswort_
        …»
    4. Objekte einfügen
        - Prozesswort um Objekte ergänzen: was, wie, wo etc.
    5. Logische und zeitliche Bedingungen formulieren
        - «sobald» für zeitliche Bedingungen
        - «falls» für logische Bedingungen
        - «wenn» zu vermeiden, da es eine logische _und_ zeitliche Bedeutung
          hat
        - Qualitätsanforderungen mittels Nebensatz an den Anfang der
          Anforderung stellen
- Was ist bei der Arbeit mit Satzschablonen zu beachten?
    - Satzschablonen normieren das Vorgehen und schränken den Stil ein.
    - Satzschablonen sollten nicht als Methode vorgeschrieben sondern als
      Hilfsmittel angesehen werden.
