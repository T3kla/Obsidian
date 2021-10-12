## Params

Allow passing an arbitrary number of equally typed objects to a method without the need of overloading it.

```cs
void Prams(params int[] arr) { }

// Passing values will allocate an array to hold them
Params(1, 2, 3);

// You can allocate the array yourself tho
Params(new int[] { 1, 2, 3, 4 });

// Depending on the framework, the next line would allocate an empty array
// or use Array.Empty<T>, which would recycle previous arrays
Params();
```

To avoid the allocation of objects when we don’t know how the current framework handles params, introduce overloads for a common number of arguments.

```cs
void Prams0(int a) { ... }
void Prams1(int a, int b) { ... }
void Prams2(int a, int b, int c) { ... }
```

This is done in the standard library several times, for exaple for `Action` and `Func` delegates.