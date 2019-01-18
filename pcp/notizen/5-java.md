# Java 8

## Interfaces

### `default`-Methoden

Seit Java 8 können Interfaces auch Implementierungen vorgeben:

```java

interface Calculator {
    public default int calculate(int a, int b) {
        return a + b;
    }
}

// write custom implementation
Calculator multiplier = new Calculator() {
    public int calculate(int a, int b) {
        return a * b;
    }
};
System.out.println(multiplier.calculate(5, 4)); // 5 * 4 = 20

// use default implementation (since Java 8)
Calculator adder = new Calculator() {};
System.out.println(adder.calculate(5, 4)); // 5 + 4 = 9
```

Hintergrund: Wichtige Methoden für die Streams-API (`stream()`,
`parallelStream()`) werden direkt auf dem Interface `Collection` angeboten,
sodass keine bestehenden Interfaces in der Collections-API verändert werden
mussten (Rückwärtskompatibilität: _defender methods_).

### Mehrfachvererbung

Java unterstützt keine Mehrfachvererbung. Eine Java-Klasse kann aber mehrere
Interfaces implementieren. Geben zwei implementierte Interfaces die gleiche
`default`-Methode vor, muss die Methode mit dem zu verwendenden Interface
qualifiziert werden: 

```java
interface Adder {
    public default int calculate(int a, int b) {
        return a + b;
    }
}

interface Divider {
    public default int calculate(int x, int n) {
        return x / n;
    }
}

class AverageCalculator implements Adder, Divider {
    public int calculate(int a, int b) {
        return Divider.super.calculate(Adder.super.calculate(a, b), 2);
    }
}

System.out.println(new AverageCalculator().calculate(4, 6)); // 5
```

### `static`-Methoden

Ab Java 8 können Interfaces auch statische Methoden definieren:

```java
interface Calculator {
    public static int add(int a, int b) {
        return a + b;
    }
}

System.out.println(Calculator.add(4, 6)); // 10
```

## Lambda-Ausdrücke

Mithilfe von Lambda-Expressions kann die Implementierung eines Interfaces
vereinfacht werden:

```java
// prior to Java 8: implement interface
List<Integer> numbers = Arrays.asList(3, 4, 1, 2);
Collections.sort(numbers, new Comparator<Integer>() {
    public int compare(Integer a, Integer b) {
        return a - b;
    }
});
System.out.println(numbers); // [1, 2, 3, 4]


// since Java 8: lambda expression
List<Integer> moreNumbers = Arrays.asList(6, 8, 7, 5);
Collections.sort(moreNumbers, (a, b) -> a - b);
System.out.println(moreNumbers);
```

Die Datentypen des Rückgabewerts und der Argumente müssen nicht explizit
angegeben werden, da sie vom Kontext abgeleitet werden können (_type
inference_).

### Funktionale Interfaces

Ein Lambda-Ausdruck implementiert implizit ein _functional interface_; ein
Interface, das mit der Annotation `@FunctionalInterface` definiert ist. Ein
funktionales Interface verfügt über eine abstrakte Methode. Interface- und
Methodenname sind dabei nur informativer Natur, da sie im Code nicht
auftauchen. Das Package `java.util.function` gibt funktionale Interfaces vor.
Diese sind von einem bestimmten Grundtyp:

- Consumer: keine Rückgabe
- Function: Rückgabe beliebigen Typs
    - Predicate: Rückgabe eines Wahrheitswerts (`boolean`)
- Operator: Rückgabe vom Argument-Typ
- Supplier: Rückgabe ohne Eingabeargument

Weiter gelten folgende Namenskonventionen:

- Präfix «Bi» und «Binary» (für Operator) bei zwei Argumenten:
    - `BiPredicate<T, U>`
    - `BinaryOperator<T>`
- Präfix «Unary» für Operator mit einem Argument:
    - `UnaryOperator<T>`
- Elementarer Datentyp als Prefix:
    - `DoublePredicate`
    - `IntegerConsumer`
- «To» für Funktionen mit unterschiedlichen Argument- und Rückgabetypen:
    - `IntToLongFunction`

### Scoping

Lambda-Ausdrücke übernehmen den umschliessenden Scope, dürfen aber nur lesend
auf Variablen in diesem zugreifen. Man sagt, die lokalen Variablen müssen
_effectively final_ sein:

```java
int a = 1;
Arrays.asList(1, 2, 3).forEach(i -> {
    int b = a; // reading: allowed
    System.out.println(i + b);

    a = 2; // writing: compilation error!
    System.out.println(i + a);
});
```

### Methoden-Referenzen

