# Pooling

Basically faster and smaller allocation for high-count/short-lived objects. Good for value types. Pooling objects may outweigh the benefits if the usage is not ideal and it is often not necessary. Maybe ok for high creation cost objects or tremendously often created objects.

-   **Problem**. Fast creation and deletion of objects
-   **Solution**. Reuse of objects from a pre-allocated pool
-   **Benefit**. Smaller GC overhead, no allocation/initialization cost, better data locality
-   **Compromise**. Trimming policy may not be trivial, buckets are weird sized.

```cs
// Normal array creation
Point[] arr = new Point[length];

// ArrayPool
Point[] arr = ArrayPool<Point>.Shared.Rent(length);
ArrayPool<Point>.Shared.Return(arr);
```