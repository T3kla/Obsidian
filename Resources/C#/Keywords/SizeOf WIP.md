**

## SizeOf

This function should display nicely the size of a given unmanaged Type. Including structs.

  
 unsafe void SizeOf<T>() where T : unmanaged { Log.Write($"Size of {typeof(T)} is {sizeof(T)}"); }**