# Racket (Scheme)

- Racket (Scheme): deklarative, funktionale Programmiersprache
- homoikonisch: selbstrepräsentierbar (Programme sind Datenstrukturen derselben
  Sprache)
- Auf LISP basierend: List Processing (jedes Programm ist eine Liste)
- Funktionen stehen im Zentrum
    - keine Seiteneffekte (referenzielle Transparenz)
    - First-Class Funktionen: Funktionen als gleichberechtigte Datenobjekte
    - Lösen von Aufgaben mittels Dekomposition des Problems und Komposition der
      Teillösungen zu einer Gesamtlösung

## Grundlagen

### Form

```scheme
(<operator> <operand 1> <operand 2> ... <operand n>)
```

- in runde Klammern eingeschlossen
- Präfix-Schreibweise: zuerst Operator (bzw. Funktion), dann Operanden
- nicht festgelegte Reihenfolge
- beliebig verschachtelbar
- paarweise Klammern

### Auswertungsregeln

Ausdrücke geben folgende Werte zurück:

- selbstauswertender Ausdruck: Wert der Zahl/des boolschen Ausdrucks
- Name: Wert, der in der jeweiligen Umgebung mit diesem Namen assoziiert wird
- eingebauter Operator: Sequenz der Instruktionen, welche entsprechende
  Operation durchführen
- Kombination:
    - Unterausdrücke in beliebiger Reihenfolge
    - Funktion des linksstehenden Unterausdrucks (Operator) auf Operanden
      anwenden
- Form mit Schlüsselwort: Funktion auf Operanden anwenden

### Definition von Namen

```scheme
(define <identifier> <expression>)
(define PI 3.1459)
```

- `identifier` ist ein beliebiger Name, der auch Sonderzeichen enthalten kann
    - Unterscheidung: case-sensitive
- `expression` kann ein beliebiger Ausdruck sein (Konstante, Variable,
  Funktionsaufruf)

### Definition von Funktionen

```scheme
(define (<identifier> <formal parameters>)
    <expression>)
(define (power-of-two (x))
    (* x x))
```

### Auswertung von Funktionen

- strikte Auswertung: alle Argumente werden vor dem Funktionsaufruf ausgewertet
- Bedarfsauswertung (_lazy evalutation_): Argumente werden unausgewertet
  übergeben; Auswertung erfolgt erst, wenn die Werte benötigt werden
    - potenziell zeitsparend, da Auswertungen vermieden werden können
    - Kurzschlussauswertung: Auswertung logischer Ausdrücke kann vorzeitig
      abgebrochen werden

## Atomare Ausdrücke

- Selbstauswertende Ausdrücke: Bezeichner und Bezeichnetes sind das Gleiche
- Zahlen (selbstauswertend)
    - Ganzzahlen (`integer`): 23
    - Rationale Zahlen (`rational`): ½, ¼ oder 0.5, 0.25
    - Reelle Zahlen (`real`): ±∞
    - Irrationale Zahlen: `pi` = `#3.14159`
    - Komplexe Zahlen (`complex`): √(-2)
- Boolsche Werte: `true` und `false` (selbstauswertend)
    - `#t` → `true`
    - `#f` → `false`
- Operatoren für ganze Zahlen:
    - `+`: Addition
        - `(+ 3 -2 5)` → `6`
    - `-`: Subtraktion
        - `(- 31 17 7 5)` → `2`
    - `*`: Multiplikation 
        - `(* 2 3)` → `6`
    - `/`: Division
        - `(/ 128 4 2 2 4)` → `2`
    - `quotient`: Ganzzahl-Division
        - `(quotient 10 3)` → 3
    - `remainder`: Divisionsrest
        - `(modulo -10 3)` → `1`
    - `expt`: Potenz
        - `(expt 2 10)` → `1024`
    - `modulo`: Modulo
        - `(modulo -10 3)` → `2`
    - `abs`: Absolutwert 
        - `(abs -3)` → `3`
    - `max`: Maximum
        - `(max 3 6 1 9 6)` → `9`
    - `min`: Minimum
        - `(min 3 6 1 9 6)` → `1`
    - `lcm`: kgV (kleinstes gemeinsames Vielfaches)
        - `(lcm 30 4)` → `60`
    - `gcd`: ggT (grösster gemeinsamer Teiler)
        - `(gcd 1024 768)` → `256`
    - `numerator`: Zähler des einfachst möglichen Bruchs
        - `(numerator 7.25)` → `4`
    - `denominator`: Nenner des einfachst möglichen Bruchs
        - `(denominator 7.25)` → `29.0`
