#include <iostream>
using namespace std;

void Array(int[][3]);				//2D array passed
void Pointer(int *);				//pointer of pointer array passed
void PPointer(int *);				//pointer to a pointer in pointer array passed


int main()
{
	int arr[2][3] = { { 1,2,3 },{ 4,5,6 } };		//2D array
	int(*parr)[3] = arr;						//pointer array to a 2D array
	int(*(*pparr))[3] = &parr;					// pointer to a pointer array which is pointing to 2D array

	Array(arr);									//2D Array passed through a function
	cout << endl;
	Pointer((parr[0]));								//Pointer to a 2D array passed through a function
	cout << endl;
	PPointer(*(*pparr + 1));
	cout << endl;




	return 0;
}
void Array(int a[][3])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << a[i][j] << endl;
		}
	}
}
void Pointer(int *b)
/*ok so a pointer pointing to a 2D array is actually a pointer array*/
{
	for (int i = 0; i < 3; i++)
	{
		cout << b[i] << endl;
	}

}
void PPointer(int *c)
{
	for (int i = 0; i < 3; i++)
	{
		cout << ((c[i])) << endl;
	}

}

//How to pass pointer array through functions and how to pass pointer to a pointer array through function?