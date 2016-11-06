#include "svgcircle.h"
#include "helper.h"

SVGcircle::SVGcircle()
{
	radius = 40;
	x = 10;
	y = 10;
	fillcolor = colors.blue;
	strokecolor = colors.black;
	strokewidth = 3;
}

void SVGcircle::setradius(float w)
{
	radius = w;
}
void SVGcircle::setxpos(float xp)
{
	x = xp;
}
void SVGcircle::setypos(float yp)
{
	y = yp;
}
void SVGcircle::setfillcolor(string col)
{
	fillcolor = col;
}
void SVGcircle::setstrokecolor(string col)
{
	strokecolor = col;
}
string SVGcircle::createCircle()
{
	string circlestring = addtostring("<circle cx=\"", x, "\" cy=\"", y, "\" r=\"");
	circlestring = addtostring(circlestring, radius,  "\" stroke-width=\"", strokewidth,"\" stroke=\"");
	circlestring = circlestring  + strokecolor + "\" fill=\"" + fillcolor + "\"/>";
	return circlestring;
}