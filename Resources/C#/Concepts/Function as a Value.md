# Delegates

A container of methods with the same signature (return type and arguments). On compile time, they are declared with the "extern"  keyword. On run time, this containers are defined with the functions they must hold.

Similar to interfaces, delegates make the promise that whatever is inside will have the same signature as the delegate itself.

```cs
public delegate void DVoid();

public class IntDelegate
{
    public DVoid OnSomethingHappens;         // Container of methods with DVoid signature
    public void DoSomething(DVoid funct) {}  // Accepts a Dvoid delegate or functions with
}                                            // the same signature as DVoid
```

---

# Func

Generic delegate that returns the type corresponding to the last element of its declaration.

```cs
Func<int, int, int> Add = (int a, int b) => a + b;
Console.WriteLine(Add(1,2)); // Writes: 3
```

```cs
Func<TResult>
Func<T, TResult>
Func<T1, T2, TResult>
Func<T1, ... , T16, TResult>
```

---

# Action

Generic delegate that returns void.

```cs
Action<int, int> Add = (int a, int b) => a + b;
```

```cs
Action
Action<T>
Action<T1, T2>
Action<T1, ... , T16>
```

---

# Lambdas

They are anonymous functions, usually used to define functionality in places where we don't feel the need of writing a separate function.

They are defined on run time with an unknown name, hence the definition: "Anonymous Functions".

```cs
// Lambda syntaxis: (arguments) = (result)
Func<int, int, int> Add = (int a, int b) => a + b;
Action<int, int> PrintAdd = (int a, int b) => Console.WriteLine(a + b);

// This two are totally equivalent
Func<int, int> myFunc = x => x + 1;
Func<int, int> myFunc = delegate(int x) { return x + 1; };
```

---

# Closures

When lambdas reference variables that are not in their enclosing scope, they have to be copied and hold inside the generated lambda container. If this weren't the case, it would fall out of scope and the lambda would throw a `NullReferenceException` each time it tried to read the free variable.

- **Free variable**: a variable which is referenced in a function, not being a parameter of the function, nor a local variable of the function, nor a member of an enclosing class.

```cs
static void Main(string[] args)
{
    var inc = GetAFunc();
    Console.WriteLine(inc(5)); // Writes: 7
    Console.WriteLine(inc(6)); // Writes: 9
}

public static Func<int,int> GetAFunc()
{
    // This variable will cease to exist after this method is done running
    int myVar = 1;
    
    // Generate a delegate that holds a lambda that contains "myVar".
    //  Even tho "myVar" will cease to exist, the copy won't,
    //  so the lambda can still execute without errors.
    Func<int, int> inc = var1 => { ++myVar; return var1 + myVar; };
    
    return inc;
}
```

---

# References
- [**RawCoding** - C# Delegates Explained || +Func +Action +Closure](https://www.youtube.com/watch?v=KaxNwGA9fiY)
- [**Justin Etheredge** - A Simple Explanation of C# Closures](https://www.simplethread.com/c-closures-explained/)