## Fixed

Fix a value so the GC can’t touch it. Need the keyword unsafe.

```cs
string text = "text";

fixed (char* c = text)
{
	c[0] = char.ToUpper(c[0]);
}

Console.Write(text);
```