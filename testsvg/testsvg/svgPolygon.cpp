#include "helper.h"
#include "svgPolygon.h"

SVGpoly::SVGpoly()
{
	

	fillcolor = colors.red;
	strokecolor = colors.yellow;
	strokewidth = 2;
}

void SVGpoly::setfillcolor(string col)
{
	fillcolor = col;
}

void SVGpoly::setstrokecolor(string col)
{
	strokecolor = col;
}

void SVGpoly::addpoint(float x, float y)
{
	points.push_back(make_pair(x, y));
}

string SVGpoly::createpoly()
{
	string polystring = "<polygon points=\""; 
	for (int i = 0; i < points.size(); i++)
	{
		polystring = addtostring(polystring, points[i].first, ",", points[i].second, " ");
	}
	polystring = addtostring(polystring + "\" stroke-width=\"", strokewidth);
	polystring += "\" stroke=\"" + strokecolor + "\" fill=\"" + fillcolor + "\"/>";

	return polystring;
}
string SVGpoly::createtriangle()
{
	points.clear();
	//<polygon points = "200,10 250,190 160,210"
	points.push_back(make_pair<float, float>(200, 10));
	points.push_back(make_pair<float, float>(250, 190));
	points.push_back(make_pair<float, float>(160, 210));

	return createpoly();
}
