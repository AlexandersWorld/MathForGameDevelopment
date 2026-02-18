#pragma once

class Vector
{
public:
    Vector() {}
    Vector(float X, float Y, float Z)
    {
        x = X;
        y = Y;
        z = Z;
    }
    float Length() const;
    float LengthSqr() const;

    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;

    Vector operator*(float s) const;
    Vector operator/(float s) const;

    Vector Normalized() const;
    float DotProduct(const Vector& a, const Vector& b);

public:
    float x, y, z;
};

class Point
{
public:
    Point AddVector(Vector v);
    Point() {}
    Point(float X, float Y)
    {
        x = X;
        y = Y;
    }

    float x, y
};

Vector Vector::Normalized() const
{
    Vector normalized;

    normalized = (*this) / Length();

    return normalized;
}

float Vector::DotProduct(const Vector& a, const Vector& b)
{
    return a.x * b.x + a.y * b.y;
}

float Vector::Length() const
{
    float length;

    length = std::sqrt(x * x + y * y);

    return length;
}

Vector Vector::operator*(float s) const
{
    Vector scaled;
    scaled.x = x * s;
    scaled.y = y * s;

    return scaled;
}

Vector Vector::operator/(float s) const
{
    Vector scaled;
    scaled.x = x / s;
    scaled.y = y / s;

    return scaled;
}

float Vector::LengthSqr() const
{
    float length;

    length = (x * x + y * y);

    return length;
}
//calculate the lenth of a vector (3,4) length = (3*3 + 4*4) = 9 + 16 = 25


Point operator+(Point a, const Vector& b)
{
    Point r;

    r.x = a.x + b.x;
    r.y = a.y + b.y;

    return r;
}

Vector Vector::operator+(const Vector& v) const
{
    Vector r;

    r.x = x + v.x;
    r.y = y + v.y;

    return r;
}

Vector Vector::operator-(const Vector& v) const
{
    return Vector(x - v.x, y - v.y);
}


Vector operator-(Point a, Point b)
{
    Vector v;

    v.x = a.x - b.x;
    v.y = a.y - b.y;

    return v;
}