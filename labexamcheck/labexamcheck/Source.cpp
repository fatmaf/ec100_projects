#include <iostream>
#include <string>

using namespace std;
template <class T>
struct node {
	T data;
	node* next;
	node* prev;
};
template <class Litem>
class linkedList {
	node<Litem>* head;
	node<Litem>* tail;
public:

	linkedList()
	{
		head = NULL;
		tail = NULL;
	}
	bool isEmpty()
	{
		return (head == tail) && (head == NULL);
	}


	void addtoend(Litem item)
	{
		if (isEmpty())
		{
			head = new node<Litem>;
			head->data = item;
			head->next = NULL;
			head->prev = NULL;
			tail = head;
		}
		else
		{
			tail->next = new node<Litem>;
			tail->next->prev = tail;
			tail = tail->next;
			tail->next = NULL;
			tail->data = item;
		}
	}
	void addtostart(Litem item)
	{
		if (isEmpty())
		{
			head = new node<Litem>;
			head->data = item;
			head->next = NULL;
			head->prev = NULL;
			tail = head;
		}
		else
		{
			node<Litem>*ptr = new node<Litem>;
			ptr->data = item;
			ptr->next = head;
			ptr->prev = NULL;
			head->prev = ptr;
			head = ptr;
		}
	}
	void removefromend()
	{
		if (!isEmpty())
		{

			node<Litem>* todel = tail;
			tail = tail->prev;
			if (tail) {
				tail->next = NULL;
			}
			if (todel == head)
				head = NULL;
			delete todel;
		}
	}
	void removefromfront()
	{
		if (!isEmpty())
		{
			node<Litem> * todel = head;
			head = head->next;
			if (head)
				head->prev = NULL;
			if (todel == tail)
				tail = NULL;
			delete todel;
		}
	}
	void display()
	{
		cout << endl;
		for (node<Litem>* cur = head; cur != NULL; cur = cur->next)
		{
			cout << cur->data << "\t";
		}
		cout << endl;
	}


	friend ostream &operator<<(ostream &output, node<Litem>* &ll)
	{
		output << "objects" << ll << endl;
		return output;
	}
	friend istream &operator>>(istream &input, node<Litem>* &l)
	{
		input >> l.addtostart << endl;
		return input;
	}
	friend class restrictedlinkedlist;

	~linkedList()

};
class restrictedlinkedlist::public linkedList
{
	friend ostream &operator<<(ostream &output, node<Litem>* &ll);
	friend istream &operator>>(istream &input, node<Litem>* &l);
	int count();
};
void testlist()
{
	linkedList<int> ll;
	for (int i = 0; i < 5; i++)
	{
		ll.addtoend(i);

	}
	ll.display();
	for (int i = 0; i < 5; i++)
	{
		ll.addtostart(5 - i);
	}
	ll.display();
	for (int i = 0; i < 5; i++)
		ll.removefromend();
	ll.display();
	for (int i = 0; i < 5; i++)
		ll.removefromfront();
	ll.display();
	for (int i = 0; i < 5; i++)
	{
		ll.addtostart(5 - i);

	}
	ll.display();
	for (int i = 0; i < 5; i++)
	{
		ll.addtoend(i);

	}
	ll.display();

	for (int i = 0; i < 5; i++)
		ll.removefromfront();
	ll.display();
	for (int i = 0; i < 5; i++)
		ll.removefromend();
	ll.display();
}
int count()
{
	linkedList<int> ll;
	for (int i = 0; i < 5; i++)
	{
		cout << "the number of elements in the list" << i << endl;
		return i;
	}
}
int main()
{
	testlist();
	count();
	return 0;
}