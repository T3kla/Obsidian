## SizeOf

Returns the size in bytes of a type.

 For value types:
 
```cs
Console.Write($"Size of {typeof(T)} is {sizeof(T)}");
```

For random types:

```cs
Marshal.SizeOf(typeof(Myclass));

// LayoutKind.Sequential needed for it to work

using System.Runtime.InteropServices;

[StructLayout(LayoutKind.Sequential)]
class Myclass {}
```