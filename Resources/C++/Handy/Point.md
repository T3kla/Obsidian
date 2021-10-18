# Point

```cpp
#include <iostream>

using namespace std;

struct point
{
    float x, y;
    point(float _x = 0, float _y = 0) : x(_x), y(_y) {}
    float magnitude() { return sqrt(x * x + y * y); }
    point normalized() { return *this / this->magnitude(); }
    point operator+(const point &b) { return point(this->x + b.x, this->y + b.y); }
    point operator-(const point &b) { return point(this->x - b.x, this->y - b.y); }
    point operator*(const float &b) { return point(this->x * b, this->y * b); }
    point operator/(const float &b) { return point(this->x / b, this->y / b); }
    bool operator==(const point &b) { return (this->x == b.x) && (this->y == b.y); }
    bool operator!=(const point &b) { return (this->x != b.x) || (this->y != b.y); }
    friend ostream &operator<<(ostream &os, const point &b) { return os << '(' << b.x << ',' << b.y << ')'; }
};

struct point3d
{
    float x, y, z;
    point3d(const float &_x = 0, const float &_y = 0, const float &_z = 0) : x(_x), y(_y), z(_z) {}
    float magnitude() { return sqrt(x * x + y * y + z * z); }
    point3d normalized() { return *this / this->magnitude(); }
    point3d operator+(const point3d &b) { return point3d(this->x + b.x, this->y + b.y, this->z + b.z); }
    point3d operator-(const point3d &b) { return point3d(this->x - b.x, this->y - b.y, this->z - b.z); }
    point3d operator*(const float &b) { return point3d(this->x * b, this->y * b, this->z * b); }
    point3d operator/(const float &b) { return point3d(this->x / b, this->y / b, this->z / b); }
    bool operator==(const point3d &b) { return (this->x == b.x) && (this->y == b.y) && (this->z == b.z); }
    bool operator!=(const point3d &b) { return (this->x != b.x) || (this->y != b.y) || (this->z != b.z); }
    friend ostream &operator<<(ostream &os, const point3d &b) { return os << '(' << b.x << ',' << b.y << ',' << b.z << ')'; }
};

struct point_i
{
    int x, y;
    point_i(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    float magnitude() { return sqrt(x * x + y * y); }
    point_i normalized() { return *this / this->magnitude(); }
    point_i operator+(const point_i &b) { return point_i(this->x + b.x, this->y + b.y); }
    point_i operator-(const point_i &b) { return point_i(this->x - b.x, this->y - b.y); }
    point_i operator*(const int &b) { return point_i(this->x * b, this->y * b); }
    point operator/(const int &b) { return point(round(this->x / b), round(this->y / b)); }
    point operator*(const float &b) { return point(round(this->x * b), round(this->y * b)); }
    point operator/(const float &b) { return point(round(this->x / b), round(this->y / b)); }
    bool operator==(const point_i &b) { return (this->x == b.x) && (this->y == b.y); }
    bool operator!=(const point_i &b) { return (this->x != b.x) || (this->y != b.y); }
    friend ostream &operator<<(ostream &os, const point_i &b) { return os << '(' << b.x << ',' << b.y << ')'; }
};

struct point3d_i
{
    int x, y, z;
    point3d_i(const int &_x = 0, const int &_y = 0, const int &_z = 0) : x(_x), y(_y), z(_z) {}
    float magnitude() { return sqrt(x * x + y * y + z * z); }
    point3d_i normalized() { return *this / this->magnitude(); }
    point3d_i operator+(const point3d_i &b) { return point3d_i(this->x + b.x, this->y + b.y, this->z + b.z); }
    point3d_i operator-(const point3d_i &b) { return point3d_i(this->x - b.x, this->y - b.y, this->z - b.z); }
    point3d_i operator*(const int &b) { return point3d_i(this->x * b, this->y * b, this->z * b); }
    point3d operator/(const int &b) { return point3d(round(this->x / b), round(this->y / b), round(this->z / b)); }
    point3d operator*(const float &b) { return point3d(round(this->x * b), round(this->y * b), round(this->z * b)); }
    point3d operator/(const float &b) { return point3d(round(this->x / b), round(this->y / b), round(this->z / b)); }
    bool operator==(const point3d_i &b) { return (this->x == b.x) && (this->y == b.y) && (this->z == b.z); }
    bool operator!=(const point3d_i &b) { return (this->x != b.x) || (this->y != b.y) || (this->z != b.z); }
    friend ostream &operator<<(ostream &os, const point3d_i &b) { return os << '(' << b.x << ',' << b.y << ',' << b.z << ')'; }
};
```