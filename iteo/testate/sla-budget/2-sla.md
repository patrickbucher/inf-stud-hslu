# Service Level Agreement

Service-Klassen:

- A: 24/7
- B: 8/5 (werktags von 9 Uhr morgens bis 17 Uhr abends)

## Web-Auftritt

- Service-Klasse: A
- Availability: 99%
- Performance: Ladezeit <3s
- BCP-Klasse
    - RTO: 24h (bis die Webseite wieder online ist)
    - RPO: 24h (bis die in Zwischenzeit getätigten Bestellungen
      wiederhergestellt sind)
- Monitoring & Reporting:
    - Performance-Messung: stündlich
        - wöchentliche Reports per E-Mail
    - Verfügbarkeitsmessung: minütlich
        - sofortige Warnung per SMS

## Helpdesk

- Service-Klasse: B
- Availability: 95%
- Performance: Wartezeit (in Warteschleife) höchstens 5 Minuten
- BCP-Klasse
    - RTO: 24h (bis das Helpdesk wieder verfügbar ist)
    - RPO: 48h (bis ein ausgefallener Mitarbeiter temporär ersetzt ist)
- Monitoring & Reporting:
    - Performance-Messung: monatlich
        - Anzahl bearbeitete Tickets
    - Verfügbarkeits-Messung: täglich
        - falls es einen ganzen Tag keine Anrufe gibt: Testanruf
