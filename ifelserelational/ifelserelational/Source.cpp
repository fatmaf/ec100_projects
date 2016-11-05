#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

int main() {
	int x = 23;
	int y = 10;
	int z = 30;
	if ((x < y) && (x < z)) {
		cout << "x is less than z and y " << endl;
		cout << " Checked condition ((x < y) && (x < z))";
	}
	else
	{
		cout << "Nothing" << endl;
	}
	/*else if ((x> y) && (x < z)) {
		cout << "x is greater than y and less than z";
		x += y; 
	}
	else {
		cout << "x is greater than y and z or ";
		cout << " x is greater than z and less than y" << endl;
	}*/
	cout << "\nx is " << x << endl;
	cout << endl;
	return 0;
}

