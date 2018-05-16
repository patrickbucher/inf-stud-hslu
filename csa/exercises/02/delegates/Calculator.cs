using System;

class Calculator
{
    public delegate double Calculate(double x, double y);

    public static double Add(double x, double y)
    {
        return x + y;
    }

    public static double Subtract(double x, double y)
    {
        return x - y;
    }

    public static double Multiply(double x, double y)
    {
        return x * y;
    }

    public static double Divide(double x, double y)
    {
        return x / y;
    }

    public static void Main(string[] args)
    {
        Console.WriteLine("Basic Calculator");    
        string selection = "";
        do
        {
            Console.WriteLine("Type: + - * /");
            selection = Console.ReadLine();
            Calculate method;
            switch (selection)
            {
                case "+":
                    method = Add;
                    break;
                case "-":
                    method = Subtract;
                    break;
                case "*":
                    method = Multiply;
                    break;
                case "/":
                    method = Divide;
                    break;
                default:
                    continue;
            }
            double a = readNumber("Number A: ");
            double b = readNumber("Number B: ");
            double result = method(a, b);
            Console.WriteLine("Result: " + result);
        } while (!selection.Equals(""));
    }

    public static double readNumber(string prompt)
    {
        double value = 0.0;
        do
        {
            Console.Write(prompt);
            value = Convert.ToDouble(Console.ReadLine());
        } while (value == 0.0);
        return value;
    }
}
