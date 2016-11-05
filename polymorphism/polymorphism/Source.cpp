
#include <iostream>
#include <string>

using namespace std; 

class Animal {
	int limbs;
	string name;
public:
	Animal(string _n = "animal", int limbs = 5) {
		this->limbs = limbs;
		name = _n;
	}
	string get_name()
	{
		return name;
	}
	void set_name(string n)
	{
		name = n; 
	}
	int get_limbs()
	{
		return limbs; 
	}
	void set_limbs(int l) {
		limbs = l;
	}
	virtual void eat()
	{
		cout << "Animals Eat" << endl;
	}
	virtual void sound()
	{
		cout << "Animal sound" << endl;
	}
	virtual void printinfo()
	{
		cout << "I am an Animal. I have " << get_limbs() << " limbs"; 
	}
};
class Cat :public Animal
{
public:
	Cat() :Animal("cat", 4) {}
	virtual void eat()
	{
		cout << "Cats eat" << endl;
	}
	virtual void sound()
	{
		cout << "Cat sounds" << endl;
	}
	virtual void printinfo() {
		cout << " I am a cat. My name is " << get_name() << endl; 
		Animal::printinfo();
	}
};

int main()
{
	Animal *aptr; 
	Animal a; 
	Cat c; 
	char choice;
	cout << "Do you want a cat or any animal" << endl; 
	cin >> choice; 
	if (choice == 'a')
	{
		aptr = &a;//new Animal;
	}
	else
	{
		aptr = &c;//new Cat;
	}
	int dchoice = 0; 
	while (dchoice!= -1)
	{
		cout << "Do you want to feed your pet (1), play with it (2), printinfo(3) or quit(-1)" << endl;
		cin >> dchoice; 
		switch (dchoice)
		{
		case 1:
			aptr->eat(); 
			break; 
		case 2:
			aptr->sound(); 
			break; 
		case 3:
			aptr->printinfo(); 
			break; 
		default:
			break;
		}
	}
//	delete aptr;
	return 0;
}