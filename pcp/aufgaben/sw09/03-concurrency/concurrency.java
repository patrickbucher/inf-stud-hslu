import java.util.concurrent.CompletableFuture;

public class Main {
    public static void main(String[] args) {
        CompletableFuture<Long> longLastingTaskFuture = CompletableFuture.supplyAsync(() -> {
            long millis = 3000;
            sleep(millis);
            System.out.print(millis);
            return millis;
        });
        CompletableFuture<Long> evenLongerLastingTaskFuture = CompletableFuture.supplyAsync(() -> {
            long millis = 6000;
            sleep(millis);
            System.out.print(millis);
            return millis;
        });
        CompletableFuture<String> lastTaskFuture = longLastingTaskFuture
            .thenCombineAsync(evenLongerLastingTaskFuture, (s, t) -> {
                long millis = 2000;
                return "was waiting for " + (s + t + millis) + "ms";
            });
        lastTaskFuture.thenAccept((String s) -> System.out.print(s));
        System.out.println("-> Now waiting for things to happen!");
        for (int i = 0; i < 15; i++) {
            sleep(500);
            System.out.print(".");
        }
        System.out.println("-> Done.");
    }
    public static void sleep(long millis) {
        try {
            Thread.sleep(millis);
        } catch (InterruptedException iEx) {
            iEx.printStackTrace();
        }
    }
}
