using System;

public class EventConsumer
{
    private EventProducer producer;

    public EventConsumer(EventProducer producer)
    {
        producer.MyEvent += HandleEvent;
    }

    public void HandleEvent(object sender, MyEventArgs args)
    {
        Console.WriteLine(args.EventData);
    }
}
