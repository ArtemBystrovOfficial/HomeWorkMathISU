
#include "../headers/Vectors.hpp"

Vec operator+(const Vec& v1,const Vec& v2)
{
    return { v1.x + v2.x, v1.y + v2.y };
}

Vec operator-(const Vec& v1, const Vec& v2)
{
    return { v1.x - v2.x, v1.y - v2.y };
}

Vec operator*(const Vec& v1, const Vec& v2)
{
    return { v2.x* v1.x, v2.y * v1.y };
}

Vec operator/(const Vec& v1, const Vec& v2)
{
    return { v1.x/ v2.x, v1.y/ v2.y };
}

bool operator==(const Vec& v1, const Vec& v2)
{
    return v1.x == v2.x && v1.y == v2.y;
}

bool eq(const Vec& v1, const Vec& v2)
{
    return v1.x - v2.x <= 0 && v1.y - v2.y <= 0;
}

bool isColeniar(const Vec& v1, const Vec& v2)
{
    return v1.x / v2.x == v1.y / v2.y;
}

int angular (double cos)
{
    float rad = acos(cos);

    double t1 = 180.0;

    t1 *= rad;

    double t2 = (3.14159265);

    int deg = int(rad / t2);
    std::cout << deg;
    return deg;

}

bool isEqualOrientation(const Vec& v1, const Vec& v2)
{
    return angular((v1.x * v2.x + v1.y * v2.y)/
    (sqrt(v1.x * v1.x + v1.y* v1.y)*
     sqrt(v2.x * v2.x + v2.y * v2.y))) == 0;
}

bool isUnEqualOrientation(const Vec& v1, const Vec& v2)
{
    return angular((v1.x * v2.x + v1.y * v2.y) /
     (sqrt(v1.x * v1.x + v1.y * v1.y) *
      sqrt(v2.x * v2.x + v2.y * v2.y))) == 180;
}

bool isOrthogonal(const Vec& v1, const Vec& v2)
{
    return (v1.x * v2.x + v1.y * v2.y)/
    (sqrt(v1.x * v1.x + v1.y* v1.y)*
     sqrt(v2.x * v2.x + v2.y * v2.y)) == 0;
}

double length(const Vec& v)
{
    return sqrt(v.x * v.x + v.y* v.y);
}

Vec normir(const Vec& v)
{
    double kof = length(v);
    return Vec{v.x/kof, v.y/kof};
}

Vec rederection(const Vec& v)
{
    return Vec{-v.x,-v.y};
}

int angle(const Vec& v1,const Vec& v2)
{
    return angular((v1.x * v2.x + v1.y * v2.y)/
    (sqrt(v1.x * v1.x + v1.y* v1.y)*
     sqrt(v2.x * v2.x + v2.y * v2.y)));
}

int cos(const Vec& v1,const Vec& v2)
{
    return (v1.x * v2.x + v1.y * v2.y)/
    (sqrt(v1.x * v1.x + v1.y* v1.y)*
     sqrt(v2.x * v2.x + v2.y * v2.y));
}





