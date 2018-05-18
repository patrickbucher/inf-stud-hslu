class StringList
{
    public string[] Data;

    private int size;

    public int Size
    {
        get { return size; }
        set
        {
            size = value;
            Data = new string[value];
        }
    }

    public string this[int index]
    {
        get { return Data[index]; }
        set { Data[index] = value; }
    }
}
