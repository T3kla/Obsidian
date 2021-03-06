# Closures 
See: [[Function as a Value]]

Compiler rewrites closures as new methods and/or classes that allow the retrieval of objects or the execution of specified behavior. Lambdas and Linq are examples of this.

---

# Boxing

The practice of passing a value type to a method expecting a reference type. This generates a new copy of the value type in the heap, hence “the box”, and makes the method work with that instead of the original object. Boxing can generate unexpected allocations.

```cs
    // New point declaration
    Point p = new Point(0,0);

    // WriteLine accepts objects, create a copy of them in the heap and then use them
    Console.WriteLine("number: {0}", p);
```

---

# Iterators

Code is rewritten as a state machine. The allocation cost here is probably small but still, returning a collection should be cheaper.

---

# Async/Await

Code is rewritten as a state machine which has to be allocated alongside a task method builder. Task and `Task<T>` can be not worth the allocation in use cases where we expect a synchronous return or no reuse. In this cases we may be able to use `ValueTask<T>`

---

# Linq

It converts itself into classes and methods that get allocated and called without your control. Use for, foreach and if when possible. Also see [Optimizing Linq](https://mattwarren.org/2016/09/29/Optimising-LINQ/) for info about this two:

-   [**Roslyn Linq Rewrite**](https://github.com/antiufo/roslyn-linq-rewrite): compiles C# code by first rewriting the syntax trees of LINQ expressions using plain procedural code, minimizing allocations and dynamic dispatch
    
-   [**LinqOptimizer**](http://nessos.github.io/LinqOptimizer/): automatic query optimizer-compiler for Sequential and Parallel LINQ. LinqOptimizer compiles declarative LINQ queries into fast loop-based imperative code.