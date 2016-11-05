#include <iostream>
using namespace std;

int main()
{
	int count = 0, total = 0;
	while (count<10)
	{
		cout << "count = " << count << "total=" << total << endl;
		count++;
		total = total + count;
		cout << "count = " << count << "total=" << total << endl;
	}
	cout << count;
	return 0;
}

