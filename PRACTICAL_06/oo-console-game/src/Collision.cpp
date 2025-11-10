//Student name Kittithep
//Collision.cpp

#include "Collision.h"
#include <cmath>


//Circle constructor
Circle::Circle(float xPos, float yPos, float r) : x(xPos), y(yPos), radius(r) {}

//Checks if the distance between the centers of two circles is less than the sum of their radii
bool Circle::circle_to_circle(Circle* a,Circle* b)
{
	//check for distance
	float dx = a->getXpos() - b->getXpos();
	float dy = a->getYpos() - b->getYpos();

	//d no square root
	float d = (dx * dx) + (dy * dy);

	//radii
	float sumR = a->getRadius() + b->getRadius();

		 //sqrt d <= sumR^2
	return d <= sumR * sumR; //if true == touching or overlapping
}

float Circle::getXpos()
{
	return x;
}


float Circle::getRadius()
{
	return radius;
}