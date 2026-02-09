#include <iostream>

class Vector
{
public:
    float Length() const;

    float x, y;
};

class Point
{
public:
    Point AddVector(Vector v);

    float x, y;
};

float Vector::Length() const
{
    float length;

    length = std::sqrt(x * x + y * y);

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
    std::cout << "Hello World!\n";

    //Point p; // (1,0)
    //p.x = 1;
    //p.y = 0;

    //Vector v; //(2,3)
    //v.x = 2;
    //v.y = 3;

    //Point p2 = p.AddVector(v);

    //std::cout << "Result: (" << p2.x << ", " << p2.y << ")\n";

    Point p; // vector (0, 1)
    p.x = 0;
    p.y = -1;

    Point i; // vector (1,1)
    i.x = 1;
    i.y = 1;

    Vector v;

    v = p - i;

    float length = v.Length();

    std::cout << "Result: (" << v.x << ", " << v.y << ")\n";

    std::cout << "Length: " << length << "\n";

    
    return 0;
}
