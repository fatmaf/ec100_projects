#include <iostream>
using namespace std;

const int MAX = 3; //stack holds 3 integers
class Stack
{
private:
	int st[MAX]; //array of integers
	int top; //index of top of stack
public:
	class Range
	{ //note: empty class body
	};
	class Full {
	private: 
		int last_element; 
		int added;
	public:
		Full(int elem,int added){
			last_element = elem;
			this->added = added;
		}
		void display()
		{
			cout << "You tried to add another element " << added << endl; 
			cout << "The last element was " << last_element << endl;
		}
	};
	class Empty{};
		Stack() //constructor
		{
			top = -1;
		}
		void push(int var)
		{
			if (top >= MAX - 1) //if stack full,
				throw Full(st[top],var);
			st[++top] = var; //put number on stack
		}

		int pop()
		{
			if (top < 0) //if stack empty,
				throw Empty();
			return st[top--]; //take number off stack
		}
		void illus()
		{
			throw Range();
		}
	};

	int main()
	{
		Stack s1;
		try {
			//s1.illus();
			s1.push(11);
			s1.push(22);
			s1.push(33);
			s1.push(44); //oops: stack full
			s1.illus();
			cout << "1: " << s1.pop() << endl;
			cout << "2: " << s1.pop() << endl;
			cout << "3: " << s1.pop() << endl;
			cout << "4: " << s1.pop() << endl; //oops: stack empty   
		}
		catch (Stack::Empty) {
			cout << "Error occurred - Empty Stack - Underflow" << endl;
		}
		catch (Stack::Full obj)
		{
			cout << "Error occurred - Full Stack - Overflow" << endl;
			obj.display();
		}
		catch (...)
		{
			cout << "General Error occurred" << endl;
		}
		//s1.pop();
		cout << "The end" << endl;
			return 0;
		}

