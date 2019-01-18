public interface GeneralInterface {
    default public void doIt() {
        System.out.println("Do it the GENERAL way.");
    }
}

public interface SpecificInterface extends GeneralInterface {
    @Override
    default public void doIt() {
        System.out.println("Do it the SPECIFIC way.");
    }
}

public class Exercise1 implements GeneralInterface, SpecificInterface {
    public static void main(String[] args) {
        Exercise1 ex1 = new Exercise1();
        ex1.doIt();
    }
}

// a) Ausgabe: Do it the SPECIFIC way.
//
// b) Die Methode doIt() kann über die Interface-Hierarchie aufgelöst werden.
// Es wird diejenige verwendet, die tiefer in der Hierarchie ist.
//
// c) Ja, in diesem Fall müsste Exercise1 die Methode doIt selber
// implementieren und den Aufruf mit GeneralInterface.super.doIt() oder
// SpecificInterface.super.doIt() weiterdelegieren.
