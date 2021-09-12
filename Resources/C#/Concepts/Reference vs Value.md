# Reference vs Value

[**Nick Chapsas** - Where are types allocated in .NET and why people get it so wrong](https://www.youtube.com/watch?v=jONSIhMST9E)

```html
<iframe width="560" height="315" src="https://www.youtube.com/embed/jONSIhMST9E" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
```

## Reference Types
- Keyword:  `class`
- Allocated on the heap
- A variable for this object is a reference to this object
- Passed around by reference
- Assignment is a copy of the reference

## Value Types
- Keyword:  `struct`
- Allocated on the stack or embedded in a class
- A variable for this object is this object
- Passed around by value
- Assignment is a copy of the object
