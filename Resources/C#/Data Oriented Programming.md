# Data Oriented Programming

[From](https://gameprogrammingpatterns.com/data-locality.html)

## Data locality

Modern CPUs have **caches to speed up memory access**. These can access memory **adjacent to recently accessed memory much quicker**. Take advantage of that to improve performance by **increasing data locality** — keeping data in **contiguous memory in the order that you process it**.

- **Problem**. Cache misses hinders CPU performance
- **Solution**. Better data locality
- **Benefit**. Less often memory accesses
- **Compromise**. Less abstraction

