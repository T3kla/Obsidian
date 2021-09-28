# Stack-Based Data

Structs provide good data locality, can be enregistered, no metadata, no object header… but they can be boxed. There are cool structs like `ValueTuple` and `ValueTask`. We can also use ref structs, fixed size buffers and `stackalloc`. `Span<T>` can hold `stackalloc` chunks of memory. `stackalloc` should never stack more than 1kb.

-   **Problem**. Allocate a lot of small and temporary objects which overloads the GC
-   **Solution**. Avoid the heap with the help of struct, `ref struct` and `stackalloc`
-   **Benefit**. No GC overhead
-   **Compromise**. Stack allocations can cause `StackOverflowException`, stack allocated memory have to be zeroed
    
```cs
 public double ByStackalloc()
 {
	 Span<Point> arr = stackalloc Point[length];
	
	 for (int i = 0; i < length; i++)
	 	arr[i] = new(1, 2);
								
	 return ProcessBatch(arr);
 }
```