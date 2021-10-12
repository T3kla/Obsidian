# Readonly
Readonly makes the variable assignable only inside the construction code block. Outside of it, the variable can not be reassigned.

This doesn't mean that the variable is immutable tho. For example, a `public readonly List<T>` could continue to add and remove members regardless.

```cs
    public class MyClass
    {
        public readonly List<Point> list;
        
        public MyClass()
        {
            list = new List<Point>(10);   // Legal
        }
        
        public void Init()
        {
            list.Add(new Point(1,1));    // Legal
            list = new List<T>();   // Ilegal
        }
    }
```