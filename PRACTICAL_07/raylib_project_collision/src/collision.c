//collision.c

#include "collision.h"

int circleToCircle(c2Circle a, c2Circle b)
{
    return c2CircletoCircle(a, b);
}

int circleToAABB(c2Circle circle, c2AABB box)
{
	return c2CircletoAABB(circle,box);
}

int circleToCapsule(c2Circle circle, c2Capsule capsule)
{
	return c2CircletoCapsule(circle, capsule);

}
