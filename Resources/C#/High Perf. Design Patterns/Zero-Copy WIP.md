# Zero-Copy 

`Span<T>`, ref passing, ref return and pipelines.
- **Problem**. Operations on “sub-data” and the need of representing and passing parts of this object
- **Solution**. Allow the representation of slices of a bigger object
- **Benefit**. No allocations
- **Compromise**. `Span<T>`can not be used with async/await, (`Memory<T>` can tho)**