**

## Stackalloc

Used to allocate stuff in the stack. Each method can allocate approximately 1mb extra from its default allocation. Manually allocating more than that can cause a StackOverflowException to be thrown. Mircrosft recommends using Span<T> or ReadOnlySpan<T> types to work with stack allocated memory whenever possible. Check this [Do and Don’ts](https://vcsjones.dev/stackalloc/).

  

 int length = 3;

 Span<byte> buffer = length <= 1024 ? stackalloc byte[length] : new byte[length];

  

Since C# 8.0, it can be used inside other expressions.

  

 Span<int> numbers = stackalloc[] { 1, 2, 3, 4, 5, 6 };

 int ind = numbers.IndexOfAny(stackalloc[] { 2, 4, 6, 8 }); // Implicit conversion to ReadOnlySpan

  

Work with Span<T>, ReadOnlySpawn<T>, arrays and pointers.

  

 unsafe

 {

 int length = 3;

 int* numbers = stackalloc int[length];

 for (var i = 0; i < length; i++) numbers[i] = i;

 }

**