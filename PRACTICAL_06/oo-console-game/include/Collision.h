//Student name Kittithep
//Collision.h

#pragma once

class Circle {
private:
	float m_x; //Position
	float m_y; 
	
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
	float m_x; //Position
	float m_y;
	
	float m_width; //Dimensions
	float m_height;

public:
	Rectangle(float xPos, float yPos, float w, float h);

	//get method
	float getXpos();
	float getYpos();
	float getWidth();
	float getHeight();


	//Collision detection
	bool rectangle_to_rectangle(Rectangle* a, Rectangle* b);







};