**

# Span

## Span<T>

Enables the representation of contiguous regions of arbitrary memory, regardless of whether that memory is associated with a managed object, is provided by native code via interop, or is on the stack. And it does so while still providing safe access with performance characteristics like that of arrays.

[https://www.meziantou.net/split-a-string-into-lines-without-allocation.htm](https://www.meziantou.net/split-a-string-into-lines-without-allocation.htm)

  

 var arr = new byte[10];

 Span<byte> bytes = arr; // Implicit cast from T[] to Span<T>

  

Can be sliced to represent lower chunks of a bigger Span.

  

 Span<byte> slicedBytes = bytes.Slice(start: 5, length: 2);

 Log.Write($"This returns true {arr[2] == bytes[2]}");

  

Can be directed to stack memory.

  

 Span<byte> stackBytes = stackalloc byte[2];

  

Can make mutable structs accessible in ways IEnumerables or IEnumerators can’t because it uses a ref-indexer instead of a value-indexer, so returned values are references of actual values instead of inmutable copies.

  

 struct MStruct { public int Value; }

 [...]

  

 // Legal

 Span<MStruct> span = new MStruct[1];

 span[0].Value = 42;

  

 // Ilegal

 var list = new List<MStruct> { new MStruct() };

 list[0].Value = 42; // Error CS1612: the return value is not a variable

 foreach (var strc in span)

 strc.Value = 42; // Error CS1654: more or less the same thing ^

  

## ReadOnlySpan<T>

Same thing but inmutable.

  

 string str = "Hello, World";

  

 // Allocate

 string worldString = str.Substring(startIndex: 7, length: 5);

  

 // Do not Allocate

 ReadOnlySpan<char> worldSpan = str.AsSpan().Slice(start: 7, length: 5);

 worldSpan[0] = 'a'; // Error CS0200: indexer cannot be assigned to

  
**