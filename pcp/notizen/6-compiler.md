# Compiler

Ein Compiler ist ein Übersetzungsprogramm, das:

- ein Programm in einer _Quellsprache_ liest,
- es in ein äquivalentes Programm in einer _Zielsprache_ übersetzt
- und dabei weder _Syntax_ noch _Semantik_ des Programms verfälscht.

Compiler erkennen Fehler und melden sie dem Benutzer:

- Syntaxfehler: `c = (a + b/2;` (fehlende schliessende Klammer)
- Semantikfehler: `x = y + z` (Variable y noch nicht definiert)

## Kompilierungsphasen

Die Kompilierung läuft in zwei Phasen ab:

1. Analyse
    - lexikalische Analyse
        - Zerlegung des Quellcodes in seine Bestandteile
        - Erzeugung von Tokens daraus
    - syntaktische Analyse
        - Anwendung von Grammatikregeln auf Tokens (Beispiel: «sind `a` und `b`
          Ausdrücke, so ist auch `a*b` ein Ausdruck»)
        - Zwischendarstellung als Syntaxbaum (siehe Beispiel)
    - semantische Analyse
        - Namensprüfung (Namenskonventionen)
        - Typprüfung (Zuweisungen, Parameterübergaben, Rückgaben, Casting)
        - Identifikation von Operatoren und Operanden
        - Überprüfung des Kontrollflusses (Code erreichbar?)
        - Gültigkeitsbereiche (Eindeutigkeit, lexikalisches Scoping)
2. Synthese
    - Zwischencode-Erzeugung: Einfacher Zwischencode für virtuelle
      (konzeptionelle) Maschine
    - Code-Optimierung
        - Inlining von einfachen Funktionen
        - Eliminierung von Rekursionen
        - Plattformspezifische Optimierungen (je nach Befehlssatz)
    - Code-Erzeugung: Erzeugung des Maschinencodes

Die Analyse und Zwischencode-Erzeugung werden vom Compiler-Frontend übernommen.
Das Compiler-Backend kümmert sich um die Optimierung und Erzeugung des finalen
Codes.

![Syntaxbaum zum Ausdruck `average:=(a+b)/2`](graphs/syntaxtree.png){width=250px}

## Arten von Compilern

- Nativer Compiler: erzeugt Maschinencode für die Plattform, auf dem er selber
  läuft
- Cross-Compiler: erzeugt Maschinencode für eine andere Plattform
- Single-Pass-Compiler: erzeugt den Zielcode ohne Zwischenschritt
    - schnellerer Kompiliervorgang, dafür weniger optimierter Code
- Multi-Pass-Compiler: erzeugt den Zielcode in mehreren Schritten (siehe oben)
- Transcompiler: übersetzt Code von einer Hochsprache in eine andere
- Compiler-Compiler: Hilfsprogramm zur Generierung von Compiler-Teilen (z.B.
  `yacc`, ein Parser Generator)
- Just-in-time-Compiler (JIT-Compiler): übersetzt Code zur Laufzeit in
  Maschinencode, um die Ausführungsgeschwindigkeit gegenüber einem Interpreter
  zu steigern
- Compreter: Zwischencode-Erzeugung beim Kompiliervorgang, Interpretation zur
  Laufzeit
- Interpreter: Erzeugen keine Programme, sondern führen generierten Code direkt
  aus
    - Kombination mit JIT-Compilern möglich: `javac` erzeugt Bytecode, `java`
      optimiert zur Laufzeit

| Vergleich | Compiler                                                    | Interpreter                                           |
|-----------|-------------------------------------------------------------|-------------------------------------------------------|
| Vorteil   | einmal kompilieren, mehrmals ausführen; Laufzeitperformance | schnellerer Arbeitszyklus (try, fail, correct, retry) |
| Nachteil  | mehrere Schritte bis zur Ausführung; aufwändige Fehlersuche | erneute Analyse bei jeder Ausführung; kein Executable |

## Bytecode und virtuelle Maschinen

- Bytecode ist vergleichbar mit dem Zwischencode eines traditionellen
  Compilers.
- Er wird beim Kompiliervorgang nicht weiter verarbeitet, sondern direkt auf
  einer virtuellen Maschine ausgeführt (oft mithilfe eines JIT-Compilers).