Ab Java 8 können Methoden mit dem `::`-Operator referenziert werden. Dadurch
können bestehende Methoden wie Lambda-Ausdrücke verwendet werden. Es gibt vier
Arten von Methoden-Referenzen:

1. statische Methode:
    - `System::currentTimeMillis`
2. Instanzmethode eines Objekts:
    - `System.out::println`
3. Instanzmethode einer Klasse:
    - `String::length`
4. Konstruktor:
    - `String::new`

Anwendungsbeispiel:

```java
// print one element per line
Arrays.asList(1, 2, 3, 4).forEach(Sytem.out::println); 
```

Methodenreferenzen können mit funktionalen Interfaces referenziert werden:

```java
LongSupplier millis = System::currentTimeMillis;
Consumer<String> println = System.out::println;
ToIntFunction<String> length = String::length;
Supplier<String> newString = String::new;
```

## Streams

Idee: Anwendung von Funktionen auf Datenstrukturen; implizite Iteration.

- `forEach`: Funktion für jedes Element aufrufen
- `filter`: Filterung der Liste anhand einer Prädikatfunktion zur Erstellung einer neuen Sequenz (Teilmenge)
- `map`: Funktion auf jedes Element einer Sequenz anwenden, um Abbildung der Sequenz zu erhalten
- `reduce`: Einzelnes Resultat aus allen Elementen produzieren

Umsetzung:

- für generische Streams:
    - `interface java.util.stream.Stream<T>`
- für primitive Datentypen:
    - `IntStream`
    - `LongStream`
    - `DoubleStream` 

Stream erhalten:

- `Collection<T>.stream()` auf bestehender Collection
- `Arrays.stream(T[] array)`: für ein Array
- `Stream<T>.of(T... values`): generische Factory-Methode
- `IntStream.range(int startInc, int endExc)`: Factory-Methode für Sequenzen

### Intermediate/Terminal Operations

Es gibt zwei Arten von Stream-Operationen:

1. intermediate (lazy): erzeugt neuen Stream (`filter`, `map`)
2. terminal (eager): macht etwas anderes (`forEach`, `reduce`)

Intermediate-Operationen werden nicht direkt ausgewertet, sondern erst beim
Aufruf der ersten Terminal-Operation. Beispiel:

```java
Integer[] numbers = { 1, 2, 3, 4 };
int sumOfSquaredEvenNumbers = Arrays.stream(numbers)
    .filter(x -> x % 2 == 0)
    .map(x -> x * x)
    .reduce(0, (x, y) -> x + y);
```

(Da `reduce` immer mit zwei Werten arbeitet, benötigt es für den ersten
Durchlauf einen Initialwert. Dieser sollte ein neutrales Element sein, z.B. `0`
für eine Addition, `1` für eine Multiplikation und `""` für eine
`String`-Konkatenierung.)

Auswertungsreihenfolge:

1. `filter(1)`
1. `filter(2)`
1. `map(2)=2²`
1. `reduce(0,2²)`
1. `filter(3)`
1. `filter(4)`
1. `map(4)=4²`
1. `reduce(2², 4²)`

Die Sequenz wird nicht mehrmals durchiteriert. Stattdessen führt der Aufruf
einer terminal-Operation dazu, dass vorhergehende intermediate-Operationen
evaluiert werden müssen. Dies führt zu einer besseren Performance
(Optimierungen, Parallelisierung möglich) und zu einer einfacheren
Implementierung (kein Buffern von Zwischenresultaten nötig).

Wird eine terminal-Operation auf einen Stream angewendet, gilt dieser
anschliessend als konsumiert und darf nicht mehr verwendet werden.

### Stateful/Stateless Intermediate Operations

- Bei stateless-Operationen hängt das Ergebnis nur vom jeweiligen Stream-Element ab.
    - `filter`
    - `map`
- Bei stateful-Operations wird ein zusätzlicher Zustand benötigt
    - `limit`
    - `distinct`
    - `substream`
    - `sorted`

Stateless-Operationen sind einfacher handhab- und parallelisierbar. Können
`filter` und `map` in beliebieger Reihenfolge ausgeführt werden, blockiert z.B.
`sorted` den ganzen Stream, bis die Operation abgeschlossen ist.

### Short-Circuiting Operations

Die Stream-Abarbeitung kann vor dem Erreichen des letzten Elements gestoppt werden:

- intermediate:
    - Begrenzung: `limit(long maxSize)`
    - Überspringen: `skip(long n)`
- terminal:
    - Prädikate: `anyMatch()`/`noneMatch()`/`allMatch()`
    - Selektoren: `findAny()`/`findFirst()`

