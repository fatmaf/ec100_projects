#include <iostream>
using namespace std; 
bool madeDracula = false;
char dracName = 'V'; //vlad
float becomeVampire(char sire, float strength, char& vamp_name)
{	if (sire == 'z' || sire == 'Z')
		sire-=2; 
	vamp_name = sire+1; 
	return (strength - (int)(vamp_name / sire)); }
float getDracStrength(bool init = false)
{	static float dracStrength = 100;
	if (!init && madeDracula)
	{
		dracStrength++;
	}
	else
		dracStrength = 100;
	return dracStrength;}
void makeDracula()
{	bool madeDracula = false; 
	if (!::madeDracula)
	{
		cout << "Dracula created with strength " << getDracStrength() << endl;
		::madeDracula = !::madeDracula;
		madeDracula = ::madeDracula;
	}}
int main()
{	makeDracula();
	int n = 6;
	int count = 0;
	for (int i = 1; i < n; i += 2)
	{	char dracName = ::dracName;
		float dracStr = getDracStrength();
		for (int j = 0; j < i; j++)
			
		{	char vampName = ' ';
		count++;
			cout << "\n"<<count<<" Siring a vampire from " << dracName << " with strength " << dracStr << endl;
			cout << "New vampire strength " << becomeVampire(dracName, dracStr, vampName);
			cout<<" and name " << vampName << endl;
			dracName = vampName;}
		::dracName++;}
	return 0; }