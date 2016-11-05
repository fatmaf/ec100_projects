#include <iostream>
using namespace std; 

int main()
{
	float x = 10; 
	float *px = &x; 
	float **ppx = &px; 
	x = 8.5;
	*px = 7.7;
	px = new float(3.1);
	cout << **ppx;


	int arr[2][3] = { {1,2,3},{4,5,6} };
	cout << arr << endl;
	cout << &arr << endl;
	cout << *arr << endl;
	cout << arr[0] << endl;
	cout << &arr[0] << endl;
	cout << **arr << endl;
	cout << arr[0][0] << endl;
	cout << *(arr + 1) << endl;
	cout << **(arr + 1) << endl;
	cout << arr[1][0] << endl;


	int ** parr = new int*[2]; 
	*parr = new int[3]; 
	*(parr + 1) = new int[3]; 
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			*(*(parr + i) + j) = i + j;
	}
	cout << parr << endl;
	cout << &parr << endl;
	cout << *parr << endl;
	cout << parr[0] << endl;
	cout << &parr[0] << endl;
	cout << **parr << endl;
	cout << parr[0][0] << endl;
	cout << *(parr + 1) << endl;
	cout << **(parr + 1) << endl;
	cout << parr[1][0] << endl;
	return 0;
}