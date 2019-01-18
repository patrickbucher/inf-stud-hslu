public class Main {
    // a)
    @FunctionalInterface
    interface TripleIntOperator {
        public Integer apply(int a, int b, int c);
    }
    public static void main(String[] args) {
        TripleIntOperator tio = (a, b, c) -> a + b + c;
        System.out.println(tio.apply(1, 2, 3));
    }
}

// b) apply
// c) Integer
