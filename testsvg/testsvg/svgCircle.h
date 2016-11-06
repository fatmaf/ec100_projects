#pragma once
#ifndef SVGCIRCLEH
#define SVGCIRCLEH
#include <iostream>
#include <string>
using namespace std;

class SVGcircle {
public:
	float radius;
	float x;
	float y;
	string fillcolor;
	string strokecolor;
	float strokewidth;

	SVGcircle();
	void setradius(float w);
	void setxpos(float xp);
	void setypos(float yp);
	void setfillcolor(string col);
	void setstrokecolor(string col);
	string createCircle();
};
#endif