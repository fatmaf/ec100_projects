#include <iostream>
#include <string>

using namespace std; 


//declaring a structure for students 

struct student
{
	int id; 
	int age; 
	string name; 
};

//delcaring a const integer that decides the number of students 
const int numstudents = 10; 

//takes as input 3 arrays and returns the index of the array containing the id
int finduserbyidwithoutstructure(int ids[],int idtosearch)
{
	int indextoret = -1; 

	for (int i = 0; i < numstudents; i++)
	{
		if (ids[i] == idtosearch)
		{
			indextoret = i; 
			break;
		}
	}

	return indextoret;
}
void withoutstructures()
{
	//declaring variables to store 
	int ids[numstudents]; 
	int ages[numstudents];
	string names[numstudents]; 
	
	//storing variables 
	for (int i = 0; i < numstudents; i++)
	{
		cin >> names[i];
		cin >> ids[i]; 
		cin >> ages[i];
	}

	//displaying variables
	for (int i = 0; i < numstudents; i++)
	{
		cout << names[i];
		cout << ids[i];
		cout << ages[i];
	}
	//searching for a user's data by id 

	int id; 
	cin >> id; 
	int index = finduserbyidwithoutstructure(ids, id);
	cout << index; 
	cout << names[index]; 
	cout << ids[index]; 
	cout << ages[index];
}

student findstudentbyid(student arr[], int idtosearch)
{
	student toret; 
	toret.id = -1; 
	for (int i = 0; i < numstudents; i++)
	{
		if (arr[i].id == idtosearch)
		{
			toret = arr[i]; 
			break;
		}
	}
	return toret; 
}
void withstructures()
{
	//declaring variables to store 
	student st_arr[numstudents];

	//storing variables 
	for (int i = 0; i < numstudents; i++)
	{
		cin >> st_arr[i].name;
		cin >> st_arr[i].id;
		cin >> st_arr[i].age;
	}

	//displaying variables
	for (int i = 0; i < numstudents; i++)
	{
		cout << st_arr[i].name;
		cout << st_arr[i].id;
		cout << st_arr[i].age;
	}
	//searching for a user's data by id 

	int id;
	cin >> id;
	student sfound = findstudentbyid(st_arr, id);
	cout << id;
	cout << sfound.name;
	cout << sfound.age;
	cout << sfound.id;
}

void recursivesort(int arr[], int str, int end)
{
	if (str != end) {
		int is = str;
		int s = arr[str];
		for (int i = str + 1; i <= end; i++)
		{
			if (arr[i] < s)
			{
				s = arr[i]; 
				is = i;
			}
		}
		arr[is] = arr[str]; 
		arr[str] = s;
		recursivesort(arr, str+1, end);
	}
}

int main()
{
	
	int arr[] = { 5,3,2, 6, 7, 2 }; 
	recursivesort(arr, 0, 5);
	return 0; 
}