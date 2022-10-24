
#pragma once

#include <iostream>
#include <cmath>

struct Vec
{
    double x, y;
    friend Vec operator+(const Vec& v1,const Vec& v2);
    friend Vec operator-(const Vec& v1,const Vec& v2);
    friend Vec operator*(const Vec& v1,const Vec& v2);
    friend Vec operator/(const Vec& v1,const Vec& v2);
};

Vec operator+(const Vec& v1,const Vec& v2);

Vec operator-(const Vec& v1, const Vec& v2);

Vec operator*(const Vec& v1, const Vec& v2);

Vec operator/(const Vec& v1, const Vec& v2);

bool operator==(const Vec& v1, const Vec& v2);

bool eq(const Vec& v1, const Vec& v2);

bool isColeniar(const Vec& v1, const Vec& v2);

int angular (double cos);

bool isEqualOrientation(const Vec& v1, const Vec& v2);

bool isUnEqualOrientation(const Vec& v1, const Vec& v2);

bool isOrthogonal(const Vec& v1, const Vec& v2);

double length(const Vec& v);

Vec normir(const Vec& v);

Vec rederection(const Vec& v);

int angle(const Vec& v1,const Vec& v2);

int cos(const Vec& v1,const Vec& v2);





