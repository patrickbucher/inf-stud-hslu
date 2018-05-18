using System;

class HelloWorld
{
    private void PrintMessage(string msg, bool upperCase)
    {
        if (upperCase)
        {
            msg = msg.ToUpper();
        }
        Console.WriteLine(msg);
    }

    static void Main(string[] args)
    {
        HelloWorld hello = new HelloWorld();
        hello.PrintMessage("Hello World", false);
        hello.PrintMessage("Hello World", true);
    }
}
