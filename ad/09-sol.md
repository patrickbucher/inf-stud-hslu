# 1 Quicksort ‒ theoretisch durchgespielt

## a)

Erster Durchgang:

12 10 52~1~ 9 77 23 18 52~2~ 11 25 8 5 _17_

12 10 5 9 8 11 _17_ 52~2~ 23 25 77 52~1~ 18

Zweiter Durchgang:

12 10 5 9 8 _11_ | 17 | 52~2~ 23 25 77 52~1~ _18_

8 10 5 9 _11_ 12 | 17 | _18_ 23 25 77 52~1~ 52~2~

Dritter Durchgang:

9 10 5 _9_ | 11 12 17 18 | 23 25 77 52~1~ _52~2~_

8 5 _9_ 10 | 11 12 17 18 | 23 25 52~1~ _52~2~_ 77

Vierter Durchgang:

8 _5_ | 9 10 11 12 17 18 | 23 25 _52~1~_ | 52~2~ 77

_5_ 8 | 9 10 11 12 17 18 | 23 25 _52~1~_ | 52~2~ 77

Fünfter Durchgang

5 8 9 10 11 12 17 18 | 23 _25_ | 52~1~ 52~2~ 77

5 8 9 10 11 12 17 18 23 _25_ 52~1~ 52~2~ 77

## b)

Die Zahl 52~1~ war nach dem ersten Durchgang rechts von 52~2~. Dass die
Reihenfolge im zweiten Durchgang noch einmal (und zwar endgültig) änderte, ist
reiner Zufall. Quicksort arbeitet _instabil_.

## c)

Beim ersten Durchgang kämen 12 (Index 0), 18 (Index 6) und 17 (Index 12) in
Frage. Dadurch würde erneut 17 als Trennelement fungieren.

Beim zweiten Durchgang würde es links wiederum genau gleich ablaufen, rechts
würde aber mit 25 ein anderes Element verwendet werden. Das könnte die
Sortierung etwas beschleunigen und evtl. einen fünften Durchgang ersparen.

# 2 Quicksort ‒ klassisch programmiert

## a)

```java
public static void quickSort(Character[] data, int left, int right) {
    int up = left;
    int down = right - 1;
    char t = data[right];
    do {
        while (data[up] < t) {
            up++;
        }
        while (data[down] >= t && down > up) {
            down--;
        }
        if (up < down) {
            swap(data, up, down);
        }
    } while (up < down);
    swap(data, up, right);
    if (left < up - 1) {
        quickSort(data, left, up - 1);
    }
    if (right > up + 1) {
        quickSort(data, up + 1, right);
    }
}
```

Testfall:

```java
@Test
public void testQuickSort() {
    final int n = 200_000;
    Character data[] = SortingUtils.generateRandomCharArray(n, 'A', 'Z');
    Sort.quickSort(data, 0, data.length - 1);
    boolean sorted = SortingUtils.isSorted(Arrays.asList(data), true);
    Assert.assertTrue(sorted);
}
```

Für grössere `n` ist es wichtig die Stackgrösse zu erhöhen. Dies erreicht man
mit dem JVM-Parameter `-Xss10M` (stellt die Stackgrösse auf 10 Megabyte).

## b)

```java
public static void quickSort(Character[] data) {
    quickSort(data, 0, data.length - 1);
}
```

## c)

```java
public static Character[] randomChars(int size, int min, int max) {
    Random random = new Random(System.currentTimeMillis());
    Character array[] = new Character[size];
    for (int i = 0; i < size; i++) {
        array[i] = (char) (random.nextInt(max - min + 1) + min);
    }
    return array;
}
```

## d)

 Elemente (`n`)   Messung (ms)
---------------  ------------- 
          1000           2
          5000           7
        10'000          12
        50'000          35
       100'000         133
       500'000        2993
     1'000'000      11'888


Beispiel: Um welchen Faktor müsste eine Sortierung mit 1'000'000 Elementen
länger dauern als eine Sortierung mit 500'000 bzw. 100'000 Elementen?

    (1'000'000 * log 1'000'000) / (500'000 * log 500'000) = 2.1
    (1'000'000 * log 1'000'000) / (100'000 * log 100'000) = 12

Realität:

    11'888 / 2993 = 3.97
    11'888 / 133 = 89.4

Das Laufzeitverhalten scheint eher `O(n²)` zu entsprechen (eine Verdoppelung der
Elemente führt zu einer Verfierfachung der Laufzeit; eine Verzehnfachung der
Elemente erhöht die Laufzeit ca. um Faktor 90).

# 3 Quick-Insertion-Sort

## a)

