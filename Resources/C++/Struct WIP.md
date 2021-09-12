# Classes and Structs

## Struct

Default accessibility level is public.

 struct int2

 {

 int x, y;

 int2(int x, int y) : x(x), y(y) {}

 bool operator==(const int2 &a) const { return (x == a.x && y == a.y); }

 friend ostream &operator<<(ostream &os, const int2 &a) { return (os << "(" << a.x << "," << a.y << ")"); }

 };

## Constructor

## Struct Hash function

Custom structs don't have hash functions so can’t be used as keys for unordered_set or unordered_multimap.

 struct int2

 {

 int x, y;

 int2(int x, int y) : x(x), y(y) {}

 bool operator==(const int2 &a) const { return (x == a.x && y == a.y); }

 friend ostream &operator<<(ostream &os, const int2 &a) { return (os << "(" << a.x << "," << a.y << ")"); }

 };

  

 template <> struct std::hash<int2>

 {

 size_t operator()(const int2 &k) const

 {

 size_t res = 17;

 res *= 31 + hash<int>()(k.x);

 res *= 31 + hash<int>()(k.y);

 return res;

 }

 };
