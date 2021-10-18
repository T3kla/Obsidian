# Const

## `const` arguments

-   `void f1(const string& s);` _// Pass by reference-to-`const`_
-   `void f2(const string* sptr);` _// Pass by pointer-to-`const`_

## `const` function
Written after function arguments, ensure that the function wont try to change instance members. This enforces called functions to be const too.
```cpp
float magnitude() { return sqrt(x * x + y * y + z * z); } // <- error because not const
point3d normalized() const { return *this / this->magnitude(); }
```

---

# References

-  [Const Correctness, C++ FAQ (isocpp.org)](https://isocpp.org/wiki/faq/const-correctness#overview-const)