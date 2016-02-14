#include <iostream>  //including libraries whose functions are to be used in your program. Eg: "cout", "cin".
using namespace std; //the using directive tells us that we're going to be using things from the library "namespace" with a prefix std
int main()
{
	int a, b, sum;
	cout << "Please enter an integer value: ";
	cin >> a;
	cout << "Please enter Second integer value: ";
	cin >> b;
	//summing function
	sum = a + b;
	//displaying output
	cout << "The sum is: " << sum << endl;

	return 0;
}
