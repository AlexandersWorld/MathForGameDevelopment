#include <iostream>
#include "Vector2.h"


Point Point::AddVector(Vector v)
{
    Point vPPrime;
    vPPrime.x = x + v.x;
    vPPrime.y = y + v.y;

    return vPPrime;
}

class mario
{
public:
    Point position;
    Vector velocity;
    Vector gravity;

};

void Update(float dt)
{
    mario mario;

    mario.position = mario.position + mario.velocity * dt;
    mario.velocity = mario.velocity + mario.gravity * dt;
}

float GetCurrentTime()
{
    return 0.f;
}

void Draw()
{

}

int main()
{

    mario mario;

    mario.position = Point(0, 0);
    mario.velocity = Vector(2, 2);
    mario.gravity = Vector(0, -2);

    float flPreviousTime = 0;
    float flCurrentTime = GetCurrentTime();

    while (true)
    {
        flPreviousTime = flCurrentTime;
        flCurrentTime = GetCurrentTime();

        float dt = flCurrentTime - flPreviousTime;

        if (dt > 0.15f)
            dt = 0.15f;
        
        Update(dt);

        Draw();
    }
    
    return 0;
}