Zur eigentlichen Methode, die zusätzlich einen Parameter `m` hat (Schwellenwert,
unter dem der Insertion-Sort verwendet werden soll), implementiere ich wiederum
eine Hilfsmethode.

```java
public static void quickInsertionSort(Character[] data, int m) {
    quickInsertionSort(data, 0, data.length - 1, m);
}

static void quickInsertionSort(Character[] data, int l, int r, int m) {
    // bestehender Algorithmus
    // ...
    // veränderte Rekursionsanweisungen:
    if (left < up - 1) {
        int from = left;
        int to = up - 1;
        if (to - from + 1 > m) {
            quickInsertionSort(data, from, to, m);
        } else {
            SimpleSorting.insertionSort(data, from, to);
        }
    }
    if (right > up + 1) {
        int from = up + 1;
        int to = right;
        if (to - from + 1 > m) {
            quickInsertionSort(data, from, to, m);
        } else {
            SimpleSorting.insertionSort(data, from, to);
        }
    }
}
```

## b)

Ich sortiere eine Million Zeichen mit verschiedenen `m`-Werten. Dabei erhalte
ich folgende Laufzeiten:

    m     Zeit (ms)
-----    ----------
    5       9420
   10       9278
   15       9259
   20       9361
   25       9269
   30       9258
   40       9267
   50       9263
   75       9267
  100       9289
  125       9265
  150       9260
  200       9300
  250       9259
  500       9255
 1000       9410

Bei einer Datenmenge von einer Million Zeichen scheinen sinnvolle `m`-Werte von
10 bis 500 zu liegen.

## c)

Mit `m = 25` kann ich beim Quick-Insertion-Sort (QIS) gegenüber dem Quick-Sort
(QS) keinen Laufzeitvorteil feststellen:

       n    QS (ms)   QIS (ms)
-------- ---------- ----------
    1000          2          2
    5000          6          6
   10000          4         15
   50000         35         33
  100000        134        126
  500000       3080       3043
 1000000      11866      12101
 2000000      47465      48360

# 4 Datenstruktur Heap

Ich habe den Heap gleich generisch und mit dynamischer Grösse implementiert.

## a)

![Heap nach dem Auffüllen und nach dem Entfernen](09-heaps.png)

## b)

Das Interface `GenericHeap`:

```java
public interface GenericHeap<T extends Comparable<T>> {
    public T getMax();
    public void insert(T element);
    public int getSize();
}
```
## c)

Die Klasse `Heap`:

```java
public class Heap<T extends Comparable<T>> implements GenericHeap<T> {

    private final List<T> heap = new ArrayList<>();

    @Override
    public T getMax() {
        if (heap.isEmpty()) {
            throw new IllegalStateException("Heap is empty.");
        }
        T max = heap.get(0);
        heap.set(0, heap.get(heap.size() - 1));
        heap.remove(heap.size() - 1);
        sink();
        return max;
    }

    @Override
    public void insert(T element) {
        heap.add(element);
        int newElementIndex = heap.size() - 1;
        raise(newElementIndex);
    }

    @Override
    public int getSize() {
        return heap.size();
    }

    private void sink() {
        final int size = heap.size();
        boolean sunk = false;
        int l = 1, f = 0, r = 2;
        while (!sunk && (l < size || r < size)) {
            T father = heap.get(f);
            T left = l < size ? heap.get(l) : father;
            T right = r < size ? heap.get(r) : father;
            if (father.compareTo(left) < 0 || father.compareTo(right) < 0) {
                int biggerChildIndex = left.compareTo(right) > 0 ? l : r;
                swap(f, biggerChildIndex);
                f = biggerChildIndex;
                l = (2 * f) + 1;
                r = 2 * (f + 1);
            } else {
                sunk = true;
            }
        }
    }

    private void raise(int i) {
        boolean risen = false;
        while (!risen) {
            int father = (i - 1) / 2;
            if (heap.get(i).compareTo(heap.get(father)) > 0) {
                swap(i, father);
                i = father;
                if (i == 0) {
                    risen = true;
                }
            } else {
                risen = true;
            }
        }
    }

    private void swap(int a, int b) {
        T tmp = heap.get(a);
        heap.set(a, heap.get(b));
        heap.set(b, tmp);
    }
}
```

## d)

Aus der Testklasse `GenericSortTest`:

```java
private static final int TEST_SIZE = 100;
private static final int STRING_LENGTH = 30;

private Integer integers[] = new Integer[TEST_SIZE];
private Double doubles[] = new Double[TEST_SIZE];
private String strings[] = new String[TEST_SIZE];

@Before
public void initializeRandomArray() {
    Random random = new Random(System.currentTimeMillis());
    for (int i = 0; i < TEST_SIZE; i++) {
        integers[i] = random.nextInt();
        doubles[i] = random.nextDouble();
        strings[i] = randomString(random);
    }
}

@Test
public void testIntegerHeapSort() {
    GenericSort.heapSort(integers);
    Assert.assertTrue(SortingUtils.isSorted(Arrays.asList(integers), true));
}

@Test
public void testDoubleHeapSort() {
    GenericSort.heapSort(doubles);
    Assert.assertTrue(SortingUtils.isSorted(Arrays.asList(doubles), true));
}

@Test
public void testStringHeapSort() {
    GenericSort.heapSort(strings);
    Assert.assertTrue(SortingUtils.isSorted(Arrays.asList(strings), true));
}

private String randomString(Random random) {
    StringBuilder randomString = new StringBuilder();
    for (int i = 0; i < STRING_LENGTH; i++) {
        randomString.append((char) (random.nextInt('Z' - 'A' + 1) + 'A'));
    }
    return randomString.toString();
}
```

## e)

Ich habe der `GenericSort`-Klasse folgende Methode (für eine _aufsteigende_
Sortierung) als API für den Heap hinzugefügt:

```java
public static <T extends Comparable<T>> void heapSort(T items[]) {
    GenericHeap<T> heap = new Heap<>();
    for (int i = 0; i < items.length; i++) {
        heap.insert(items[i]);
    }
    for (int i = items.length - 1; i >= 0; i--) {
        items[i] = heap.getMax();
    }
}
```

# 5 Übersicht Sortieralgorithmen

## a) und b)

Algorithmus                          O avg        O worst     O best         stabil  parallel  Merkmale
------------                         -----------  ----------  -------------  ------- --------- ---------
Direktes Einfügen (Insertion Sort)   O(n²)        O(n²)       O(n)           ja      nein      sortierter/unsortierter Teil; benachbartes Vertauschen
Direktes Auswählen (Selection Sort)  O(n²)        O(n²)       O(n²)          nein    nein      sortierter/unsortierter Teil; Vertauschen über weite Entfernungen
Direktes Austauschen (Bubble Sort)   O(n²)        O(n²)       O(n)           ja      nein      Vergleich von jedem Element mit jedem
Shellsort                            O(n*log²n)   O(n*log²n)  O(n*log n)     nein    nein      Insertion Sort mit verschiedenen Schrittweiten
Quicksort (`Arrays.sort()`)          O(n*log n)   O(n²)       O(n*log n)     ja      ja        Divide & Conquer; Sortierung um Teilerelement
Mergesort (`Collections.sort()`)     O(n*log n)   O(n*log n)  O(n*log n)     nein    ja        Divide & Conquer; Reissverschlussprinzip
Heapsort                             O(n*log n)   O(n*log n)  O(n*log n)     ja      nein      basiert auf Heap-Datenstruktur

# 6  Optional: Quicksort ‒ generisch programmiert

## a) und b)

```java
public static <T extends Comparable<T>> void quickSort(T[] data) {
    quickSort(data, 0, data.length - 1);
}

public static <T extends Comparable<T>> void quickSort(T[] data, int left, int right) {
    if (right - left == 0) {
        return;
    }
    int up = left;
    int down = right - 1;
    T t = data[right];
    do {
        while (data[up].compareTo(t) < 0) {
            up++;
        }
        while (data[down].compareTo(t) >= 0 && down > up) {
            down--;
        }
        if (up < down) {
            swap(data, up, down);
        }
    } while (up < down);
    swap(data, up, right);
    if (left < up - 1) {
        quickSort(data, left, up - 1);
    }
    if (right > up + 1) {
        quickSort(data, up + 1, right);
    }
}
```

## c) und d)

Die Methode `medianOfThree()` ermittelt das mittlere Element im angegebenen Bereich:

```java
public static <T extends Comparable<T>> int medianOfThree(T items[], int left, int right) {
    int middle = left + ((right - left) / 2);
    T l = items[left];
    T m = items[middle];
    T r = items[right];
    if (l.compareTo(r) > 0 && l.compareTo(m) < 0 || l.compareTo(r) < 0 && l.compareTo(m) > 0) {
        return left;
    } else if (m.compareTo(r) > 0 && m.compareTo(l) < 0 || m.compareTo(r) < 0 && m.compareTo(l) > 0) {
        return middle;
    } else {
        return right;
    }
}
```

Das ermittelte Element muss dann ans rechte Ende des zu sortierenden Bereiches verschoben werden:

```java
int tIndex = medianOfThree(data, left, right);
swap(data, tIndex, right);
```

Dieser Testfall testet Heapsort, Quicksort und Median-of-Three-Quicksort:

```java
public class GenericSortBenchmark {

    private static final int TEST_SIZES[] = new int[] { 100_000, 200_000, 500_000, 1_000_000, 2_000_000, 5_000_000, };

    private Random random;

    @Before
    public void initialize() {
        random = new Random(System.currentTimeMillis());
    }

    @Test
    public void benchmarkHeapVsQuickSort() {
        System.out.println("   Items    HS    QS  QS Mo3");
        System.out.println("-------- ----- ----- -------");
        for (int testSize : TEST_SIZES) {
            Integer hItems[] = randomIntegerArray(testSize);
            Integer qItems[] = Arrays.copyOf(hItems, hItems.length);
            Integer qItemsMo3[] = Arrays.copyOf(hItems, hItems.length);

            long hStart = System.currentTimeMillis();
            GenericSort.heapSort(hItems);
            long hEnd = System.currentTimeMillis();
            Assert.assertTrue(sorted(hItems));

            long qStart = System.currentTimeMillis();
            GenericSort.quickSort(qItems);
            long qEnd = System.currentTimeMillis();
            Assert.assertTrue(sorted(qItems));

            long qStartMo3 = System.currentTimeMillis();
            GenericSort.quickSortMedianOfThree(qItemsMo3);
            long qEndMo3 = System.currentTimeMillis();
            Assert.assertTrue(sorted(qItemsMo3));

            System.out.printf("%8d %5d %5d %7d\n", testSize, hEnd - hStart, qEnd - qStart, qEndMo3 - qStartMo3);
        }
    }

    private <T extends Comparable<T>> boolean sorted(T items[]) {
        T last = items[0], current;
        for (int i = 1; i < items.length; i++) {
            current = items[i];
            if (current.compareTo(last) < 0) {
                return false;
            }
            last = current;
        }
        return true;
    }

    private Integer[] randomIntegerArray(int size) {
        Integer integers[] = new Integer[size];
        for (int i = 0; i < size; i++) {
            integers[i] = random.nextInt(Integer.MAX_VALUE);
        }
        return integers;
    }
}
```

Die ermittelten Laufzeiten (in Millisekunden):

   Items    HS    QS  QS Mo3
-------- ----- ----- -------
  100000   117    55      76
  200000   114    76      42
  500000   308   115     114
 1000000   620   265     273
 2000000  1383   563     571
 5000000  4261  1580    1634

# Fazit

## Optimierungen

Für Quicksort wurden folgende beiden Optimierungen vorgenommen:

1. Sortierung mittels Insertion-Sort für kleine Teillisten
2. Ermittlung eines Teilerelements mittels _median of three_-Verfahren

Keine der beiden Optimierungen hatte für `n >= 1'000'000` einen messbaren
Performancegewinn zur Folge. Die Optimierungen mögen für (sehr) grosse `n`
durchaus angebracht sein; für "kleine" `n` scheinen sie aber eher nachteilig, da
der Code komplizierter wird. Dadurch liefen die Sortierungen tendenziell sogar
langsamer.

## Heap

Der Heap liess sich erstaunlich einfach iterativ implementieren. Diese
Datenstruktur kapselt das Heap-Sort-Verfahren; die Datenstruktur beinhaltet
quasi den Sortieralgorithmus.

## Laufzeitkomplexität vs. Performancemessung

Die theoretische Laufzeitkomplexität und die gemessene Performance unterschieden
sich teils deutlich. So arbeitete der Selection-Sort bei mir wesentlich
schneller als der Insertion-Sort. Bei Quick-Sort deuten meine Messungen eher auf
eine Laufzeitkomplexität von `O(n²)` als `O(n*log n)` hin.

Konstante Faktoren mögen für sehr grosse `n` nicht relevant sein. In der Praxis
hat man es aber auch oft mit eher kleinen `n` zu tun.

## Benchmark

Zum Schluss noch eine Übersicht über die Laufzeiten der verschiedenen
Sortieralgorithmen.

Einfache Sortieralgorithmen:

 Items    BS    IS    SS
------ ----- ----- -----
  1000    21     9    11
  2000    11     7     2
  5000    64    36    25
 10000   300   127    65
 20000  1226   558   294
 50000  8768  3652  1996

Höhere Sortieralgorithmen:

   Items      HS      QS  QS Mo3     QIS
-------- ------- ------- ------- -------
  100000      42      51      66      63
  200000     128      82     116     133
  500000     298     112     124     230
 1000000     706     267     272     254
 2000000    1645     579     606     570
 5000000    4757    1673    1747    1648
10000000   10665    3757    3901    3681
20000000   24049    8013    8357    7867
50000000   66566   21582   22231   22378