- Operatoren für reelle und komplexe Zahlen:
    - `exp`: Exponentialfunktion (Potenz zur Basis `e`)
        - `(exp 1)` → `2.718281828459045`
    - `sin`: Sinus
        - `(sin 1.5)` → `0.9974949866040544`
    - `cos`: Cosinus
        - `(cos 1.5)` → `0.0707372016677029`
    - `tan`: Tangens
        - `(tan 1)` → `1.5574077246549023`
    - `expt`: Potenz
        - `(expt 1.5 2.5)` → `2.7556759606310752`
    - `log`: Logarithmus zur Basis `e`
        - `(log (exp 1))` → `0`
    - `sqr`: Quadrat
        - `(sqr 4.1)` → `16.81`
    - `sqrt`: Quadratwurzel
        - `(sqrt 17.3)` → `4.159326868617084`

## Bedingte Ausdrücke

### Vergleichsoperatoren

- `=`: gleich
    - `(= 5 5)` → `#t`
    - `(= 3 4)` → `#f`
- `>`: grösser als
    - `(> 7 2)` → `#t`
    - `(> 2 7)` → `#f`
    - `(> 9 7 5 3 1)` → `#t`
    - `(> 9 7 5 3 3)` → `#f`
- `<`: keliner als
    - `(< 2 5)` → `#t`
    - `(< 5 2)` → `#f`
- `>=`: grösser/gleich
    - `(>= 5 5)` → `#t`
    - `(>= 3 4)` → `#f`
    - `(>= 9 7 5 3 3)` → `#t`
- `<=`: kleiner/gleich
    - `(<= 5 5)` → `#t`
    - `(<= 5 3)` → `#f`

### Logische Verknüpfungen

- Sequenzielle Auswertung mit Kurzschlussverfahren
- Fehler, wenn ein Ausdruck weder `true` noch `false` ergibt
- Auswertung: von links nach rechts
- `and`: UND-Logik
    - Kurzschluss: `false`, bei erstem Teilausdruck, der zu `false` evaluiert
    - `(and (> 5 3) (< 1 9))` → `#t`
    - `(and (> 5 3) (= 1 9))` → `#f`
    - `(and (> 5 3) (+ 1 9))` → `Error`
- `or`: OR-Logik
    - Kurzschluss: `true`, bei erstem Teilausdruck, der zu `true` evaluiert
    - `(or (> 7 9) (< 1 9))` → `#t`
    - `(or (> 3 5) (= 1 9))` → `#f`
    - `(or (> 3 5) (+ 1 9))` → `Error`
- `not`: Logische Umkehrung
    - `(not (> 1 3))` → `#t`
    - `(not (> 3 1))` → `#f`
- `boolean=?`: Boolsche Gleichheit (2 Operanden)
    - `(boolean=? (> 3 1) (< 2 5))` → `#t` (beide `true`)
    - `(boolean=? (> 1 3) (< 5 2))` → `#t` (beide `false`)
    - `(boolean=? (> 3 1) (< 5 2))` → `#f` (`true` und `false`)

Mit dem Kurzschlussverfahren lassen sich Fehler vermeiden:

```scheme
> (define x 0)
> (and (not (= x 0)) (< (/ 2 x) 1))
#f
```

Ist `x` gleich `0`, wird die Division nicht ausgewertet. Wird die Reihenfolge
der `and`-Operanden umgedreht, gibt es einen Fehler:

