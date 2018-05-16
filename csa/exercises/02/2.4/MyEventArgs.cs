using System;

public class MyEventArgs : EventArgs
{
    public MyEventArgs(string eventData)
    {
        EventData = eventData;
    }

    public string EventData
    {
        get; 
        set;
    }
}
