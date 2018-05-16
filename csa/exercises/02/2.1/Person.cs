using System;

class Person
{
    public string firstName { get; set; }
    public string lastName { get; set; }

    public Person(string firstName, string lastName)
    {
        this.firstName = firstName;
        this.lastName = lastName;
    }

    public override string ToString()
    {
        return "Hi, my name is " + firstName + " " + lastName;
    }
}
