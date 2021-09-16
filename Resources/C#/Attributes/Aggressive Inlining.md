Obligates the JIT compiler to inline a given method. Inlining reduces jumps between calls.
- Very small methods used very commonly
- Big methods that are called just once (these will probably already be inlined by JIT)

```cs
[MethodImpl(MethodImplOptions.AggressiveInlining)]
public static int Method() => 1;
```

---

# References
[**DotNetPerls** - Aggressive Inlining](https://www.dotnetperls.com/aggressiveinlining).