#pragma once
#ifndef SVGPOLYH 
#define SVGPOLYH
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SVGpoly {
public:
	vector<pair< float, float> > points;
	string fillcolor;
	string strokecolor;
	float strokewidth;

	SVGpoly();
	void addpoint(float x, float y);
	void setfillcolor(string col);
	void setstrokecolor(string col);
	string createpoly();
	string createtriangle();
};
#endif