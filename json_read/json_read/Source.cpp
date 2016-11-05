#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	fstream file("locations.json", ios::in | ios::out | ios::binary);

	//file.seekg(2);

	char x=' ';
	bool readnext = false; 
	while (!file.eof()) {
		file.read(&x, 1);
		cout << x << endl;
	}
	return 0;
}
//int main()
//{
//	string line;
//	ifstream jfile("locations.json");
//	if (jfile.is_open())
//	{
//		while (getline(jfile, line))
//		{
//			cout << line << endl;
//		}
//		jfile.close();
//	}
//
//	return 0;
//}