```scheme
> (define x 0)
> (and (< (/ 2 x) 1) (not (= x 0)))
; /: divison by zero
```

### Prädikatfunktionen

Für Zahlen:

- `integer?`: ganze Zahl?
    - `(integer? (/ 4 2)` → `#t`
    - `(integer? (/ 4 3)` → `#f`
- `real?`: reelle Zahl?
    - `(real? (sqrt 2))` → `#t`
    - `(real? (sqrt -2))` → `#f`
- `rational?`: rationale Zahl?
    - `(rational? (/ 4 3)` → `#t`
    - `(rational? (sqrt -2))` → `#f`
- `complex?`: komplexe Zahl?
    - `(complex? (sqrt -2))` → `#t`
    - `(complex? (sqrt 2))` → `#f`
- `odd?`: ungerade?
    - `(odd? 3)` → `#t`
    - `(odd? 2)` → `#f`
- `even?`: gerade?
    - `(even? 4)` → `#t`
    - `(even? 3)` → `#f`
- `negative?`: negativ?
    - `(negative? -3)` → `#t`
    - `(negative? 3)` → `#f`
- `positive?`: positiv?
    - `(positive? 3)` → `#t`
    - `(positive? -3)` → `#f`
- `zero?`: null?
    - `(zero? 0)` → `#t`
    - `(zero? 0.0001)` → `#f`
- `exact?`: exakt?
    - `(exact? (sqrt 4))` → `#t`
    - `(exact? (sqrt 2))` → `#f`
- `inexact?`: nicht exakt?
    - `(inexact? (sqrt 2))` → `#t`
    - `(inexact? (sqrt 4))` → `#f`

Für Typen:

- `boolean?`
- `number?`
- `char?`
- `string?`
- `symbol?`
- `vector?`
- `prodedure?`
- `null?`
- `pair?`

Für Gleichheitsprüfung:

- `eq?`: prüft, ob es sich um die gleichen Objekte im Speicher handelt
- `eqv?`: wie `eq?`, prüft Zahlen auf Äquivalenz, nicht auf Identität
- `equal?`: wie `eqv?`, prüft zusammengesetzte Zypen auf Äquivalent, nicht auf Identität
- `char=?`: Gleichheit von Zeichen
- `string=?`: Gleichheit von Strings
- `null?`: Nullprüfung

Prädikate lassen sich mittels `define` definieren:

```scheme
> (define (is-the-answer-to-everything? expr) (= expr 42))
> (is-the-answer-to-everything? 42)
#t
> (is-the-answer-to-everything? 35)
#f
```

### Symbole

- für symbolische Namen (nicht Zeichenketten)
- Sequenz von Zeichen beginnend mit einem einfachen Anführungszeichen `'`
    - `foobar`, `'this-is-a-test`
- `symbol=?`-Prädikat: Gleichheit von Symbolen
    - `(symbol=? 'Foo 'Foo)` → `#t`
    - `(symbol=? 'Foo 'Bar)` → `#f`

### Fallunterscheidung

Fallunterscheidung mit dem `cond`-Schlüsselwort:

```scheme
(cond (<condition clause 1> <expression 1>)
      (<condition clause 2> <expression 2>)
      ...
      (else <expression n>))
```

- Auswertung von oben nach unten
- Mindestens ein Fall muss zu `true` auswerten

Beispiel (`grade.rkt`):

```scheme
#lang racket

(define (grade score)
  (cond
    ((not (number? score)) "score is not a number")
    ((not (integer? score)) "score is not an integer")
    ((<= 90 score 100) "A")
    ((<= 75 score 89) "B")
    ((<= 65 score 74) "C")
    ((<= 55 score 64) "D")
    ((<= 45 score 54) "E")
    ((<= 30 score 44) "FX")
    ((<= 0 score 29) "F")
    (else "out of range [0,100]")
  )
)

(grade 101)
(grade 100)
(grade 50)
(grade 0)
(grade (/ 99 4))
```

Ausgabe:

