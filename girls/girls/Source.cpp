#include <iostream>
using namespace std;

int t1(int * a, int &b, int **c)
{
	int *x = new int(5);
	cout << *a << " " << b << " " << **c <<" "<<*x<< endl;
	*a = 10;

	cout << *a << " " << b << " " << **c << " " << *x << endl;
	a = x;
	c = &a; 
	b = b + 1; 

	cout << *a << " " << b << " " << **c << " " << *x << endl;
	return **c;
}
void onee2()
{
	int *d = new int(0);
	int **b = &d;
	int a = 1;
	cout << *d << " " << **b << " " << a << endl;
	*d = t1(d, a, b);

	cout << *d << " " << **b << " " << a << endl;
	delete d;
	d = NULL;

}

void disparr(int a[], int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void disparr(float a[], int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void OddEvenSort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i & 1) // 'i' is odd
		{
			for (int j = 2; j < n; j += 2)
			{
				if (a[j] < a[j - 1])
					swap(a[j - 1], a[j]);
			}
			
		}
		else
		{
			for (int j = 1; j < n; j += 2)
			{
				if (a[j] < a[j - 1])
					swap(a[j - 1], a[j]);
			}
		}
		disparr(a, n);
	}
}
void arrfunc(float **arr, int s1, int* s2)
{
	for (int i = 0; i < s1; i++)
	{
		for (int j = 0; j < s2[i]; j++)
		{
			*(*(arr + i) + j) += 2;
		}
	}
}
void q2()
{
	int s1 = 3;
	float **anarr = new float*[s1];
	int *anarrsize = new int[s1];
	for (int i = 0; i < s1; i++)
		anarrsize[i] = (i + 1) * 2;

	for (int i = 0; i < s1; i++)
	{
		anarr[i] = new float[anarrsize[i]];
		for (int j = 0; j < anarrsize[i]; j++)
			anarr[i][j] = i + j;
	}
	for (int i = 0; i < s1; i++)
		disparr(anarr[i],anarrsize[i]);
	arrfunc(anarr, s1, anarrsize);
	for (int i = 0; i < s1; i++)
		disparr(anarr[i], anarrsize[i]);

}
void evenodd()
{
	int ar[] = { 3,2,5,99,1,23 };
	int n = sizeof(ar) / sizeof(int);
	disparr(ar, n);
	OddEvenSort(ar, n);
	disparr(ar, n);

}
int a, b, c;
void confuse1(int  b, int a) { a += 1;   b += 1;   c += 1; }
void confuse2(int  b, int &a) { a += 2;   b += 2;   c += 2; }
void confuse3(int &b, int c) { a += 3;   b += 3;   c += 3; }
int test() {
	int a, c;   a = b = c = 1;
	cout << a << b << c << endl;
	confuse1(a, b);
	cout << a << b << c << endl;
	confuse2(b, c);
	cout << a << b << c << endl;
	confuse3(a, c);
	cout << a << b << c << endl;   return 0;
}
int main() {
	//onee2();
	test();
	return 0;
}