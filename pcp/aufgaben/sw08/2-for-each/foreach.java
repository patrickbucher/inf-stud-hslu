import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        printNumbersAndSquares(new Integer[]{1, 2, 3, 5, 8});
    }
    static void printNumbersAndSquares(Integer[] numbers) {
        Arrays.asList(numbers).forEach(i -> System.out.printf("%d: %d\n", i, i*i));
    }
}
