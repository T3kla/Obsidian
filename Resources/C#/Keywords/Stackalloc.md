## Stackalloc

Used to allocate stuff in the stack. Each method can allocate approximately 1mb extra from its default allocation. Manually allocating more than that can cause a StackOverflowException to be thrown. Mircrosft recommends using Span\<T> or ReadOnlySpan\<T> types to work with stack allocated memory whenever possible. 

[Do and Don’ts](https://vcsjones.dev/stackalloc/)

Declaration.

```cs
Span<int> numbers = stackalloc int[] { 1, 2, 3, 4, 5, 6 };
// Or unsafe
int* numbers = stackalloc int[] { 1, 2, 3, 4, 5, 6 };
```

Choose between stack or heap depending on the memory needed.
Usually less than 1 megaByte should be ok.

 ```cs
int length = 420;

Span<byte> buffer = length <= 1024 ? stackalloc byte[length] : new byte[length];
// Or unsafe
byte* buffer = length <= 1024 ? stackalloc byte[length] : new byte[length];
```

Since C# 8.0, it can be used inside other expressions.
								  
```cs
// Implicit conversion to ReadOnlySpan
int ind = numArray.IndexOfAny(stackalloc[] { 2, 4, 6, 8 }); 
```

Making a list of ordered numbers. This snippet works with Span\<T>, ReadOnlySpawn\<T> and pointers depending on the .Net version and/or installed packages.

```cs
unsafe
{
	var length = 420;
	var numbers = stackalloc int[length];
	for (var i = 0; i < length; i++)
		numbers[i] = i;
}
```
