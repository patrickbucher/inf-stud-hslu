import java.util.Random;
import java.util.concurrent.atomic.AtomicInteger;

public class Main {
    public static void main(String[] args) {
        Random random = new Random(System.currentTimeMillis());
        AtomicInteger n = new AtomicInteger();
        boolean found = random.ints().anyMatch(i -> {
            n.incrementAndGet();
            return i > 10_000 && i < 12_000;
        });
        System.out.println("Found suitable number at stream position " + n.get());
    }
}
