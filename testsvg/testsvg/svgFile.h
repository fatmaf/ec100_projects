#pragma once
//svgFile.h contatins the member function prototypes and data members of the class svgFile 
//DO NOT EDIT THIS FILE

#ifndef SVGFILEH					//if you can't find something called svgfileh
#define SVGFILEH					//define it

#include <iostream>					//for input output
#include <string>					//for strings
#include <sstream>					//for file writing and processing strings
#include <fstream>					//for file writing
using namespace std;

//SVGfile is a class that can be used to write svg files
class SVGfile {
	float width;					//width of file 
	float height;					//height of file
	string body;					//body of the file
	string header;					//predefined header
	string footer;					//predefined footer
	string title;					//title of the file 
	string makesvgheader();			//a helper function to add svg specific things 
	void initvars();				//initialize any extra variables
public:
	SVGfile();						//the constructor for the class, what to do when you want to create an object
	SVGfile(float width, float height);		//an overloaded constructor, use this one to set the width and height yourself
	SVGfile(string title, float width, float height);	//an overloaded constructor, use this one to set the width, height and title
	SVGfile(string title);			//an overloaded constructor to set the title
	void addtofile(string shape);	//add a shape to the file
	void writefile(string filename = "draw.html");	//write the file with filename to disk
	void openfile(string filename = "draw.html");	//open the file with filename 
	void testempty();				//creates a test file, which draws a circle
};

#endif SVGFILEH