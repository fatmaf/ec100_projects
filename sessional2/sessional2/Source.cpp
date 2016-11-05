#include <iostream>
using namespace std; 

float powerit(int base, int exp)
{
	float ans = 1;
	if (exp < 0)
	{
		for (int i = exp; i<0; i++)
		{
			ans *= 1.0 / (float)base;
		}
	}
	else
	{
		if (exp > 0)
		{
			for (int i = exp; i>0; i--)
			{
				ans *= base;
			}
		}
	}
	return ans;
}
float power(int base, int exp)
{
	if (exp == 0)
	{
		return 1;
	}
	else if (exp < 0)
	{
		return (1.0 / (float)base * power(base, exp + 1));
	}
	else
	{
		return base * power(base, exp - 1);
	}
}

void testq1()
{
	int base = 3; 
	int exp = 2; 
	cout << power(base, exp) << endl; 
	cout << powerit(base, exp) << endl;
	cout << power(base, 0) << endl;
	cout << powerit(base, 0) << endl;
	cout << power(base, -exp) << endl;
	cout << powerit(base, -exp) << endl;
}
bool madeDracula = false;
char dracName = 'V'; //vlad
float becomeVampire(char sire, float strength, char& vamp_name)
{
	if (sire == 'z' || sire == 'Z')
		sire -= 2;
	vamp_name = sire + 1;
	return (strength - (int)(vamp_name / sire));
}
float getDracStrength(bool init = false)
{
	static float dracStrength = 100;
	if (!init && madeDracula)
	{
		dracStrength++;
	}
	else
		dracStrength = 100;
	return dracStrength;
}
void makeDracula()
{
	bool madeDracula = false;
	if (!::madeDracula)
	{
		cout << "Dracula created with strength " << getDracStrength() << endl;
		::madeDracula = !::madeDracula;
		madeDracula = ::madeDracula;
	}
}
void testq2()
{
	makeDracula();
	int n = 6;
	int count = 0;
	for (int i = 1; i < n; i += 2)
	{
		char dracName = ::dracName;
		float dracStr = getDracStrength();
		for (int j = 0; j < i; j++)

		{
			char vampName = ' ';
			count++;
			cout << "\n" << count << " Siring a vampire from " << dracName << " with strength " << dracStr << endl;
			cout << "New vampire strength " << becomeVampire(dracName, dracStr, vampName);
			cout << " and name " << vampName << endl;
			dracName = vampName;
		}
		::dracName++;
	}
}
int main()
{
	testq1();
	testq2();
	return 0;
}