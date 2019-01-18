import java.util.Comparator;
import java.util.List;
import java.util.Random;
import java.util.StringJoiner;
import java.util.stream.IntStream;
import java.util.stream.Collectors;

public class Main {
    public void generateSortAndPrintRandomInts(int numberOfVals, int maxValueExc) {
        StringJoiner joiner = new StringJoiner(" > ", "reverse ordered list = { ",  " }");
        List<Integer> ints = new Random(System.currentTimeMillis())
            .ints(0, maxValueExc)
            .limit(numberOfVals)
            .boxed()
            .collect(Collectors.toList());
        ints.sort(Comparator.reverseOrder());
        ints.forEach(i -> joiner.add(String.valueOf(i)));
        System.out.println(joiner);
    }
    public static void main(String[] args) {
        new Main().generateSortAndPrintRandomInts(7, 100);
    }
}