### Parallele Streams

Die Methode `Stream<T>.parallelStream()` gibt einen Stream zurück, dessen
Abarbeitung nach Möglichkeit nebenläufig vonstatten geht. Parallele und
sequenzielle Streams können ineinander umgewandelt werden, wozu das Interface
`BaseStream` folgende Methoden definiert:

- `boolean isParallel()`
- `S parallel()`
- `S sequential()`

Bei parallelen Streams ist die Auswertungsreihenfolge nicht deterministisch!

### Unendliche Streams

Da Streams _lazy evaluation_ ermöglichen, sind Konstrukte wie unendlich lange
Sequenzen möglich. Beispiel:

```java
double sum = DoubleStream.generate(Math::random))
    .skip(10_000)
    .limit(5_000)
    .sum();
System.out.println("average: " + sum / 5_000);
```

Ein (theoretisch) unendlich langer Stream mit Zufallszahlen im Bereich `0..1`
wird erstellt. Die ersten zehntausend Elemente werden übersprungen, dann wird
der Stream auf eine Länge von fünftausend Elementen eingeschränkt, und die
Elemente werden aufsummiert.

### `Optional<T>`

Da Methode `Stream<T>.reduce()` auf einem leeren Stream kein Ergebnis erzeugen
kann, wird nicht das eigentliche Resultat, sondern ein `Optional`
zurückgeliefert. Wichtige Methoden von `java.util.Optional` sind:

- `boolean isPresent()`: gibt an, ob ein Wert vorhanden ist
- `T get()`: gibt den Wert zurück, falls er vorhanden ist
- `T orElse(T value)`: gibt den Wert (falls vorhanden) oder den Parameter
  (falls kein Wert vorhanden) zurück
- `T ifPresent(Consumer<T> c)`: führt den Consumer-Lambda-Ausdruck aus, falls
  ein Wert vorhanden ist

Beispiel:

```java
List<Integer> list = Arrays.asList(1, 2, 3);
Optional<Integer> opt = list.stream().reduce((a, b) -> a + b);
if (opt.isPresent()) {
    System.out.println(opt.get());
}
System.out.println(opt.orElse(0));
opt.ifPresent(System.out::println);
```

## Weitere Java-Neuerungen

### Strings verketten

- `String.join(CharSequence delimiter, CharSequence... elements)`
    - Verkettet die Elemente zu einem durch `delimiter` getretten `String`
- `String.join(CharSequence delimiter, Iterable<? extends CharSequence> elements)`
    - Das gleiche mit einem Iterator
- `java.util.StringJoiner`: Strings per Builder-Pattern verketten
    - `StringJoiner(CharSequence delimiter, CharSequence prefix, CharSequence suffix)`: Konstruktor
    - `add(CharSequence element)`: Elemente hinzufügen

Beispiel:

```java
String a = String.join(" ", "Das", "ist", "ein", "Test");

List<String> l = Arrays.asList("Das", "ist", "ein", "Test");
String b = String.join(" ", l);

StringJoiner j = new StringJoiner(":", "(", ")");
j.add("Das");
j.add("ist");
j.add("ein");
j.add("Test");
```

### Komparatoren

Neue Methoden auf `Comparator`:

- `static Comparator<T> naturalOrder()`: Erstellt einen `Comparator` zur natürlichen Sortierung
- `Comparator<T> reversed()`: Erstellt  einen `Comparator` zur umgekehrt natürlichen Sortierung

Beispiel:

```java
// natural order
Comparator<String> cmp = Comparator.naturalOrder();
cmp.compare("a", "b"); // -1
cmp.compare("b", "a"); // 1
cmp.compare("a", "a"); // 0

// reversed natural order
Comparator<String> rev = cmp.reversed();
rev.compare("a", "b"); // 1
rev.compare("b", "a"); // -1
rev.compare("a", "a"); // 0
```

- `Comparator<T> thenComparing(Comparator<? super T> other)`: Verkettet zwei `Comparator`s
- `static Comparator<T> nullsLast()/nullsFirst()`: Definiert die Einordnung von
  `null`-Werten

Beispiel:

```java
Comparator<String> fullCmp = Comparator
    .comparingInt(String::length)
    .thenComparing(String.CASE_INSENSITIVE_ORDER);
fullCmp.compare("foo", "goo"); // -1
fullCmp.compare("foobar", "foo"); // 1

Comparator<String> natural = Comparator.naturalOrder();

Comparator<String> nullsFirst = Comparator.nullsFirst(natural);
nullsFirst.compare(null, "b"); // -1
nullsFirst.compare("a", "b"); // -1
nullsFirst.compare("b", null); // 1

Comparator<String> nullsLast = Comparator.nullsLast(natural);
nullsLast.compare(null, "b"); // 1
nullsLast.compare("a", "b"); // -1
nullsLast.compare("b", null); // -1
```

