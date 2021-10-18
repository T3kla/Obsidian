# Set

## `.insert`

The returning value of the '`.insert`' method of a set will return a pair `pair<iterator, bool>` in which the first element is an iterator to the inserted array and the second element is a bool which if true means it could insert the element, and if false, it couldn't.

```cpp
set<int> unique { 0, 1 };
auto it = unique.insert(2); // std::pair<std::set<int>::iterator, bool> it

if (it.second == true)
    // stuff was inserted correctly
else
    // stuff couldn't be inserted
```