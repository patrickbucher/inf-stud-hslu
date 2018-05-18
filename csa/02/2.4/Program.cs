public class Program
{
    public Program()
    {
        EventProducer producer = new EventProducer();
        EventConsumer consumer1 = new EventConsumer(producer);
        EventConsumer consumer2 = new EventConsumer(producer);
        producer.OnMyEvent("Event fired...");
    }

    static void Main(string[] args)
    {
        Program prog = new Program();
    }
}
