# 1 Performance-Messungen an Mergesort

Mit den Threshold-Werten 10, 25, 33, 50, 66, 75, 100 und 250 erhalte ich für
eine Sortierung eines `int`-Arrays mit 100 Millionen Elemente folgende
Laufzeiten:

 Threshold  Duration
---------- ---------
        10      8372
        25      8054
        33      8224
        50      8124
        66      7997
        75      8065
       100      8471
       250      9052

Sinnvolle Threshold-Werte scheinen im Bereich zwischen 25 bis 75 zu liegen. Für
kleinere Werte dürfte der Overhead der Parallelisierung zu gross ausfallen. Für
grössere Werte fällt die Langsamkeit des langsameren Insertion-Sort ins Gewicht.

# 2 Quicksort parallelisieren

Ich verwende wiederum die Threshold-Werte 10, 25, 33, 50, 66, 75, 100, 250 um
`int`-Arrays mit 100 Millionen Elemente zu sortieren. Dabei erhalte ich folgende
Laufzeiten:

 Threshold  Duration
---------- ---------
        10      6987
        25      6290
        33      6313
        50      5636
        66      5863
        75      6191
       100      6231
       250      5722

Aufgrund dieser Messung entscheide ich mich für den Threshold-Wert 50 für meinen
Quick-Sort, um ihn gegen `Arrays.sort` antreten zu lassen. Dabei komme ich auf
folgende Laufzeiten:

 Items  Arrays.sort  QuickSort
------ ------------ ----------
    1M          200        220
    2M          240        117
    5M          471        267
   10M         1055        598
   20M         2054       1149
   50M         5458       2991
  100M        11266       6961

Der Quick-Sort läuft ungefähr doppelt so schnell wie `Arrays.sort`. Da mein
Rechner über 4 Cores verfügt, sollte der Faktor theoretisch 4 betragen. Das ist
aufgrund folgender Gründe nicht der Fall:

- Quick-Sort verwendet `Arrays.sort` für kleinere n
- Speicher und Caches werden von den Cores gemeinsam verwendet
- Die Parallelisierung verursacht einen Overhead

# 3 Fibonacci-Zahlen

Die rekursive Lösung wird ab der 35. Fibonacci-Zahl richtig. Die nebenläufige
(rekursive) Lösung ist überraschenderweise noch langsamer; der Overhead scheint
hier grösser zu sein als der Zugewinn durch die Parallelisierung. Die iterative
Lösung ist die schnellste.

 nth Fib  recursively  concurrently  iteratively
-------- ------------ ------------- ------------
       1            0             0            0
       2            0             0            0
       3            0             0            0
       4            0             0            0
       5            0             0            0
       6            0             0            0
       7            0             1            0
       8            0             0            0
       9            0             1            0
      10            0             2            0
      11            0             0            0
      12            0             0            0
      13            0             0            0
      14            0             0            0
      15            0             0            0
      16            0             0            0
      17            0             0            0
      18            0             1            0
      19            0             2            0
      20            0             4            0
      21            1             5            0
      22            1            14            0
      23            1            11            0
      24            1            18            0
      25            3            25            0
      26            5            57            0
      27            7            40            0
      28            9            49            0
      29           14            57            0
      30           23            55            0
      31           36            90            0
      32           54           143            0
      33           90           265            0
      34          139           389            0
      35          222           625            0
      36          353           894            0
      37          564          1507            0
      38          922          2429            0
      39         1563          3882            0
      40         2479          7450            0
      41         3970         11105            0
      42         6393         16265            0

# 4 Finde das File

TODO

# 5 Optional: Türme von Hanoi

TODO
