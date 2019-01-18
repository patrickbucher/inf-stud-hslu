import java.util.Arrays;
import java.util.List;
import java.util.Optional;

// a) Optional<T> wurde eingeführt, da eine reduce-Operation wie die
// nachfolgende möglicherweise kein Resultat produziert. Mit den
// Optional-Methoden ifPresent und orElse kann das null-Handling elegant
// bewerkstelligt werden.

public class Main {
    public static void main(String[] args) {
        String[] namesArray = {"Joe", "Tara", "Sue", "Tim"};
        Main main = new Main();
        main.printOptional(main.reduceAndPrintStrings(namesArray), "[Default]");
        main.printOptional(main.reduceAndPrintStrings(new String[]{}), "[Default]");
    }

    // b)
    public Optional<String> reduceAndPrintStrings(String[] namesArray) {
        Optional<String> x = Arrays.asList(namesArray).stream()
            .filter(s -> s.startsWith("T"))
            .map(s -> s.toUpperCase())
            .reduce((s, t) -> s + " " + t);
        x.ifPresent(s -> System.out.println(String.format("[Debugoutput] x = %s", s)));
        return x;
    }

    // c)
    public void printOptional(Optional<String> optionalString, String defaultValue) {
        System.out.println("value = " + optionalString.orElse(defaultValue));
    }
}

