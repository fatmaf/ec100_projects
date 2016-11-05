#include <iostream>
using namespace std;

int main() {
	char totest[] = "zrun%ohduqrerwv.frp";
	char torep[] = "zrun%ohduqrerwv.frp";
	int len = sizeof(totest) / sizeof(char)-1;
	for (int i = 0; i< len; i++)
	{
		if (totest[i] == 'f')
			torep[i] = 'c';
		else if (totest[i] == 'r')
			torep[i] = 'o';
		else if (totest[i] == 'p')
			torep[i] = 'm';
		else
			torep[i] = totest[i];

	}
	cout << totest << endl;
	cout << torep << endl;
	for (int i = 0; i<len; i++)
		cout << (int)totest[i] << " ";
	cout << endl;
	for (int i = 0; i<len; i++)
		cout << (int)torep[i] << " ";
	cout << endl;
	for (int i = 0; i<len; i++)
		cout << (int)torep[i] - (int)totest[i] << " ";
	cout << endl;
	for (int i = 0; i<len; i++)
	{
		torep[i] = totest[i] - 3;
	}
	cout << endl;

	for (int i = 0; i<len; i++)
		cout << torep[i] << " ";
	cout << endl;
	cout << torep << endl;
	return 0;
}