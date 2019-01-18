import java.util.Arrays;

public class Main {
    public String processNames(String[] names) {
        return Arrays.stream(names)
            .filter(s -> s.length() >= 3 && s.length() <= 4 )
            .map(s -> s.toUpperCase())
            .reduce("", (l, r) -> l + r + " ");
    }
    public static void main(String[] args) {
        String[] names = new String[]{"Susanna", "Joe", "Lu", "Timmy", "Rafael", "Lisa"};
        String result = new Main().processNames(names);
        System.out.println(result);
    }
}
