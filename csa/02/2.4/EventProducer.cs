public delegate void MyEventHandler(object sender, MyEventArgs args);

public class EventProducer
{
    public event MyEventHandler MyEvent;

    public void OnMyEvent(string data)
    {
        if (MyEvent != null)
        {
            MyEvent(this, new MyEventArgs(data));
        }
    }
}
