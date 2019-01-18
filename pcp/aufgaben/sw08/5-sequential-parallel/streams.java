import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        // a)
        System.out.println("a) sequential");
        IntStream is = IntStream.iterate(0, i -> i + 1).limit(100);
        is.forEach(i -> System.out.print(i + ", "));

        // b)
        System.out.println("\nb) parallel");
        is = IntStream.iterate(0, i -> i + 1).limit(100);
        is.parallel().forEach(i -> System.out.print(i + ", "));
    }
}
