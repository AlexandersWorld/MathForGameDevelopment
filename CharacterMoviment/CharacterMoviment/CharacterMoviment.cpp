#include <iostream>

class Vector
{
public:
    Vector() {}
    Vector(float X, float Y)
    {
        x = X;
        y = Y;
    }
    float Length() const;
    float LengthSqr() const;

    Vector operator*(float s) const;
    Vector operator/(float s) const;

    Vector Normalized() const;

public:
    float x, y;
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

    float x, y;
};

Vector Vector::Normalized() const
{
    Vector normalized;

    normalized = (*this) / Length();

    return normalized;
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


Vector operator-(Point a, Point b)
{
    Vector v;

    v.x = a.x - b.x;
    v.y = a.y - b.y;

    return v;
}

Point Point::AddVector(Vector v)
{
    Point vPPrime;
    vPPrime.x = x + v.x;
    vPPrime.y = y + v.y;

    return vPPrime;
}

int main()
{
    //std::cout << "Hello World!\n";

    //Point p; // (1,0)
    //p.x = 1;
    //p.y = 0;

    //Vector v; //(2,3)
    //v.x = 2;
    //v.y = 3;

    //Point p2 = p.AddVector(v);

    //std::cout << "Result: (" << p2.x << ", " << p2.y << ")\n";

    //Point p; // vector (0, 1)
    //p.x = 0;
    //p.y = -1;

    //Point i; // vector (1,1)
    //i.x = 1;
    //i.y = 1;

    //Point c;
    //c.x = 2;
    //c.y = -1;

    //Vector cp;
    //Vector ip;

    //cp = p - c;
    //ip = p - i;

    //float length_sqr_cp = cp.LengthSqr();
    //float length_sqr_ip = ip.LengthSqr();

    //std::cout << "Length squared of CP: " << length_sqr_cp << "\n";
    //std::cout << "Length squared of IP: " << length_sqr_ip << "\n";

    //Vector v(3, 4);

    //std::cout << "Pac man's initial speed: " << v.Length() << "\n";

    //Vector doubled;

    //doubled = v * 2; //(6, 8)

    //std::cout << "Pac man's doubled speed: " << doubled.Length() << "\n";

    //Vector halved;

    //halved = v / 2;

    //std::cout << "Pac man's halved speed: " << halved.Length() << "\n";

    Point i(3, 4);
    Point p(1,2);

    Vector pi = i - p;

    Vector normalized = pi.Normalized();

    std::cout << "Pac man's view vector: (" << normalized.x << ", " << normalized.y << ")" << "\n";
    std::cout << "Pac man's view vector length: " << normalized.Length() << "\n";
    
    return 0;
}
