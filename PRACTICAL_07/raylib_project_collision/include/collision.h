//collision.h

#ifndef COLLISION_H
#define COLLISION_H

#include "cute_c2.h"



typedef struct{
	c2Circle c; //this is the actual cuteC2 circle

}Circle;

typedef struct {
	c2AABB a; //this is the actual cuteC2 AABB
}Rect;

typedef struct {
	c2Capsule cap;
}Capsule;

typedef struct {
	c2Ray ray; //actual cuteC2 ray
}Ray2;


//c2Circle to Circle
int circleToCircle(Circle* a, Circle* b);


//c2Capsule to Circle
int capsuleToCircle(Capsule* capsule, Circle* circle);


//c2Capsule to AABB
int capsuleToAABB(Capsule* capsule, Rect* box);


//C2AABB to AABB
int rectangleToRectangle(Rect* a, Rect* b);


//C2AABB to Capsule
int rectangleToCapsule(Rect* box,Capsule* capsule);


//C2AABB to Circle
int rectangleToCircle(Rect * box,Circle * circle);


//c2Ray to Circle
int rayToCircle(Ray2* ray, Circle * circle);


//c2Ray to AABB
int rayToAABB(Ray2 *ray,Rect* box);


//c2Ray to AABB
int rayToCapsule(Ray2* ray, Capsule* capsule);





int circleToAABB(Circle* circle, Rect* box);



#endif