- Im Gegensatz zum traditionellen Zwischencode enthält Bytecode
  Typinformationen, Instruktionen zur Thread-Organisation und Metainformationen
  (Debug-Symbole); ist sehr kompakt und serialisierbar.
- Die virtuelle Maschine übernimmt Aufgaben wie Code-Optimierung
  (JIT-Compiler), Speicherorganisation (gemäss einem definierten
  Speichermodell), Thread- und IO-Organisation etc.

## Formale Sprachen

- Sprache: Bildung von Sätzen aus einer definierten Menge von Zeichen unter
  Beachtung der Syntaxregeln.
- Alphabet (Σ): Menge von Zeichen, aus denen Wörter gebildet werden.
    - Terminales Alphabet (T): Menge von Zeichen, aus denen Sätze der Sprache
      gebildet werden (auch Atome, Morpheme, Token genannt).
        - `T={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '.'}`
    - Nichtterminales Alphabet (N): Menge von Metasymbolen zur Bildung
      syntaktischer Regeln.
        - `N={Zahl, GanzzahlTeil, BruchTeil}`
- Zeichenkette/Wort: Aneinanderreihung von Zeichen eines Alphabets.
    - Kann sowohl aus Elementen des terminalen wie auch des nichtterminalen
      Alphabets bestehen.

### Grammatik nach Chomsky

Grammatik nach Chomsky: `G=(T,N,s,P)`

- `T`: terminales Alphabet
- `N`: nichtterminales Alphabet
- `s`: Startsymbol, Axiom
- `P`: Menge der Produktionen (Regeln)
    - Regeln: `[linke Seite] [Symbol] [rechte Seite]`
        - beide Seiten sind Zeichenketten des Alphabets
        - linke Seite: mindestens ein nichtterminales Symbol (wird durch die
          Anwendung der Regel ersetzt)
        - Symbole: `->`: wird abgeleitet nach, `::`, `::=`

Beispiel einer Grammatik:

    T = { der, ein, Mann, Bier, trinkt }
    N = { Satz, Subjekt, Prädikat, Objekt, Artikel, Verb, Substantiv }
    S = Satz
    P = {
        Satz       -> Subjekt Prädikat Objekt (1)
        Subjekt    -> Artikel Substantiv      (2)
        Objekt     -> Artikel Substantiv      (3)
        Prädikat   -> Verb                    (4)
        Substantiv -> Mann                    (5)
        Substantiv -> Bier                    (6)
        Verb       -> trinkt                  (7)
        Artikel    -> der                     (8)
        Artikel    -> ein                     (9)
    }

- Ableitungen:
    - Linksableitung: das am weitesten links stehende nichtterminale Metasymbol
      wird untersucht
    - Rechtsableitung: das am weitesten rechts stehende nichtterminale
      Metasymbol wird untersucht
- Ableitbarkeit: Zeichenkette `t` ist aus Zeichenkette `s` ableitbar, wenn es
  eine Folge direkter Ableitung dieser Form gibt:
    - `s=>t`, falls `s->s1->s2->...->sn->t`
    - Beispiel: `Satz=>Der Mann trinkt das Bier`
    - direkte Ableitbarkeit: `t` durch Anwendung einer einzigen Regel aus `s`
      ableitbar
- Eine _Satzform_ zu einer Grammatik G ist ein String, der aus einem
  Startsymbol (Axiom) ableitbar ist. Die Grammatik kann terminale und
  nichtterminale Symbole enthalten.
- Ein _Satz_ ist eine Satzform, die nur terminal Symbole enthält.
- Eine _Sprache_ ist die Menge der durch eine Grammatik G erzeugbaren Sätze.

Bildung eines Satzes:

| Regel | Satzform                           |
|-------|------------------------------------|
| (1)   | Satz                               |
| (2)   | Subjekt Prädikat Objekt            |
| (8)   | der Substantiv Prädikat Objekt     |
| (5)   | der Mann Prädikat Objekt           |
| (4)   | der Mann Verb Objekt               |
| (7)   | der Mann trinkt Objekt             |
| (3)   | der Mann trinkt Artikel Substantiv |
| (9)   | der Mann trinkt ein Substantiv     |
| (6)   | der Mann trinkt ein Bier           |

