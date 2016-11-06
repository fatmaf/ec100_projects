#include "svgFile.h"							//include the user defined header file svgfile.h
#include "svgRect.h"							//include the user defined header file svgrect.h
#include "helper.h"								//include the helper file. it has all the colors you need.

using namespace std;

void task1()
{
	int canvaswidth = 1000;						//set the width of our canvas
	int canvasheight = 1000;					//set the height of our canvas

	SVGfile afile(canvaswidth, canvasheight);	//create the canvas 

	SVGrect arect;								//create a rectangle object 
	arect.width = 100;							//set the width of the rectangle
	arect.height = 100;							//set the height of the rectangle
	arect.x = 50;								//set the x position of the rectangle, how many pixels away from the left 
	arect.y = 50;								//set the y position of the rectangle, how many pixels away from the top
	arect.strokecolor = colors.green;			//change the color of the boundary of the rectangle
												//add code here to change the color of the fill of the rectangle 

	afile.addtofile(arect.createRect());		//add the rectangle to the file. first call the create rectangle function
												//then send the result to the file.


	afile.writefile();							//write the file to disk
	afile.openfile();							//test your drawing by opening the file

}


void task2()
{
	int canvaswidth = 1000;						//set the width of our canvas
	int canvasheight = 1000;					//set the height of our canvas

	SVGfile afile(canvaswidth, canvasheight);	//change this to change the title as well. look at svgFile.h

	SVGrect arect;								//create a rectangle object 
	arect.width = 100;							//set the width of the rectangle
	arect.height = 100;							//set the height of the rectangle
	arect.x = 50;								//set the x position of the rectangle, how many pixels away from the left 
	arect.y = 50;								//set the y position of the rectangle, how many pixels away from the top
	arect.strokecolor = colors.green;			//change the color of the boundary of the rectangle

	//add code here to declare another rectangle object , arect2
	

	afile.addtofile(arect.createRect());		//add the rectangle to the file. first call the create rectangle function
												//then send the result to the file.

	//add code here to add your rectangle object to the file
	afile.writefile();							//write the file to disk
	afile.openfile();							//test your drawing by opening the file

}

void task3()
{
	//repeat task 2 here
	//instead of modifying the attributes directly, use the set functions to do so
}

void task4()
{
	//create a rectangle here and modify its stroke width 
	//you must add a function to change the stroke width to the rectangle class and call that function
	//bonus: try to change the title and name of your file 
}

void task5()
{
	//test your square class here 
}

//task6
float calculateRectangleArea(SVGrect arect)
{
	float area = 0; 
	//write code here to calculate the area of a rectangle object 
	return area;
}

void task6()
{
	SVGrect arect;								//create a rectangle object 
	arect.width = 100;							//set the width of the rectangle
	arect.height = 100;							//set the height of the rectangle
	arect.x = 50;								//set the x position of the rectangle, how many pixels away from the left 
	arect.y = 50;								//set the y position of the rectangle, how many pixels away from the top
	arect.strokecolor = colors.green;			//change the color of the boundary of the rectangle

	//call the area function here 
	//print its output to the console
}

//write a function to calculate the perimeter of a square object 
void task7()
{
	//test your function here
}

SVGrect redRectangle()
{
	SVGrect arect; 
	//create a red rectangle
	return arect;
}

void task8()
{
	int canvaswidth = 1000;						//set the width of our canvas
	int canvasheight = 1000;					//set the height of our canvas

	SVGfile afile(canvaswidth, canvasheight);	//change this to change the title as well. look at svgFile.h

	SVGrect arect = redRectangle();				//should create a red rectange
	afile.addtofile(arect.createRect());		//add the rectangle to the file. first call the create rectangle function
												//then send the result to the file.
												//add code here to add your rectangle object to the file
	afile.writefile();							//write the file to disk
	afile.openfile();							//test your drawing by opening the file

}

//write a function to create a yellow square and return it 

void task9()
{
	int canvaswidth = 1000;						//set the width of our canvas
	int canvasheight = 1000;					//set the height of our canvas

	SVGfile afile(canvaswidth, canvasheight);	//change this to change the title as well. look at svgFile.h

	SVGrect arect = redRectangle();				//should create a red rectange
	afile.addtofile(arect.createRect());		//add the rectangle to the file. first call the create rectangle function
												//then send the result to the file.
	//add code here to create a yellow square using your function. 
	//send that square to your file here 
	afile.writefile();							//write the file to disk
	afile.openfile();							//test your drawing by opening the file

}

int main()
{
	
	return 0;
}