```bash
$ racket -t grade.rkt
"out of range [0,100]"
"A"
"E"
"F"
"score is not an integer"
```

### Selektion

Selektion mit dem `if`-Schlüsselwort:

```scheme
(if (<test>) <then-expression> <else-expression>)
```

Beispiel (Absolutwert):

```scheme
(define (absolute x) (if (< x 0) (- x) x))
```

Die Ausdrücke `<then-expression>` und `<else-expression>` werden nur bei Bedarf
ausgewertetn (lazy evaluation).

## Strukturen

Strukturen sind zusammengesetzte Datentypen aus Atomen und anderen Strukturen.

Definition:

```scheme
(define-struct <typename>
    (<field 1> <field 2> ... <field n>))
```

Beispiel:

```scheme
(define-struct address
    (firstname lastname street number zipcode city))
(define-struct point-2d
    (x y))
(define-struct point-3d
    (x y z))
```

`define-struct` erzeugt weitere Funktionen:

1. `make-<typename>`: Konstruktor
    - `(make-point-2d 3 5)` → `#<point-2d>`
2. `<typename>?`: Typen-Prädikat
    - `(point-2d? (make-point-2d 10 20))` → `#t`
3. `<typename>-<field>`: Selektor für jedes Feld
    - `(define q (make-point-3d 10 20 30)) (point-3d-z q)` → `30`

### Anwendungsbeispiel: Punktabstand (Hypothenuse) berechnen

Die Struktur `point` definiert die zwei Felder `x` und `y`. Die Funktion
`hypot` erwartet zwei `point`-Instanzen, von denen sie den Abstand berechnet:

```scheme
#lang racket

(define-struct point (x y))

; hypot = sqrt((p.x - q.x)² + (p.y - q.y)²)
(define (hypot p q)
  (sqrt (+ (expt (- (point-x p) (point-x q)) 2)
           (expt (- (point-y p) (point-y q)) 2))))

(define a (make-point 5 7))
(define b (make-point 2 3))
(hypot a b)
; sqrt((5 - 2)² + (7 - 3)²) = sqrt(3² + 4²) = sqrt(9 + 16) = sqrt(25) = 5
```

Ein Punkt mit zwei Koordinaten steht auch mit der eingebauten Struktur `posn`
(Position) zur Verfügung.

## Listen

Rekursive Liste: Entweder leer, oder bestehend aus einem Element und einem
Rest, der wiederum eine Liste ist. Listen können Elemente beliebiger (auch
unterschiedlicher) Datentypen enthalten.

- Selektoren:
    - `first`/`car`: erstes Element
    - `rest`/`cdr`: Restliste
- Prädikate:
    - `list?`: Liste?
    - `cons?`: nicht leere Liste?
    - `empty?`: leere Liste?
- Funktionen:
    - `reverse`: Reihenfolge umkehren
    - `length`: Länge der Liste
    - `append`: zwei Listen aneinanderhängen

Beispiel:

```scheme
> (define list0 empty)
> list0
'()
> (first list0)
'()
> (rest list0)
'()
> (list? list0)
#t
> (cons? list0)
#f
> (empty? list0)
#t

> (define list1 (cons 'a empty))
> list1
'(a)
> (first list1)
'a
> (rest list1)
'()
> (list? list1)
#t
> (cons? list1)
#t
> (empty? list1)
#f
> (empty? (rest list1))
#t

> (define list2 (cons 'a (cons 'b empty)))
> list2
'(a b)
> (first list2)
'a
> (rest list2)
'(b)
> (first (rest list2))
'b
> (car (cdr list2))
'b
> (cadr list2)
'b

> (reverse (list 'a 'b 'c 'd))
'(d c b a)
> (length (list 'a 'b 'c 'd))
4
> (append '('a 'b 'c) '('x 'y 'z))
'('a 'b 'c 'x 'y 'z)
```

    list0: []
    list1: [a|]->[]
    list2: [a|]->[b|]->[]

`cons` vs. `list`:

