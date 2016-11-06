#include "svgRect.h"
#include "helper.h"

SVGrect::SVGrect()
{
	height = 30; 
	width = 30; 
	x = 10; 
	y = 10; 
	fillcolor = colors.blue;
	strokecolor = colors.black;
	strokewidth = 3;
}

void SVGrect::setwidth(float w)
{
	width = w;
}
void SVGrect::setheight(float h)
{
	height = h;
}
void SVGrect::setxpos(float xp)
{
	x = xp;
}
void SVGrect::setypos(float yp)
{
	y = yp;
}
void SVGrect::setfillcolor(string col)
{
	fillcolor = col;
}
void SVGrect::setstrokecolor(string col)
{
	strokecolor = col;
}
//add a function here to change the stroke width 


//do not change this function 
string SVGrect::createRect()
{
	
	string rectstring = addtostring("<rect x=\"", x, "\" y=\"", y, "\" width=\"");
	rectstring = addtostring(rectstring, width, "\" height=\"", height, "\" stroke-width=\"");
	rectstring = addtostring(rectstring, strokewidth);
	rectstring =rectstring+ "\" stroke=\"" + strokecolor + "\" fill=\"" + fillcolor + "\"/>";
	return rectstring;
}