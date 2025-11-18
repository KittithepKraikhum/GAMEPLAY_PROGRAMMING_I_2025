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

    // Test rectangles
    Rectangle r1(0, 0, 50, 50);   // Rectangle at (0,0) with width=50, height=50
    Rectangle r2(25, 25, 50, 50); // Overlaps with r1
    Rectangle r3(100, 100, 20, 20); // Far away, no overlap

    // Test overlap between r1 and r2
    if (r1.Rectangle::rectangle_to_rectangle(&r1, &r2))
        std::cout << "r1 and r2 intersect" << std::endl;
    else
        std::cout << "r1 and r2 do NOT intersect" << std::endl;

    // Test overlap between r1 and r3
    if (r1.Rectangle::rectangle_to_rectangle(&r1, &r3))
        std::cout << "r1 and r3 intersect" << std::endl;
    else
        std::cout << "r1 and r3 do NOT intersect" << std::endl;
}