```scheme
> (cons "foo" (cons "bar" (cons "qux" empty)))
'("foo" "bar" "qux")
> (list "foo" "bar" "qux")
'("foo" "bar" "qux")
> '("foo" "bar" "qux")
'("foo" "bar" "qux")
```

Die `list`-Funktion wertet im Gegensatz zum Quote-Konstruktor `'` alle
Argumente aus:

```scheme
> '((+ 2 2))
'((+ 2 2))
> (list (+ 2 2))
'(4)
```

Strukturen in Listen:

```scheme
; using a list like a struct
(define payroll
    (list
        (list "Hinz" 7500)
        (list "Kunz" 6900)))

; using a real struct
(define-struct wage (name salary))
(define payroll
    (list
        (make-wage "Hinz" 7500)
        (make-wage "Kunz" 6000)))
```

### Rekursive Funktionen auf Listen

Summieren einer Liste:

```scheme
(define (sum l)
  (cond
    ((empty? l) 0) ; Rekursionsbasis
    (else (+       ; Rekursionsanweisung
            (first l)
            (sum (rest l))))))

(sum '(1 2 3 4 5)) ; 15
```

Quadrieren aller Listenelemente:

```scheme
(define (square-list l)
  (cond
    ((empty? l) empty)
    (else
      (cons (* (first l) (first l))
            (square-list (rest l))))))

(square-list '(1 2 3 4 5)) ; '(1 4 9 16 25)
```

Insertion Sort:

```scheme
(define (insert v l)
  (cond
    ((empty? l) (list v))
    ((<= v (first l)) (cons v l))
    (else (cons (first l)
                (insert v (rest l))))))

(define (insertion-sort l)
  (cond
    ((empty? l) empty) ; Rekursionsbasis: leere Liste (per Definition sortiert)
    (else (insert (first l)
                  (insertion-sort (rest l)))))) ; Rekursionsanweisung

(insertion-sort (list 9 4 6 1)) ; '(1 4 6 9)
```

## Rekursion

Strukturelle Rekursion:

- Zerlegen der Eingabedaten in ihre strukturellen Komponenten
    - Beispiel: Listen in Listenelemente zerlegen
- ein Aufruf pro Komponente
- Funktionsschema: erstes Element behandeln, erneuter Aufruf für den Rest

Beispiel (Maximalwert einer Liste finden):

```scheme
(define (maximum l)
  (cond
    ((empty? (rest l)) (first l))
    (else (cond
            ((> (first l) (maximum (rest l))) (first l))
            (else (maximum (rest l)))))))

(maximum '(5 2 6 9 4)) ; 9
```

Problem: zwei Rekursionsaufrufe!

Alternative: Akkumulative Rekursion:

- Akkumulator zum Zwischenspeichern von Zwischenresultaten (Teillösungen)
- Endrekursiv (tail recursive): rekursiver Funktionsaufruf als letzter
  Berechnungsschritt (optimierbar)

```scheme
(define (maximum l acc)
  (cond
    ((empty? l) acc)
    ((> (first l) acc) (maximum (rest l) (first l)))
    (else (maximum (rest l) acc))))

(maximum '(5 2 6 9 4 8 1 3 7) 0) ; 9
```

Beispiel (grösster gemeinsamer Teiler, naive Lösung):

```scheme
(define (ggt a b)
  (ggt-internal a b (min a b)))

(define (ggt-internal a b divisor)
  (cond
    ((= divisor 1) 1)
    ((and (= (remainder a divisor) 0)
          (= (remainder b divisor) 0)) divisor)
    (else (ggt-internal a b (- divisor 1)))))

(ggt 318 54)
```

Problem: jeder Divisor von 1 bis `min(a,b)` wird durchprobiert (ineffizient).

ggT-Algorithmus von Euklid:

```scheme
(define (ggt-euklid a b)
  (cond
    ((zero? b) a)
    (else (ggt-euklid b (remainder a b)))))

(ggt-euklid 318 54)
```

Generative Rekursion:

