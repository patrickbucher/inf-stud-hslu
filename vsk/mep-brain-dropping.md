Netzwerkkommunikation

- Was ist ein verbindungsorientiertes, zuverlässiges Protokoll? Beispiel?
    - Es wird vor dem Austausch von Datenpaketen eine Verbindung aufgebaut.
    - Verlorengegangene Pakete werden erneut angefordert/gesendet und in die
      richtige Reihenfolge gebracht.
- Was ist ein verbindungsloses, unzuverlässiges Protokoll? Beispiel?
    - Baut keine Verbindung auf, sondern schickt direkt ein Datenpaket.
    - Garantiert nicht, dass ein Paket ankommt, oder in welcher Reihenfolge und
      über welche Route das passiert.
- Wo verwenden Sie im Projekt ein verbindungsorientiertes Protokoll?
    - TCP: Kommunikation zwischen `logger-component` und `logger-server`
    - RMI: implizit (funktioniert über TCP)
- Beschrieben Sie das Protokoll mithilfe der Projektdokumentation.
    - individuell

Lamport-Uhr

- Was ist der Zweck einer Lamport-Uhr?
    - Ordnet Ereignissen einen aufsteigenden Zeitstempel zu.
    - Gibt Auskunft über die Reihenfolge von Ereignissen.
- Was muss lokal passieren, wenn ich eine Nachricht mit einem Timestamp
  bekomme, der in der Zukunft liegt?
    - Der lokale Zähler muss erhöht werden, sodass er grösser ist als der von
      der empfangenen Nachricht.
- Was muss lokal passieren, wenn ich eine Nachricht mit einem Timestamp
  bekomme, der in der Vergangenheit liegt?
    - Der Timestamp der Nachricht muss erhöht werden.
- Einsatz einer Lamport-Uhr im Projekt: wo sinnvoll, wie möglich?
    - Log-Meldungen zwischen Client und Server fortlaufend durchnummerieren, um
      die Reihenfolge der Nachrichten nachvollziehen zu können.
    - Problematisch, da bei Log-Ereignissen nicht nur die Abfolge, sondern auch
      die absolute Zeit von Interesse ist.

Schnittstelle

- Was ist die Breite einer Schnittstelle?
    - Java Interface: Anzahl Methoden (und Länge der Parameterliste?)
- Wo in ihrem Projekt verwenden Sie Schnittstellen? Zeigen Sie ein Beispiel
  anhand ihrer Dokumentation.
    - RMI: Observer-Pattern/Push-Prinzip (`subscribe(viewer)`, `push(message)`)
- Wie könnte man das Problem mit einem anderen Interface-Design lösen?
    - Polling über RMI (`fetch_messages()`)
- Wie würde sich diese Änderung auf die Breite der Schnittstelle auswirken?
    - Statt zwei gäbe es nur noch eine Schnittstelle/Methode. Die Breite würde
      abnehmen.
