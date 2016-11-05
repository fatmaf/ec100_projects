#include<iostream>
#include <math.h>
using namespace std;

/* test function that returns two values */
void rets2(int*, int*); /*prototype*/
int main()
{
	int z = 0; 
	int u = 1; 
	int *x=&z; 
	int *y=&u;

	rets2(x, y); /*get values from function*/
	cout << "First is = " << x << "Second is = " << y;
	cout << "First is = " << *x << "Second is = " << *y;
	return 0;
}
/* returns two numbers */
void rets2(int* px, int* py)
{
	*px = 3; /* set contents of px to 3 */
	*py = 5; /* set contents of px to 5 */
	py = px; 
}
