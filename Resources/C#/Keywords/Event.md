# Event

Events are a special kind of multicast delegate that can only be invoked from within the class or struct where they are declared (the publisher class).

```cs
public class Events
{
	public static Action SomeDelegate;
	public static event Action SomeEvent;
}

public class Subscriber
{
	private void Subscribe()
	{
		Events.SomeDelegate += Handler;
		Events.SomeDelegate -= Handler;
		Events.SomeDelegate = null;
		Events.SomeDelegate.Invoke();
		
		Events.SomeEvent += Handler;
		Events.SomeEvent -= Handler;
		Events.SomeEvent = null; 		// Compile error CSharp(CS0070)
		Events.SomeDelegate.Invoke(); 	// Compile error CSharp(CS0070)
	}

	private void Handler() {...}
}
```

---

# References
- [event - C# Reference | Microsoft Docs](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/event)