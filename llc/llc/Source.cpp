#include <iostream>
#include <string>
using namespace std; 
#define DEBUG_F true

//a linked list 

typedef int elemtype; //everytime i write elemtype , think its an int. giving int a nickname/alias

struct node {
	elemtype data;  //same as saying int data 
	node *next; 
};

void displaylist(node * h)
{
	cout << "\n---" << endl;
	int count = 0;
	while (h != NULL)
	{
		cout << count<<"\t"<<h->data << endl; 
		h = h->next; count++;
	}
	cout << "---" << endl;;
	if (DEBUG_F)
	cin.get();
}

void addtoendoflist(node*&h, elemtype datatoadd)
{
	//create new node 
	node* temp = new node; 
	temp->data = datatoadd; 
	temp->next = NULL; 

	if (h!=NULL)
	{
		node * headcopy = h; 
		while (headcopy->next!= NULL)
		{
			headcopy = headcopy->next;
		}
		headcopy->next = temp;
	}
	else
	{
		h = temp;
	}

}

void deletelist(node*&head)
{
	node * todel;
	while (head)
	{
		todel = head;
		head = head->next; 
		delete todel; 
	}
}


void deletelast(node*&head)
{
	node*todel = head;
	node*prev = NULL;
	while (todel->next != NULL)
	{
		prev = todel;
		todel = todel->next;
	}
	if (prev)
	{
		prev->next = NULL;
		delete todel;
	}
	else
	{
		delete todel;
		head = NULL;
	}

}

void addtobeg(node*&head, elemtype data)
{
	node * temp = new node;
	temp->data = data;
	temp->next = head;
	head = temp;
}
void deletebeg(node*&head)
{
	node * todel = head;
	if (todel)
	{
		head = head->next;
		delete todel;
	}
}
void deleteatn(node *&head, int n)
{
	if (n > 0 && head!=NULL) {
		//get to n 
		node* prev = NULL;
		node* cur = head;
		int i = 0;
	
		for (; (i < n) && (cur != NULL);  i++, cur = cur->next)
		{
			prev = cur;
		}
		if (prev)
		{
			if (i == n )
			{
				prev->next = cur->next;
				delete cur;
			}
			else
				cout << "\nNode does not exist" << endl;
		}
		else
		{
			head = NULL;
			delete cur;
		}
	}
	else
	{
		deletebeg(head);
	}
}
int getlistlen(node * head)
{
	int listsize = 0;
	while (head != NULL)
	{
		listsize++;
		head = head->next;
	}
	if (DEBUG_F)
	{
		cout << "\nSize of list is " << listsize << endl;
	}
	return listsize;
}
void addatn(node *&head, int n, elemtype data)
{
	if (n >= 0) {
		if (n == 0 || head == NULL)
		{
			addtobeg(head, data);
		}
		else
		{
			//get to n-1 th node 
			int i = 0;
			node* hc = head;
			for (i = 0; i < (n-1) && hc->next != NULL; i++, hc = hc->next);
			if (i == (n-1))
			{
				node*temp = new node;
				temp->data = data;
				temp->next = hc->next;
				hc->next = temp;
			}
			else
			{
				cout << "\nLocation does not exist" << endl;
			}


		}
	}
	else
		cout << "\nInvalid" << endl;
}

void print(string msg)
{
	cout <<"\n"<< msg << endl;
}

int main()
{
	node*head = NULL; 
	print("Adding to the end of an empty list, 0 - 4");
	for (int i = 0; i < 5; i++)
	{
		addtoendoflist(head, i);
		
	}

	displaylist(head);
	print("Deleteing numbers 0 to 4 from the new list using del last");
	for (int i = 0; i < 5; i++)
	{
		deletelast(head);
	}
	displaylist(head);
	print("Adding to the beg of an empty list, 0 - 4");
	for (int i = 0; i < 5; i++)
	{
		addtobeg(head, i + 1);
	}
	displaylist(head); 
	print("Deleting from beg, 0 - 4");
	for (int i = 0; i < 5; i++)
	{
		deletebeg(head);
	}
	displaylist(head); 
	print("Adding to the end and beg");
	for (int i = 0; i < 5; i++)
	{
		addtobeg(head, i+2); 
		addtoendoflist(head, i+3);
		displaylist(head);
	}
	displaylist(head);
	print("addatn(head, 0, 500);");
	addatn(head, 0, 500);
	displaylist(head);

	print("addatn(head, 5, 600);");
	addatn(head, 5, 600);
	displaylist(head);
	int listlen = getlistlen(head);
	
	print("addatn(head, listlen, 700);");
	addatn(head, listlen, 700);
	displaylist(head);

	print("addatn(head, listlen+2, 900);");
	addatn(head, listlen + 2, 900);
	displaylist(head);

	print("addatn(head, listlen+89, 300);");
	addatn(head, listlen + 89, 300);
	displaylist(head);

	print("delete from beg and last");
	for (int i = 0; i < 3; i++)
	{
		deletebeg(head);
		deletelast(head);
		displaylist(head);
	}
	displaylist(head);
	print("deleteatn(head, 0);");
	deleteatn(head, 0);
	displaylist(head);

	print("deleteatn(head, 3);");
	deleteatn(head, 3);
	displaylist(head);

	listlen = getlistlen(head);

	print("deleteatn(head, listlen);");
	deleteatn(head, listlen);
	displaylist(head);

	print("deleteatn(head, listlen);");
	deleteatn(head, listlen);
	displaylist(head);
	return 0;
}