- generativer Schritt: Argumente werden bei jedem Aufruf neu berechnet (`remainder a b`)
- Ansatz: Teile und Herrsche (Divide & Conquer)
    - Problem in Teilprobleme aufteilen
    - kleine Probleme lösen (Trivialfall)
    - Teillösungen zu Gesamtlösung kombinieren

## Funktionen höherer Ordnung

- Funktionen erster Ordnung: Führen Berechnungen (im weitesten Sinne) anhand
  von Daten aus
- Funktionen höherer Ordnung: Beschreiben allgemeine Berechnungen, die mittels
  Funktionsparameter spezifiziert werden

Beispiel (Grundrechenarten):

```scheme
; spezifische Funktionen
(define (plus a b)
  (+ a b))
(define (minus a b)
  (- a b))
(plus 3 5) ; 8
(minus 8 3) ; 5

; allgemeine Funktion mit Operation als Parameter
(define (calc a b f)
  (f a b))
(calc 3 5 +) ; 8
(calc 8 3 -) ; 5
```

- `plus` und `minus` sind Funktionen _erster Ordnung_
- `calc` ist eine Funktion _höherer Ordnung_

In Scheme sind Funktionen Daten und _Werte erster Klasse_ und können:

- als Parameter übergeben werden
- Rückgabewerte anderer Funktionen sein
- an Namen gebunden werden
- in Listen und Strukturen aufgenommen werden

Anwendungsbeispiele:

- `filter`: Filterprädikate auf Listen durchführen (Filterfunktion als
  Parameter)
- `map`: Mapping von Listenwerten (Anwenden einer Parameter-Funktion auf alle
  Listenelemente)
- `apply`: Reduktion von Listenwerten auf einen Wert (Listenelemente als
  Eingabeparameter für eine Parameter-Funktion)

Beispiel (`filter`, `map`, `apply`):

```scheme
; filter
(define (positive? x)
  (> x 0))
(filter positive? '(-3 5 -2 1)) ; '(5 1)

; map
(define (square x)
  (* x x))
(map square '(1 2 3 4 5)) ; '(1 4 9 16 25)

; apply
(apply + '(1 2 3 4)) ; 10
```

Beispiel (`reduce`-Implementierung):

```scheme
(define (reduce l f)
  (cond
    ((= 2 (length l)) (f (first l) (first (rest l))))
    (else (f (first l) (reduce (rest l) f)))))

(define (plus a b)
  (+ a b))

(reduce '(1 2 3 4) plus) ; 10

(define (bigger a b)
  (if (> a b)
      a
      b))

(reduce '(4 3 1 6 3) bigger) ; 6
```

## Scoping

### Lokaler Scope

Per `define` definierte Symbole (Variablen, Funktionen) sind global sichtbar. Mit `local` kann ein lokaler Scope definiert werden:

```scheme
(local (<definition 1>
        <definition 2>
        ...
        <expression>))
```

Die Definitionsliste wird abgearbeitet, `<expression>` evaluiert und
zurückgegeben. Der Ausdruck `<expression>` verwendet in der Regel die zuvor
innerhalb von `local` definierten Symbole, welche von ausserhalb nicht
zugreifbar sind. Beispiel:

```scheme
(define (binom a b)
  (local
    (
     (define (square a) (* a a)) ; a², b²
     (define (double-product a b) (* 2 a b))) ; 2ab
    (+ (square a) (double-product a b) (square b)))) ; a²+2ab+b²

; (3+4)² = 3²+2*3*4+4² = 9+24+16 = 49
(binom 3 4)
```

Die Parameter `a` und `b` der Funktionen `square` und `double-product` haben
nichts mit den Parametern `a` und `b` der Funktion `binom` zu tun
(lexikalisches Scoping).

### Lokale Variablen

Lokale Variablen können mithilfe einer Kombination von `local` und `define`
erstellt werden:

```scheme
(define (binom-local-vars a b)
  (local
    (
     (define x (* a a)) ; a²
     (define y (* 2 a b)) ; 2ab
     (define z (* b b))) ; b²
    (+ x y z)))

; (3+4)² = 3²+2*3*4+4² = 9+24+16 = 49
(binom-local-vars 3 4)
```

