#pragma once					//include this only once 
#ifndef SVGRECTH				//if svgrecth does not exist	
#define SVGRECTH				//define it
#include <iostream>					
#include <string>
using namespace std; 

//The class svgrect creates a rectangle, that can be sent to the 
//svgfile class and hence draw a rectangle on the canvas
class SVGrect {					//class is the keyword, SVGrect is the name of the class, notice the {
public:							//access specifier, change this to private and see what happens
//data members
	float width;				//width in pixels			
	float height;				//height in pixels
	float x;					//x location, num of pixels away from left
	float y;					//y location, num of pixels away from top
	string fillcolor;			//fill color
	string strokecolor;			//stroke color
	float strokewidth;			//stroke width
//member functions
	SVGrect();					//class constructor, what happens when an object is created, what variables are initialized		
	void setwidth(float w);		//a function to change the width
	void setheight(float h);	//set the height
	void setxpos(float xp);		//set the x position (from the left)
	void setypos(float yp);		//set the y position (from the top)
	void setfillcolor(string col); //set the fill color
	void setstrokecolor(string col);//set the stroke color
	string createRect();		//create the string that we can add to the file to make the rectangle
	//add the function prototype for a function to change the stroke width of the rectangle
};
#endif