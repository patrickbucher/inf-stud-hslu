import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<String> strings = Arrays.asList("Java", "is", "cool");
        System.out.println(java8(strings));
        System.out.println(java7(strings));
    }
    public static String java8(Iterable<String> strings) {
        String message = String.join(" ", strings);
        return message;
    }
    // a)
    public static String java7(Iterable<String> strings) {
        Iterator<String> iterator = strings.iterator();
        StringBuilder str = new StringBuilder();
        while (iterator.hasNext()) {
            str.append(iterator.next());
            if (iterator.hasNext()) {
                str.append(" ");
            }
        }
        return str.toString();
    }
    // b) Typisch ist der Loop und die Verzweigung innerhalb des Loops.
    // c) Das Verketten von Funktionsaufrufen, das Fehlen von Variablen zur Zwischenspeicherung.
    // d) Man arbeitet auf einer höheren Abstraktionsstufe: Näher am Problem, weiter weg vom Computer.
}
