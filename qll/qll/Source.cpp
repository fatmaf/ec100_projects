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
		return (head == tail) && (head==NULL);
	}
	node<Litem>* findbyitem(int item)
	{
		node<Litem>* toret = NULL; 
		if (!isEmpty())
		{
			node<Litem>*cur = head;
			while (cur!=NULL && cur->data != item)
			{
				cur = cur->next;
			}
			if (cur)
			{
				toret = cur;
			}
		}
		return toret;
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
			if(head)
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

};

int main()
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
	return 0;
}