#include <iostream>
using namespace std;

int Global = 10;
void create_static_variable()
{
	static int Static = 0;
	Static += 2;
}
void create_local2_variable()
{
	int Local2 = 0;
	Local2++;
}




int main()
{
	int Local0 = 10;
	{
		int Local1 = 0;
		Local1++;
		Local1++;
		Local0++;
		create_static_variable();
		create_local2_variable();
	}
	create_static_variable();
	create_static_variable();
	create_local2_variable();
	create_local2_variable();
	return 0;
}


