using System;

public class Test
{
    public static void Main(string[] args)
    {
        new Test();
    }
    public Test()
    {
        Test1();
        Test2();
    }
    public void Test1()
    {
        int a = 1; int b = 2; int c = 3; int d = 4; int e = 5;
        Method1(ref a, out b, out c, ref d, ref e);
        Console.WriteLine("a={0} b={1} c={2} d={3} e={4}", a, b, c, d, e);
    }
    public void Method1(ref int a, out int b, out int c, ref int d, ref int e)
    {
        a = a + 1;
        b = 2;
        c = 2 * d;
        d = c + e;
    }
    public void Test2()
    {
        C a = new C();
        C b = new C(); b.X = 2;
        C c = new C(); c.X = 3;
        C d = new C();
        C e = c;
        Method2(out a, ref b, c, d, e);
        Console.WriteLine("a={0} b={1} c={2} d={3} e={4}",a.X, b.X, c.X, d.X, e.X);
    }
    public void Method2(out C a, ref C b, C c, C d, C e)
    {
        b = new C();
        a = b;
        c = b;
        d = new C(); d.X = 7;
        e.X = 9;
    }
    public class C
    {
        public int X;
    }
}
