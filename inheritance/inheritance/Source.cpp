#include <iostream>
#include <string>
using namespace std; 

class B {
	int x; 
protected:
	int y; 
public:
	int z; 
	B() {
		x = 10; y = 5; z = 2; 
	}
};

class C : private B{

public:
	C()
	{
		y = 5; 
		z = 2; 
	}
};

class D : public C {
public:
	D()
	{
		y = 5; 
		z = 3;
	}
};

class E : public D
{
public:
	E()
	{
		y = 5; 
		z = 3; 
	}

};
class F : public E
{
public: 
	F()
	{
		y = 5; 
		z = 3;
	}
};
//class Person {
//private:
//	string name_; int id_;
//public:
//	Person(string n, int ident) :name_(n), id_(ident) {};
//	string get_name() { return name_; }
//	int get_id() { return id_; }};
//class Student : public Person {
//private:
//	int degree_; double gpa_;
//public:
//	Student(string n, int ident, int degree):Person(n,ident),
//		degree_(degree),gpa_(0.0){}
//	int get_degree() { return degree_; }
//	double get_gpa() { return gpa_; }
//	void set_gpa(double gpa) { gpa_ = gpa; }
//	void print()
//	{
//		cout << degree_ << gpa_ << get_name() << get_id() << endl;
//	}
//};
//void testStudent()
//{
//	Student s1("arham", 32, 33);
//	s1.print();
//}
//void testPerson()
//{	Person aperson("Name", 123); 
//	cout << "Name: " << aperson.get_name() 
//		<< " Id: " << aperson.get_id() << endl;}
//int main()
//{
//	testPerson();
//	return 0;



