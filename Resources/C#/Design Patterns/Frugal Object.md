# Frugal Object

Instead of allocating a list of strings we allocate an object that can take the form of 0, 1  or multiple elements. This has the benefit of better data locality because we have to follow less references when the object holds 0 or 1 elements.

-   **Problem**. Efficient storage of very small collections that usually holds 0 or 1 values
-   **Solution**. Discriminated union
-   **Benefit**. (Sometimes) Smaller memory usage, better data locality, better JIT optimizations (bound checks)
-   **Compromise**. More complex API and some overhead for checks, casts and wrappers

```cs
// Example 0
public struct FrugalObject : IList<string>
{
	private readonly object _values;
	public string this[int index]
	{
		get
		{
			if (_values == null) throw new System.IndexOutOfRangeException();
			if (index == 0) return (_values is string str) ? str : ((string[])_values)[0];
			return ((string[])_values)[index];
		}
		set { }
	}
	[ . . . ]
}
```

```cs
// Example 1
public struct CompactList<T> : IEnumerator<T>
{
	private T singleValue;
	private List<T> multiValue;
	[ . . . ]
}
```