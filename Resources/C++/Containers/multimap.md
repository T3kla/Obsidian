# `multimap`

## equals_range
Returns range as `pair` in which `pair.first` is the begining iterator and `pair.second` is the end iterator.

```cpp
multimap<int,string> map;
auto range = map.equal_range(id);
for (auto it = range.first; it != range.second; it++)
	cout << it->second;
```