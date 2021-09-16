Since C# 7.2 you can apply reference mechanics to value types.

---

# `in`

Allow the passing of a value type or a reference type as `readonly` reference.

```cs
public void In_0(in int a) { }
public void In_1(in string a) { }
```

---

# `ref` locals and `ref` returns

Allows the creation of references for value types and even return them.
Allow the use of a ref to a value type inside a method, and the return of a ref to a value type.

```cs
public static Point[] vec = new Point[] { new(1, 1), new(2, 2) };
public static ref Point Refs(ref Point[] arr)
{
    ref var a = ref arr[0];     // ref local
    a.x = 3;                    // modifying mutable struct by ref
    return ref a;               // ref return
}
```

---

# `readonly struct`

Forces the struct to implement readonly fields and won’t compile otherwise.

```cs
readonly struct Point
{
    public readonly int x;
    public readonly int y;
}
```

---

# `ref struct`

Forces the struct to live only on the stack. Only other ref structs themselves can have fields which are ref structs.

```cs
ref struct Point
{
    public int x;
    public int y;
}
```