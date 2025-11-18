#include "Collision.h"

//Student name Kittithep
//Collision.cpp
#include <cmath>


//Circle constructor
Circle::Circle(float xPos, float yPos, float r) : m_x(xPos), m_y(yPos), radius(r) {}

//Checks if the distance between the centers of two circles is less than the sum of their radii
bool Circle::circle_to_circle(Circle* a, Circle* b)
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
	return m_x;
}

float Circle::getYpos()
{
	return m_y;
}

float Circle::getRadius()
{
	return radius;
}

//start Rectangle definition
float Rectangle::getXpos()
{
	return m_x;
}

float Rectangle::getYpos()
{
	return m_y;
}

float Rectangle::getWidth()
{
	return m_width;
}

float Rectangle::getHeight()
{
	return m_height;
}

//Checks if the boundaries of one rectangle intersect with the boundaries of another
bool Rectangle::rectangle_to_rectangle(Rectangle* a, Rectangle* b)
{
	bool intersect;

	if (a->getXpos() + a->getWidth() <= b->getXpos() ||
		a->getXpos() >= b->getXpos() + b->getWidth() ||
		a->getYpos() + a->getHeight() <= b->getYpos() ||
		a->getYpos() >= b->getYpos() + b->getHeight())
	{
		intersect = false; //they are not intersect
	}
	else
	{
		intersect = true;
	}
	return intersect;
}