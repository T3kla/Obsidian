# Heap vs Stack

[**Stack Overflow** - Arrays, heap and stack and value](https://stackoverflow.com/questions/1113819/arrays-heap-and-stack-and-value-types)

- The heap is general purpose memory, while the stack allocated for each method
- Each method asks (at least) for enough memory to allocate local variables
- The stack memory block is returned on method exit
- Since value types are data themselves, they live on the stack
- Allocations in the stack are cheap and non GC taxing, but space is very limited
