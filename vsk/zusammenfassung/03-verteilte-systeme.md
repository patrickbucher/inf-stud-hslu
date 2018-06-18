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

Serialisierung: Objekte in eine persistente Form bringen, damit der
Objektzustand später wiederhergestellt werden kann

- Anforderungen an Objektpersistenz
    - Transparenz: gleiche Handhabung von persistenten und transienten Objekten
      durch den Entwickler
    - Interoperabilität: Verwendung persistenter Objekte unabhängig von
      Laufzeitumgebung
    - Wiederauffindbarkeit: Auffinden von persistenten Objekten ohne explizite
      Suche (transparent)
- Grundidee: Umwandlung eines  Objekts in Bytestrom zur persistenten
  Abspeicherung

### Serialisierung in Java

- Java-Serialisierungsverfahren: Ablauf und Umfang
    1. Metadaten (voll qualifizierter Klassenname, Signatur, Versionsnummer) in
    den Bytestrom schreiben
    2. Rekursive Serialisierung nicht-statischer, nicht-transienter Attribute
    (`private`, `protected`, `public`) und aus Oberklassen geerbte Attribute
    3. Zusammenfassen der entstandenen Byteströme zu einem bestimmten Format
    - alle verwendeten Klassen müssen vollständig im `CLASSPATH` vorliegen!
- Objektserialisierung in Java
    - Java Object Serialization (JOS): binäres Format
    - Java Bean Persistence (JBP): Abspeicherung von Java Beans als XML
    - Java Architecture for XML Binding (JAXB): Abbilden von Objektstrukturen
      auf XML
- Standard-Serialisierung: Java-Klassen, Interfaces und Methoden
    - Idee: Dekoration eines Input- oder Output-Streams (`FileInputStream`,
      `BufferedOutputStream`, etc.)
    - Interface `java.io.ObjectOutput`
        - `void ObjectOutputStream.writeObject(Object obj)`: rekursives
          Abarbeiten des Objekt-Parameters
    - Interface `java.io.ObjectInput`
        - `Object ObjectInputStream.readObject()`: Aufbauen der
          Objekthierarchie aus Bytestrom (Cast notwendig)
    - Marker-Interface `java.io.Serializable` (keine Methoden): muss
      implementiert werden, damit Objekte der jeweiligen Klasse serialisiert
      werden können
        - dadurch automatische Serialisierbarkeit von erbenden Klassen gegeben
    - spezielle Methoden Auf dem jeweiligen Objekt:
    - `Object readResolve()`: erlaubt Manipulation des deserialisierten Objekts
        - zur Wiederherstellung transienter Objekte
        - zum Garantieren der Eindeutigkeit bei Singleton-Objekten
    - `void writeObject(final ObjectOutputStream oos)`
        - eigens definierte Serialisierung anhand von Bytestrom
        - Aufruf von `oos.defaultWriteObject()` zum Erweitern der
          Serialisierung
    - `void readObject(final ObjectInputStream ois)`
        - eigens definierte Deserialisierung anhand von Bytestrom
        - Aufruf von `ois.defaultReadObject()` zum Erweitern der
          Deserialisierung
- Klonen von beliebigen Objekten per Serialisierung und anschliessender
  Deserialisierung
    - `ByteArrayOutputStream` $\rightarrow$ `ObjectOutputStream` $\rightarrow$
      `ByteArrayInputStream` $\rightarrow$ `ObjectInputStream`
- Transiente Attribute: für «berechnete», zwischengespeicherte Felder
    - Schlüsselwort `transient`: `private transient String fullName;`
    - Deserialisierung: Implementierung der Methode `readResolve()` 
- Serialisierung und Vererbung
    - private Felder nicht-serialisierbarer Oberklassen werden nicht
      serialisiert
    - Deserialisierung: Suche und Aufruf des parameterlosen Konstruktors der
      ersten nicht-serialisierbaren Oberklasse: es muss ein solcher existieren!
    - Implementierung von `readObject()` und `writeObject()` muss sich um
      Zustand der Oberklasse kümmern
    - Verhinderung von Serialisierung bei Unterklassen durch Überschreibung von
      `writeObject()` und `readObject()` möglich
- Versionierung: aufgrund langer Zeitspannen zwischen Serialisierung und
  Deserialisierung mit wechselnden Umgebungen (Laufzeitumgebung,
  Softwareversion) unbedingt nötig
    - Angabe über Attribut: `public static long serialVersionUID = ...`;
    - Andernfalls automatische Berechnung eines Hash-Werts zur Laufzeit anhand
      verschiedener Klassenparameter (nicht empfohlen).
    - Neuerstellung der `serialVersionUID` bei inkompatiblen Änderungen der
      Klasse.
    - Ein Objekt kann nur deserialisiert werden, wenn seine Klasse die gleiche
      Version hat, wie sie die zugrundeliegende Klasse des serialisierten
      Objekts bei der Serialisierung hatte.

## Message Passing

Message Passing: Kommunikationsparadigma zum Versenden einer Nachricht von
einem Sender zu einem oder zu mehreren Empfängern.

- Arten von Nachrichten: (Remote) Method Invocation, Signale, Datenpakete
- Designentscheide bei der Entwicklung eines Message-Passing-Systems:
    1. zuverlässige oder unzuverlässige Nachrichtenübertragung
    2. garantierte oder beliebige Übertragungsreihenfolge der Nachrichten
    3. Sender-Empfänger-Beziehungen:
        - Unicast: ein Sender, ein Empfänger
        - Multicast/Broadcast: ein Sender, mehrere Empfänger
        - Client-Server: mehrere Sender, ein Empfänger
        - All-to-all: mehrer Sender, mehrere Empfänger
    4. synchrone oder asynchrone Kommunikation
        - synchron: Sender blockiert, bis der Empfänger die Nachricht
          entgegengenommen hat (Telefonie, Instant Messaging)
        - asynchron: Sender führt seine Aufgabe nach Versenden einer Nachricht
          fort (E-Mail, Diskussionsforum)
    5. persistente oder transiente Kommunikation
        - persistent: Nachricht bis zur Bereitschaft des Empfängers
          zwischenspeichern (E-Mail)
        - transient: Nachricht während Ausführung von sendender und
          empfangender Applikation zwischengespeichert (Router, Socket)
- Kommunikationsformen: TODO: Seite 8 bis 10
    - persistent und asynchron
    - persistent und synchron
    - transient und asynchron
    - transient und synchron (empfangsbasiert)
    - transient und synchron (auslieferungsbasiert)
    - transient und synchron (antwortbasiert)
- Message Passing Interface (MPI): TODO: Seite 11

### Nachrichtenverarbeitung

- Definition _Nachricht_: TODO: Seite 13 ff.

- Entwurfsmuster _Fabrikmethode_ und _Prototyp_ im entsprechenden Kapitel zusammenfassen

### Protokollarten

- fixe und adaptive Protokolle: Seite 21 ff. bzw. 25 ff.

## Verteilung & Kommunikation: RMI

## Uhrensynchronisation

## Verteilung: Data Grid