Parsen eines Satzes:

| Regel | Satzform                            |
|-------|-------------------------------------|
|       | der Mann trinkt ein Bier            |
| (8)   | Artikel Mann trinkt ein Bier        |
| (5)   | Artikel Substantiv trinkt ein Bier  |
| (2)   | Subjekt trinkt ein Bier             |
| (7)   | Subjekt Verb ein Bier               |
| (4)   | Subjekt Prädikat ein Bier           |
| (9)   | Subjekt Prädikat Artikel Bier       |
| (6)   | Subjekt Prädikat Artikel Substantiv |
| (2)   | Subjekt Prädikat Objekt             |
| (1)   | Satz                                |

### Erweiterte Backus-Naur-Form (EBNF)

- BNF: Backus-Naur-Form (formale Syntax-Beschreibungssprache) von John Backus
  (Fortran) und Peter Naur (Algol)
- EBNF: Erweiterung von Niklaus Wirth (Pascal): wechselseitig rekursive
  Definition der syntaktischen Kategorien einer Programmiersprache
- Bausteine:
    - nichtterminale Symbole: syntaktische Kategorien
    - terminale Symbole: wörtliche Symbole der Sprache (in `' '`)
- BNF-Symbole:
    - `'='`: Definitionszeichen
    - `'|'`: Alternative
    - `'''`: Kennzeichnung von Sprachsymbolen
    - `'ϕ'`: Leere Zeichenfolge
    - `'.'`: Ende einer Regel
- Zusätzliche EBNF-Symbole (Klammernpaare):
    - `()`: Gruppierung
    - `[]`: Option (`0..1`)
        - Alternative: `()?`
    - `{}`: optionale Wiederholung (`0..n`)
        - Alternative: `()*`
    - `<>`: beliebige Wiederholung (`1..n`)
        - Alternative: `()+`
- Aufbau der EBNF-Notation:
    1. Startregel
    2. sonstige Regeln
    3. terminale (Basiselemente) und nichtterminale (abgeleitete Konstrukte) Symbole
- EBNF-Regeln: `linke Seite = rechte Seite`
    - linke Seite: genau ein nichtterminales Symbol
    - rechte Seite:
        - terminale Symbole (in `' '`)
        - nichtterminale Symbole
        - leere Zeichenfolge `'ϕ'`
        - Alternativen (durch `'|'` gruppiert)
        - geklammerte Ausdrücke (nur EBNF)

Beispiel:

    Ausdruck          = EinfacherAusdruck [ RelOp EinfacherAusdruck] .
    EinfacherAusdruck = [ AddOp ] Term { AddOp Term } .
    Term              = [ 'NOT' ] Faktor { MulOp Faktor } .
    Variable          = 'a' | 'b' | 'c' | 'd' | 'e' | 'f' .
    AddOp             = '+' | '-' .
    MulOp             = '*' | '/' .
    RelOp             = '=' | '!=' | '<' | '<=' | '>' | '>=' .

Mögliche Ausdrücke (erste Regel als Startregel):

    d
    a + b
    -(c/d)
    (a*b) <> (c / f)
    NOT (c/e)

## Parsergeneratoren

Ein Parsergenerator erstellt aus einer Grammatik, die z.B. in EBNF vorliegt,
ein Parser-Programm in einer bestimmten Sprache.

ANTLR steht für «ANother Tool for Language Recognition». Es bietet eine
kompakte Sprache zur Formulierung von Sprachgrammatiken. Damit lassen sich
lexikalische Scanner (Tokenizer) und Parser aus LL-Grammatiken erzeugen:

- LL: Abarbeitung von links nach rechts
- LL(k): Abarbeitung mittels Lookahead-Buffer von k Zeichen
- LL(*): Abarbeitung adaptiver Grammatiken

ANTLR bietet zwei Mechanismen zum Durchlaufen eines Syntaxbaums:

1. Listener Interface: reagiert auf Ereignisse, die vom Tree Walker ausgelöst
   werden (vgl. SAX).
    - `enter()`: Ereignis beim Eintritt in eine Regel
    - `exit()`: Ereignis beim Austritt aus einer Regel
2. Visitor Interface: bietet die Möglichkeit, den Syntaxbaum gemäss eigener
   Regeln abzuarbeiten.
