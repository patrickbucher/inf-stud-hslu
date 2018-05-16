using System;

class Arrays
{
    static void Main(string[] args)
    {
        oneDimensionalArrays();
        multiDimensionalJaggedArrays();
        multiDimensionalRectangularArrays();
    }

    private static void printArray(int[] array)
    {
        foreach (int i in array)
        {
            Console.Write(i + " ");
        }
        Console.WriteLine();
    }

    private static void printArray(Object[] array)
    {
        foreach (Object o in array)
        {
            Console.WriteLine(o);
        }
    }

    private static void printTwoDimensionalArray(int[][] array)
    {
        foreach (int[] i in array)
        {
            foreach (int j in i)
            {
                Console.Write(j + " ");
            }
            Console.WriteLine();
        }
    }

    private static void printTwoDimensionalArray(int[,] array)
    {
        foreach (int i in array)
        {
            Console.Write(i + " ");
        }
        Console.WriteLine();
    }

    private static void oneDimensionalArrays()
    {
        int[] a = {1, 2, 3};
        int[] b = new int[]{4, 5, 6};
        int[] c = new int[3];
        c[0] = 7;
        c[1] = 8;
        c[2] = 9;
        printArray(a);
        printArray(b);
        printArray(c);

        Person[] people = new Person[3];
        people[0] = new Person("Hans", "Meier");
        people[1] = new Person("Franz", "Huber");
        people[2] = new Person("Josy", "Müller");

        printArray(people);
    }

    private static void multiDimensionalJaggedArrays()
    {
        int[][] a = new int[3][];
        a[0] = new int[]{1, 2, 3};
        a[1] = new int[]{4, 5};
        a[2] = new int[]{6, 7, 8, 9};
        printTwoDimensionalArray(a);
    }

    private static void multiDimensionalRectangularArrays()
    {
        int[,] a = new int[2, 2];
        a[0,0] = 1;
        a[0,1] = 2;
        a[1,0] = 3;
        a[1,1] = 4;
        printTwoDimensionalArray(a);
    }
}