Die gleiche Definition kann auch kürzer mit `let` (nur für Variablen)
ausgedrückt werden:

```scheme
(let
 (
  (<var 1> <expr 1>)
  (<var 2> <expr 2>)
  ...
  (<var n> <expr n>)
  ))
```

Das Beispiel von vorher:

```scheme
(define (binom-let a b)
  (let
    (
     (x (* a a))
     (y (* 2 a b))
     (z (* b b)))
    (+ x y z)))

; (3+4)² = 3²+2*3*4+4² = 9+24+16 = 49
(binom-let 3 4)
```

Bei `let` ist zu beachten, dass zunächst alle Ausdrücke (`expr 1` bis `expr n`)
ausgewertet werden, bevor Zuweisungen an die Symbole (`var 1` bis `var n`)
stattfinden:

```scheme
(define (sevenfold x)
  (let
    (
     (double (* 2 x))
     (fourfold (* 2 double))) ; double: unbound identifier
    (+ fourfold double x))) ; 7x = 4x+2x+x

(sevenfold 2)
```

Die Form `let*` hingegen wertet die Definitionsliste von links nach rechts/oben
nach unten aus (`expr 1` auswerten und an `var 1` zuweisen, dann `expr 2`
auswerten und an `var 2` zuweisen usw.):

```scheme
(define (sevenfold x)
  (let*
    (
     (double (* 2 x))
     (fourfold (* 2 double)))
    (+ fourfold double x))) ; 7x = 4x+2x+x

(sevenfold 2) ; 14
```

## Anonyme Funktionen

Mit der Form `lambda` können anonyme Funktionen erstellt werden. Diese sind
dann hilfreich, wenn eine Funktionsdefinition nur einmal in einem bestimmten
Kontext benötigt wird, wie z.B. bei dieser `reduce`-Funktion, die eine Liste
und einen Funktionsausdruck erwartet:

```scheme
(define (reduce l f)
  (cond
    ((= 2 (length l))
     (f (first l) (first (rest l))))
    (else
      (f (first l)(reduce (rest l) f)))))

; named function
(define (plus a b) (+ a b))
(reduce '(1 2 3 4) plus)

; lambda expression
(reduce '(1 2 3 4) (lambda (a b) (+ a b)))
```

`lambda`-Ausdrücke können nicht rekursiv verwendet werden, da sie keinen Namen
haben.

## Seiteneffekte

Reine Funktionen haben keinen Status. Ihr Rückgabewert ist ausschliesslich von
den Parametern und der Funktionsdefinition abhängig. Oft müssen in der
Programmierung Zustände abgespeichert und aktualisiert werden. Dazu kann die
`set!`-Form verwendet werden, welche den Wert einer Variablen überschreibt.

Beispiel (Counter mit Closure):

```scheme
(define (counter current)
  (lambda ()
    (set! current (+ current 1)) ; override value
    current))

(define c (counter 0))
(c) ; 1
(c) ; 2
(c) ; 3
```

## Sequenzen

Die `begin`-Form wertet eine Liste von Ausdrücken aus und gibt den Wert des
letzten evaluierten Ausdrucks zurück. Damit lassen sich prozedurale
Programmkonstrukte umsetzen:

```scheme
(define (binom-seq a b)
  (begin
    (define result 0)
    (set! result (* a a)) ; a²
    (set! result (+ result (* 2 a b))) ; + 2ab
    (set! result (+ result (* b b))) ; + + b²
    result))

(binom-seq 3 4) ; 49
```

## Praktische Tipps

Mit Racket eine Datei einlesen (`-t`) und deren Symbole interaktiv (`-i`) im
REPL (read-eval-print-loop) verwenden (`interactive.rkt`):

```scheme
#lang racket
(provide x) ; make x available in REPL!
(define x 3)
(define y 4)
```

Ausführung:

```bash
racket -it interactive.rkt
> x
3
> y
; y: undefined
```
