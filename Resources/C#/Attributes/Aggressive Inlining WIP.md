**

## Aggressive Inlining

Obligates the JIT compiler to inline a given method. Inlining reduces jumps between calls. Inlining small methods is usually good. Inlining big methods can be good if their appearance in the codebase is very, very limited. [Link](https://www.dotnetperls.com/aggressiveinlining).

  

 [MethodImpl(MethodImplOptions.AggressiveInlining)]

 public static int Method() => 1;**