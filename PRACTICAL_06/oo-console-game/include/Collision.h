//Student name Kittithep
//Collision.h

#pragma once

class Circle {
private:
	float x; //Position
	float y; 
	
	float radius; //Radius
public:
	//Constructor
	Circle(float xPos, float yPos, float r);


	//get method
	float getXpos();
	float getYpos();
	float getRadius();

	//Collision detection
	bool circle_to_circle(Circle *a, Circle* b);
};


class Rectangle {
private:
	float x; //Position
	float y;
	
	float width; //Dimensions
	float height;

public:
	Rectangle(float xPos, float yPos, float w, float h);

	//get method
	float getXpos();
	float getYpos();

	//Collision detection
	bool rectangle_to_rectangle(Rectangle* a, Rectangle* b); 







};