### `CompletableFuture`

Mithilfe von einem `CompletableFuture` lassen sich zeitaufwändige Aufgaben
mithilfe von Lambda-Ausdrücken nebenläufig ausführen, ohne den Hauptthread zu
blockieren. Durch die Kombination von `supplyAsync`, `thenApplyAsync` und
`thenAcceptAsync` lassen sich Zwischenergebnisse einfach von einem Thread zum
nächsten weitergeben.

1. `static CompletableFuture<T> supplyAsync(Supplier<T> supplier)`:
   Initialisierung, stellt «Problem» zur Verfügung (`Supplier`)
2. `CompletableFuture<T> thenApplyAsync(Function<? super T, ?extends U> fn)`:
   Berechnung, führt das Problem in eine Lösung über (`Function`)
3. `CompletableFuture<Void> thenAcceptAsync(Consumer<? super T> action)`:
   Verwertung, verbraucht Lösung (`Consumer`)

Beispiel:

```java
import java.util.concurrent.CompletableFuture;

public class Main {

    // task1 -> "42" -> task2 -> "the answer is 42"
    public static void main(String[] args) {
        CompletableFuture<String> task1 = CompletableFuture.supplyAsync(() -> {
            sleep(1000);
            System.out.print("task1");
            return "42";
        });
        CompletableFuture<String> task2 = task1.thenApplyAsync((String s) -> {
            sleep(1000);
            System.out.print("task2");
            return "the answer is " + s;
        });
        task2.thenAcceptAsync((String s) -> {
            sleep(1000);
            System.out.print(s);
        });
        for (int i = 0; i < 10; i++) {
            System.out.print(".");
            sleep(500);
        }
        System.out.print("done");
    }

    private static void sleep(long millis) {
        try {
            Thread.sleep(millis);
        } catch (InterruptedException iEx) {
            iEx.printStackTrace();
        }
    }
}
```

Ausgabe:

    ..task1...task2..the answer is 42...done

### Kollektoren

Die Methode `Stream.collect()` ist ein Spezialfall von `reduce()`. Sie reduziert
die Elemente eines Streams mithilfe einer `Collector`-Implementierung. Die
Klasse `java.util.stream.Collectors` bietet verschiedene Möglichkeiten, u.a.:

- `String Collectors.joining()`: Elemente als Strings konkatenieren
- `String Collectors.joining(CharSequence delimiter)`: Elemente mit einem
  Delimiter als Strings konkatenieren
- `List<T> Collectors.toList()`: Elemente in einer Liste sammeln
- `List<T> Collectors.toCollection(Supplier collectionFactory)`: Elemente in
  einer Collection sammeln (als `collectionFactory` dient z.B. `TreeSet::new`)
- `Map<K, V> Collectors.groupBy(Function<T, K> classifier)`: Elemente nach
  einem Kriterium gruppieren (als `classifier` dient eine Methode von `T` mit
  Rückgabetyp `K`)

Beispiel:

```java
List<String> ugly = Arrays.asList("foo", "alice", "bar", "dilbert", "qux", "boss");
String nice = ugly.stream()
    .filter(s -> s.length() > 3)
    .map(s -> s.substring(0, 1).toUpperCase() + s.substring(1, s.length()))
    .collect(Collectors.joining(", "));
System.out.println(nice); // Alice, Dilbert, Boss
```

## Funktionales Denken

Analogie: Sowie der Garbage Collector den Programmierer vom Memory Management
befreit, befreit die funktionale Programmierung den Programmierer von
Implementierungsdetails (implizite statt explizite Funktion, Zwischenspeichern
von Ergebnissen in Variablen usw.). Der Programmierer arbeitet auf einer
höheren Abstraktionsebene: Der Code spielt sich näher an der Problemebene als
auf der Computer-Ebene (Variablen, Schleifen) ab. Viele Verarbeitungsprobleme
lassen sich in drei Kategorien einteilen:

- filter: Einschränkung der Problemmenge
- transform/map: Überführung einer Eingabe in eine Ausgabe
- convert/reduce: Zusammenführen der Teillösungen zu einer Gesamtlösung

Wie man in der Physik zwischen potenzieller und kinetischer Energie
unterscheidet, kann man in Java zwischen Streams und Collections unterscheiden:
Ein Stream ist noch _keine_ Sammlung von Elementen, kann aber schnell zu einer
werden.
