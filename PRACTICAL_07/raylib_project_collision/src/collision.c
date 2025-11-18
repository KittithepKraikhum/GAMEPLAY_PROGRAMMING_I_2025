//collision.c

#include "collision.h"

int circleToCircle(Circle* a, Circle* b)
{
    return c2CircletoCircle(a->c, b->c);
}

int circleToAABB(Circle* circle, Rect* box)
{
	return c2CircletoAABB(circle->c,box->a);
}

int capsuleToCircle(Capsule* capsule, Circle* circle)
{
	return c2CircletoCapsule(circle->c, capsule->cap);

}

int capsuleToAABB(Capsule* capsule, Rect* box)
{
	return c2AABBtoCapsule(box->a, capsule->cap);
}

int rectangleToRectangle(Rect* a, Rect* b)
{
	return  c2AABBtoAABB(a->a,b->a);
}


int rectangleToCapsule(Rect* box, Capsule* capsule)
{
	return c2AABBtoCapsule(box->a, capsule->cap);
}

int rectangleToCircle(Rect* box, Circle* circle)
{
	return c2CircletoAABB(circle->c,box->a);
}


int rayToCircle(Ray2* ray, Circle* circle)
{
	c2Raycast cast;
	return c2RaytoCircle(ray->ray, circle->c, &cast);
}

int rayToAABB(Ray2* ray, Rect* box)
{
	c2Raycast cast;
	return c2RaytoAABB(ray->ray,box->a, &cast);
}

int rayToCapsule(Ray2* ray, Capsule* capsule)
{
	c2Raycast cast;
	return c2RaytoCapsule(ray->ray, capsule->cap, & cast);
}
