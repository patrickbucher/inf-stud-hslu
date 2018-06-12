# Verteilte Systeme

## Socket-Kommunikation

- Netzwerkschichten:
    - Applikationsschicht (application layer): HTTP, SMTP, FTP, DNS
    - Transportschicht (transport layer):
        - Transmission Control Protocol (TCP): verbindungsorientiert,
          zuverlässig
        - User Datagram Protocol (UDP): verbindungslos, unzuverlässig
    - Internetschicht (internet layer): Internet Protocol (IP)
    - Netzwerkschickt (network layout): Ethernet, WLAN, DSL, UMTS, LTE
- Begriffe:
    - Host: An ein Netzwerk angeschlossener Computer mit netzwerkweit
      eindeutiger IP-Adresse
    - Socket: Kommunikationsendpunkt, durch IP-Adresse und Port-Nummer
      definiert
    - Server (Diener): Dienstleister, der Daten/Ressourcen zur Verfügung
      stellt; umfasst einen oder mehrere Computer
        - Software: Server-Programm, das einen Dienst implementiert
        - Hardware: Server-Computer, auf dem ein oder mehrere Server-Programme
          laufen
    - Client (Kunde): Dienstnehmer, der Dienste von Servern verwendet

### Java Sockets

Package `java.net.*` mit Klassen:

- `InetAddress`
    - `static InetAddress getByName(String host)`: IP-Adresse von Host anhand
      Namen finden
    - `String getHostName()`: liefern Hostnamen
    - `String getHostAddress()`: liefert IP-Adresse
    - `String getCanonicalHostName()`: liefert voll qualifizierten Hostnamen
      (mit Domäne)
    - `boolean isReachable(int msec)`: prüft, ob ein Host innerhalb eines
      Timeouts antwortet
    - `static InetAddress getLocalHost()`: IP-Adresse des lokalen Hosts finden
    - `boolean isSiteLocalAddress()`: Prüft, ob es sich um den lokalen Host
      handelt
- `Socket`
    - `Socket(String host, int port)`: Socket-Verbindung zu `host:port`
      erstellen
    - `OutputStream getOutputStream()`: zum schreibenden Zugriff
    - `InputStream getInputStream()`: zum lesenden Zugriff
- `ServerSocket`
    - `ServerSocket(int port)`: Socket, der auf `port` hört
    - `ServerSocket(int port, int backlog, InetAddress addr)`: mit Grösse der
      Warteschlange und spezifischer IP-Adresse
    - `Socket accept()`: Verbindung entgegennehmen (blockierend)
- `NetworkInterface`
    - `static Enumeration<NetworkInterface> getNetworkInterfaces()`
    - `String getDisplayName()`
    - `Enumeration<InetAddress> getInetAddresses()`

### Socket-Lebenszyklus

1. Server: Socket erzeugen und an lokalen Port binden
2. Server: Mit `accept` auf eingehende Verbindung warten
3. Client: Verbindung mit Server herstellen (mit IP-Adresse und Port-Nummer)
4. Client/Server: Daten über Socket lesen/schreiben
5. Client: Verbindung schliessen
6. Server: Socket schliessen

## Serialisierung

## Message-Passing

## Verteilung & Kommunikation: RMI

## Uhrensynchronisation

## Verteilung: Data Grid
