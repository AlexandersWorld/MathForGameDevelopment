#include <iostream>

class Vector
{
public:
    float x, y;
};

class Point
{
public:
    Point AddVector(Vector v);

    float x, y;
};

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

    Point p; // (1,0)
    p.x = 1;
    p.y = 0;

    Vector v; //(2,3)
    v.x = 2;
    v.y = 3;

    Point p2 = p.AddVector(v);

    std::cout << "Result: (" << p2.x << ", " << p2.y << ")\n";

    
    return 0;
}
