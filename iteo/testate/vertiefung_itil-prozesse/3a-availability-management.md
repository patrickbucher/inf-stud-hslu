# Availability Management

## Ziele

- Das _Verfügbarkeitsniveau_ vereinbarter Services soll gewährleistet werden.
- Dabei geht es nicht nur um aktuelle Services, sondern auch um die _Planung_
  und _Realisierung_ zukünftiger Anforderungen.
- Die Infrastruktur soll _effizient_ bereitgestellt werden, sodass weder Unter-
  noch Überkapazitäten auftreten.

## Begriffe

- Das _Availability Management Information System_ (AMIS) dient
    - zur zentrale Speicherung aller Informationen und Daten zum Availability
      Management
    - und als Grundlage für die Erstellung von Berichten und
      Optimierungsmassnahmen.
- Der _Availability Plan_ definiert Ziele und Massnahmen im Bezug auf die
  Verfügbarkeit. Der Zeithorizont sollte ein bis zwei Jahre betragen. Er
  beinhaltet:
    - vereinbarte Verfügbarkeit/tatsächliche Verfügbarkeit
    - Massnahmen zur Verbesserung der Verfügbarkeit
    - Bewertungen erwarteter Änderungen auf die Verfügbarkeit
    - Auswirkungen geplanter neuer Services auf die Verfügbarkeit
    - Hinweise auf neue Technologien
- Mithilfe des _erweiterten Incident Lifecycle_ sollen die Auswirkungen auf
  Incidents (Vorfälle) auf die Serviceverfügbarkeit reduziert werden. Relevant
  sind folgende Messgrössen:
    - MTBF: Mean Time Between Failures (Uptime)
    - MTRS: Mean Time to Restore Service (Downtime)
    - MTBSI: Mean Time Between System Incidents (durchschnittliche Zeit zwischen
      den Vorfällen)
- Wartbarkeit (_Maintainability_)
- Zuverlässigkeit (_Reliability_)
- Servicefähigkeit (_Serviceability_)

## Aktivitäten

- proaktive Tätigkeiten
    - Planung
    - Risikomanagement
    - Reviews
- reaktive Tätigkeiten
    - Monitoring
    - Analyse von Messdaten
    - Untersuchung von Serviceunterbrechungen
    - Dokumentation (AMIS)

Bei der Planung ist es wichtig, die vitalen Business-Funktionen (VBF) zu
definieren. Je kritischer ein Geschäftsprozess, desto höher ist die
Verfügbarkeitsanforderung. Die Verfügbarkeitsziele werden anhand folgender
Grössen definiert:

- High Availability: Reduktion der Fehlerauswirkungen mithilfe von Redundanz
- Fault Tolerance: Weiterbetrieb des Service trotz Teilausfällen
- Continuous Operations: Massnahmen zur Reduktion der Downtime
- Continuous Availability: Kombination von Massnahmen und Technologien zur
  Annäherung an 100%-Verfügbarkeit

## Rollen

Der _Availability Manager_ trägt folgende Verantwortungen:

- Sicherstellen vereinbarter Servicequalität
- Planung der Verfügbarkeit neuer und veränderter Services
- Unterstützung bei der Diagnose bei Vorfällen mit Bezug auf die Verfügbarkeit
- Bestimmung der Anforderungen neuer Komponenten bezüglich Zuverlässigkeit,
  Wartbarkeit und Servicefähigkeit
- Monitoring der aktuellen Verfügbarkeit

## Key-Performance-Indikatoren (KPI)

- Prozentuale Serviceverfügbarkeit (möglichst hoch)
- Dauer und Häufigkeit der Nichtverfügbarkeit (möglichst tief)
- Differenz vereinbarte und tatsächliche Verfügbarkeit (möglichst tief)
- Verringerung der MTRS (möglichst tief)
- Kosten, die aufgrund von Nichtverfügbarkeit anfallen (möglichst tief)
- Lieferung von Management-Reports (möglichst zeitgerecht)

## Herausforderungen

- Die wirklichen Geschäftsanforderungen im Bezug auf die Verfügbarkeit sind
  schwierig aufzunehmen.
- Es ist eine Abstimmung über alle Fachbereiche hinweg erforderlich, da die
  Manager der einzelnen Bereiche unterschiedliche Vorstellungen haben können.
- Der Begriff „Verfügbarkeit“ muss zunächst definiert werden:
    - Welche Antwortzeiten und welche Funktionen sind nötig, damit der Service
      als „verfügbar“ gilt?
    - Wo und wie werden Verfügbarkeit und Performance gemessen?
    - Ist eine partielle Nichtverfügbarkeit definiert? Wie?
