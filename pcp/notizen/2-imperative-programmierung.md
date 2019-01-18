# Imperative Programmierung

- Grundidee der imperativen Programmierung: Programm als Sequenz von
  Anweisungen mit vorgegebenem Kontrollfluss
    - Verzweigungen: `if`/`else`, `switch`/`case`
    - Schleifen: `for`, `while`, `do`/`while`
    - Sprung: `goto`

## Strukturierte Programmierung
- Strukturierte Programmierung: Imperative Programmierung ohne `goto`
    - Dijkstra: [Go To Statement Considered Harmful](https://homepages.cwi.nl/~storm/teaching/reader/Dijkstra68.pdf),
      [A Case against the GO TO Statement](https://www.cs.utexas.edu/users/EWD/transcriptions/EWD02xx/EWD215.html) 
    - Mit der hemmungslosen Verwendung von `goto` (_unbridled use of the go to
      statement_) wird es sehr schwierig nachzuvollziehen, wie weit ein Prozess
      bereits fortgeschritten ist.

## Prozedurale Programmierung

- Prozedurale Programmierung: Strukturierte Programmierung mit
  Unterprogrammen/Funktionen/Routinen/Prozeduren -- und lokalem
  Gültigkeitsbereich von Variablen
    - Auch Schleifen wären theoretisch überflüssig, da mit rekursiven Funktion
      zu bewerkstelligen. Sie sind aber syntaktisch äusserst praktisch und
      hatten sich damals schon eingebürgert.
    - Ohne lokalen Gültigkeitsbereich von Funktionsparametern wäre Rekursion
      nur sehr eingeschränkt möglich.

## Zusammengesetzte Datentypen

Strukturen (C): fassen eine Liste von  Variablen zusammen

```C
struct point {
    int x;
    int y;
};

struct point p;
p.x = 1;
p.y = 2;

typedef struct {
    char[100] first_name;
    char[100] last_name;
    int year_of_birth;
} person;

person tom; // typedef: no `struct` needed
tom.first_name = "Thomas";
tom.last_name = "Miller";
tom.year_of_birth = 1964;
```

- Abstrakte Datentypen (ADT: Abstract Data Type): Semantik vorgegeben,
  Implementierung frei
    - Stack: Last In, First Out (LIFO)
        - `init`: leeren Stack initialisieren
        - `push`: Element auf Stack ablegen
        - `top`: letztes Element zurückgeben
        - `pop`: letztes Element vom Stack nehmen
        - `print`: alle Elemente ausgeben
        - Ein Stack kann in C mithilfe eines Arrays oder einer verketteten
          Liste implementiert werden. Die Schnittstelle wäre für beide
          Implementierung gleich, die Laufzeiteigenschaften (Performance,
          Arbeitsspeicherbedarf) könnten Unterschiede aufweisen.
    - Queue: First In, First Out
    - Weitere: Matrix, Map, Ring Buffer
    - strukturierte/prozedurale Programmierung: Datenstrukturen und Funktionen
      voneinander getrennt (C: `struct` und Funktionen)
    - objektorientierte Programmierung: Datenstrukturen und Funktionen in einem
      Gefäss zusammengefasst (Java: Klasse mit Eigenschaften und Methoden)
        - Eigenschaften bilden den Zustand, Methoden das Verhalten ab
        - Sichtbarkeit: Einschränkung des Zugriffs (`public`, `protected`,
          default, `private`) auf Klassen- und Paketstufe
    - Java als Erweiterung von C um folgende Konzepte:
        - Klassen und Instanzen: `class`, `extends`, `super`, `instanceof`,
          `this`, `new`
        - Interfaces: `interface`, `implements`
        - Packages: `package`, `import`
        - Sichtbarkeit: `public`, `protected`, default, `private`
        - Exception Handling: `try`, `catch`, `finally`, `throw`, `throws`
    - Java-Referenzen als Einschränkung von C-Zeigern: Keine Zeigerarithmetik!
