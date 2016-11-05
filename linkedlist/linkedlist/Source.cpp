#include <iostream>
#include <string>

using namespace std; 
const int numstudents = 3;

struct student
{
	string name; 
	int id; 
	int age; 
};
student findstudentbyid(student arr[],int id)
{
	student toret; 
	toret.id = -1; 
	for (int i = 0; i < 10; i++)
	{
		if (arr[i].id == id)
		{
			toret = arr[i];
			break;
		}
	}
	return toret;
}
int main()
{
	//variables 
	student s_array[numstudents];

//	string names[numstudents]; 
//	int ages[numstudents];
//	int ids[numstudents];

	for (int i = 0; i < numstudents; i++)
	{
		cin >> s_array[i].name; 
		cin >> s_array[i].age;
		cin >> s_array[i].id;
	}
	for (int i = 0; i < numstudents; i++)
	{
		cout << s_array[i].name;
		cout << s_array[i].age;
		cout << s_array[i].id;
	}
	student sfind = findstudentbyid(s_array, 56); 
	sfind.id; sfind.name; sfind.age;
	return 0; 
}