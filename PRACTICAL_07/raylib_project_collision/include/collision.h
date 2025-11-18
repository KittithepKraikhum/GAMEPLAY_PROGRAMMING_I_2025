//collision.h

#ifndef COLLISION_H
#define COLLISION_H

#include "cute_c2.h"

//Circle to circle
int circleToCircle(c2Circle a, c2Circle b);

//Circle to Rectangle
int circleToAABB(c2Circle circle, c2AABB box);


//Circle to Capsule
int circleToCapsule(c2Circle circle, c2Capsule capsule);

#endif

