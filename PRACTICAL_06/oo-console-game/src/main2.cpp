#include "Collision.h"
#include <iostream>


int main()
{
    Circle c1(0.0f, 0.0f, 5.0f);   // Circle at origin, radius 5
    Circle c2(20.0f, 0.0f, 3.0f);   // Circle at (7,0), radius 3

    if (c1.circle_to_circle(&c1, &c2)) {
        std::cout << "Collision!";
    }
    else {
        std::cout << "No collision";
    }
}