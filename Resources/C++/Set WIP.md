# Set

## Set .insert return pair

The returning value of the .insert method of a set will return a pair in which the first element is an iterator to the inserted array and the second element is a bool which if true means it could insert the element, and if false, it couldn't.

```cpp
set<int> unique { 0, 1 };
int a = 2;

// insert returns a pair<iterator, bool>
auto it = unique->insert(a);

if (it.second == true)
    // stuff was inserted correctly
else
    // stuff couldn't be inserted
```