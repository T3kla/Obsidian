## Unsafe

Allow the use of pointers and other scary stuff.

```cs
private unsafe void Unsafe()
{
	int someInt = 9;
	int* p_someInt = &someInt;
	Console.Write(p_someInt->ToString());
}
```