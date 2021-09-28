# Struct of Arrays

We use classes and structs to encapsulate fields. Whenever these get created, they get allocated in a random spot in memory. When trying to read them, Random Memory Access calls destroys performance.

| Address | Data |
| -- | -- |
| 0 | struct_0 |
| 11 | struct_1 |
| 30 | struct_2 |
| 42 | struct_3 |

Since structs are laid out sequentially by default, creating an array of structs is pretty efficient because the processor can easily calculate where the data will be and optimize for it.

| Address | Data |
| -- | -- |
| 0 | age: 0 |
| 1 | health: 0 |
| 2 | age: 1 |
| 3 | health: 1 |

Even more performant could be to create a struct of arrays. This design allows each memory call to retrieve relevant data, since it must always return certain amount (32 or 64 bytes).

| Address | Data |
| -- | -- |
| 0 | age: 0 |
| 1 | age: 1 |
| 2 | health: 0 |
| 3 | health: 1 |

-   **Problem**. Processing lots of data inefficiently due to memory access time
-   **Solution**. Design data structures to leverage data locality and sequential access
-   **Benefit**. Much better memory access time thanks to sequential reading 
-   **Compromise**. Much worse design and violation of object-oriented principles like encapsulation

```cs
// Structs will order themselves sequentially by default
public struct Struct
{
	// Data
	public int age;
	public int health;
	[ . . . ]
	public float score;
	
	// Processors
	public void UpdateScore() => score = age * health * (isSmoking ? 0.8f : 1f) * earnings;
}

// Force sequential reading of interal data
public struct StructOfArrays
{
	// Data
	public int numberOfCustomers;
	public int[] age;
	public int[] health;
	[ . . . ]
	public float[] scores;

	// Processors
	// It is important that data processors are inside the class for better data locality
	public void UpdateScores()
	{
		for (int i = 0; i < numberOfCustomers; i++)
			score[i] = age[i] * health[i] * (isSmoking[i] ? 0.8f : 1f) * earnings[i];
	}
}
```