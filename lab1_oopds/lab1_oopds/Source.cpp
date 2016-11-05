#include <iostream>
#include <string>
using namespace std;
class Box
{
private:
	double length; // Length of a box
	double breadth; // Breadth of a box
	double height; // Height of a box
	string name;
	double rectArea(double l, double b)
	{ return l*b;}
public:
	Box() :length(0), breadth(0), height(0) { name = "box"; cout << "\nCreated Box " << name << endl; }
	Box(double l, double b, double h,string _name = "box")
	{
		length = l; breadth = b; height = h; name = _name;
		cout << "\nCreated Box " << name << endl;
	}
	Box(double x,string _name = "box") :length(x), breadth(x), height(x), name(_name) { cout << "\nCreated Box " << name << endl; }
	void setBox(double l, double b, double h)
	{length = l; breadth = b; height = h; }
	double volume()
	{ return length*breadth*height;}
	double surfaceArea()
	{return (2*rectArea(length,breadth)+2*rectArea(breadth,height)+2*rectArea(height,length));}
	void printBox()
	{
		cout << "\nPrinting data for box named " << name << endl;
		cout << "\nLenght: " << length << "\tBreadth: " << breadth << "\tHeight: " << height << endl;}
	double getLength()
	{return length;}
	double getBreadth()
	{return breadth;}
	double getHeight()
	{return height;}
	~Box()
	{cout << "\nDestroying Box "<< name << endl;}
};

//create a function that dynamically allocates a new box and returns it
Box* createNewBox(double l = 1,double h = 2, double b = 3)
{
	Box *newBox = new Box(l, b, h,"dynBox");
	return newBox;
}
Box addBoxes(Box box1, Box box2, int n = 2)
{
	double newl = box1.getLength() + box2.getLength();
	double newh = box1.getHeight() + box2.getHeight();
	double newb = box1.getBreadth() + box2.getBreadth();
	Box toret(newl, newb, newh,"addedBox");
	for (int i = 0; i < n; i++)
	{
		toret.printBox();
	}
	return toret;}
void oldtasks()
{
	Box *aBox = createNewBox(); 
	Box newBox = addBoxes(*aBox, Box(4,"anotherBox"));
	newBox.printBox();
}
void task1()
{
	//write code for task 1 here
}
void task2()
{
	//write code for task 2 here
}
int main()
{
	Box Box1;        // Declare Box1 of type Box
	Box Box2(3.5,2,1.0,"Box2");        // Declare Box2 of type Box
	double volume = 0.0;     // Store the volume of a box here
	
	Box1.printBox();
	Box2.printBox();
	Box1.setBox(6, 7, 5);

	Box1.printBox();
	Box2.printBox();
	
	volume = Box1.volume();
	cout << "Volume of Box1 : " << volume << endl;

	oldtasks();
	//call new tasks here 
	task1();
	task2();
	return 0;
}

