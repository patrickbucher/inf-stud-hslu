using System;

public class ClassB : ClassA
{
    public ClassB(string msg, int count)
    {
        Console.Write("B:" + msg);
        for (int i = 0; i < count; i++)
        {
            Console.Write(".");
        }
        Console.Write(" ");
    }

    public ClassB(string msg) : this(msg, 1) {}

    public ClassB() : this("B0", 0) {}
}
