#include <iostream>
#include <queue>
using namespace std;

//creating a templated structure for
//a binary tree node
template <class TItem>
struct bstnode {
	TItem data;
	bstnode* right;
	bstnode* left;
	bstnode* parent;
	//constructors for the structure
	bstnode()
	{
		right = NULL;
		left = NULL;
		parent = NULL;
	}
	bstnode(TItem item)
	{
		right = NULL;
		left = NULL;
		parent = NULL;
		data = item;
	}
	bstnode(TItem item, bstnode* p)
	{
		right = NULL;
		left = NULL;
		parent = p;
		data = item;
	}
	bool noleftChild()
	{
		return (left == NULL);
	}
	bool norightChild()
	{
		return (right == NULL);
	}
	bool isExternal()
	{
		return (noleftChild() && norightChild());
	}
	bool hastwochildren()
	{
		return (!(noleftChild()) && !(norightChild()));
	}
	bool hasOneChild()
	{
		return (!isExternal() && !hastwochildren());
	}
};

//creating a templated 
//binary search tree class
template <class T>
class bst {
	bstnode<T>* root;
	//the add function
	void add(T item, bstnode<T>*& h, bstnode<T>* parent) //reference to a pointer
	{
		if (h)	//if the pointer is not null
		{
			if (item >= h->data)	//if the item to be added 
									//is greater than the data in h
			{
				add(item, h->right, h); //go to the right subtree
			}
			else    //otherwise the item should be added to left subtree
			{
				add(item, h->left, h); //go to the left subtree
			}
		}
		else
		{
			h = new bstnode<T>(item, parent); //if the node is null, add here
		}
	}
public:
	bst() {
		root = NULL;
	}


	void add(T item) //an overloaded add function
	{
		add(item, root, NULL);
	}
	bst& operator+(T item)
	{
		add(item);
		return *this;
	}
	void preorder(bstnode<T>* h)
	{
		if (h)
		{
			cout << h->data << "\t";
			preorder(h->left);
			preorder(h->right);
		}
	}
	void preorder()
	{
		preorder(root);
	}
	void inorder(bstnode<T>* h)
	{
		if (h)
		{
			inorder(h->left);
			cout << h->data << "\t";
			inorder(h->right);
		}
	}
	void inorder()
	{
		inorder(root);
	}
	void postorder(bstnode<T>* h)
	{
		if (h)
		{
			postorder(h->left);
			postorder(h->right);
			cout << h->data;
		}
	}
	void postorder()
	{
		postorder(root);
	}

	friend istream &operator>>(istream  &input, bst<T> &D)
	{
		T item;
		input >> item;
		D.add(item);
		return input;
	}
	bstnode<T>* find(T item)
	{
		bstnode<T>* cur = root;
		bstnode<T>* toret = NULL;
		while (cur != NULL && cur->data != item)
		{
			if (item >= cur->data)
			{
				cur = cur->right;
			}
			else
				cur = cur->left;
		}
		if (cur)
		{
			if (cur->data == item)
			{
				toret = cur;
			}
		}
		return toret;
	}
	bstnode<T>* getMax(bstnode<T>* cur)
	{
		//bstnode<T>* cur = root; 
		if (cur)
		{
			while (cur->right)
			{
				cur = cur->right;
			}
		}
		return cur;
	}
	bstnode<T>* getMax()
	{
		return getMax(root);
	}
	bstnode<T>* getMin(bstnode<T>* cur)
	{
		if (cur)
		{
			while (cur->left)
			{
				cur = cur->left;
			}
		}
		return cur;
	}
	bstnode<T>* getMin()
	{
		return getMin(root);
	}
	void remove(bstnode<T>* found)
	{
		if (found)
		{
			if (found->isExternal())
			{
				//delete found 
				//set parent's right or left to NULL 
				if (found->parent) {
					if (found == found->parent->right)
					{
						found->parent->right = NULL;

					}
					else
					{
						found->parent->left = NULL;

					}
				}
				else
					root = NULL;
				delete found;
				found = NULL;

			}
			else if (found->hasOneChild())
			{
				bstnode<T>* fchild = NULL;
				if (found->noleftChild())
				{
					fchild = found->right;
				}
				else
					fchild = found->left;
				if (found->parent)
				{
					if (found == found->parent->right)
					{
						found->parent->right = fchild;
						
					}
					else {
						found->parent->left = fchild;
					}
				}
				else
					root = fchild;
				fchild->parent = found->parent;
				delete found;
				found = NULL;
			}
			else
			{
				//two children 
				//left subtree, rightmost = left subtree + max
				cout << "has two kids" << endl;
				bstnode<T>* toswap = getMax(found->left);
				bstnode<T>* toswapP = toswap->parent;
				T temp = toswap->data;
				toswap->data = found->data;
				found->data = temp;
				remove(toswap);

			}
		}
	}
	void remove(T item)
	{
		bstnode<T> * found = find(item);
		remove(found);
	}
	~bst()
	{
		while (root)
		{
			remove(root);
		}
	}
	int depth(bstnode<T>* node, int d)
	{
		if (node)
		{
			d++; 
			int d1 = d; 
			int d2 = d; 
			d1=depth(node->left, d1);
			d2=depth(node->right, d2);
			d = (d1 > d2 ? d1 : d2);
		}
		return d;
	}
	int depth()
	{
		return depth(root, 0)-1;
	}
};
template <class Tt>
ostream& operator<<(ostream& os, bst<Tt>& tree)
{
	tree.preorder();
	return os;
}
void testbst()

{
	bst<char> intbst;
	intbst.add('M');
	intbst.add('E');
	intbst.add('C');
	intbst.add('H');
	intbst.add('A');
	intbst.add('T');
	intbst.add('R');
	intbst.add('O');
	intbst.add('N');
	intbst.add('I');
	//intbst.add('C');
	intbst.add('S');
	//cin >> intbst;
	cout << endl;
	intbst.preorder();
	cout << endl;
	intbst.postorder();
	cout << endl;
	intbst.inorder();
	cout << endl;
	intbst.remove('S');
	cout << intbst;
	cout << endl;
	intbst.remove('M'); 
	cout << intbst;
	cout << endl;
	intbst.remove('A');
	cout << intbst;
	cout << endl;

	intbst.remove('T');
	cout << intbst;
	cout << endl;
}
void testbstnum()
{
	bst<int> ibst;
	ibst.add(50);
	ibst.add(25);
	ibst.add(75);
	ibst.add(12);
	ibst.add(13);
	ibst.add(11);
	ibst.add(5);
	ibst.add(6);
	ibst.add(7);
	ibst.add(8);
	ibst.add(9);
	ibst.add(10);
	//ibst.add(37);
	ibst.add(60);
	cout << ibst.depth();
}
int main()
{

	//testbst();
	testbstnum();
	return 0;
}