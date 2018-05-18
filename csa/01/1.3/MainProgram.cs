using System;

public class MainProgram
{
    public static void Main(string[] args)
    {
        ClassA a = new ClassA("A");
        ClassB b0 = new ClassB();
        ClassB b1 = new ClassB("B1");
        ClassB b2 = new ClassB("B2", 2);

        ClassA aa = new ClassA("AA");
        ClassA ab = new ClassB("AB");
    }
}
