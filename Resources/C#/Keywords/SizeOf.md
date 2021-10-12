## SizeOf

Returns the size in bytes of a type.

 For value types:
 
```cs
Console.Write($"Size of {typeof(T)} is {sizeof(T)}");
```

For reference types the attribute `LayoutKind.Sequential` is needed for it to work:

```cs
using System.Runtime.InteropServices;

[StructLayout(LayoutKind.Sequential)]
class Myclass {}

// ...

Marshal.SizeOf(typeof(Myclass));
```