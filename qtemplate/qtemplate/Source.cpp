#define defaultsize 5
#define emptyqueue -1
#include <iostream>

using namespace std; 

template <class T>
class queue {
	int maxSize; 
	int curSize; 
	T *qarr;
	class queueFull{};
	class queueEmpty{};
	void movedown()
	{
		//on every dequeue move it all down 
		for (int i = 1; i < curSize; i++)
			qarr[i - 1] = qarr[i]; 
		curSize--;
	}
public:
	queue(int size=defaultsize)
	{
		maxSize = size; 
		curSize = emptyqueue; 
		qarr = new T[maxSize];

	}
	bool isFull()
	{
		return (curSize == (maxSize - 1));
	}
	bool isEmpty()
	{
		return (curSize == emptyqueue);
	}
	void enqueue(T item)
	{
		if (isFull())
		{
			throw queueFull();
		}
		curSize++;
		qarr[curSize] = item;
	}
	T dequeue()
	{
		if (isEmpty())
		{
			throw queueEmpty();
		}
		T toret = qarr[0]; 
		movedown();
		return toret;
	}
	void print()
	{
		cout << endl;
		for (int i = 0; i < currSize; i++)
			cout << qarr[i] << "\t";
		cout << endl;
	}
	T getTop()
	{
		if (!isEmpty())
			return qarr[0];
		else
			throw queueEmpty();
	}

};

int main()
{
	int qsize = 4;
	queue<double> aq(qsize); 
	for (int i = 0; i < qsize; i++)
	{
		aq.enqueue(i + 2);
		cout<<aq.dequeue();
	}
	for (int i = 0; i < qsize; i++)
	{
		aq.enqueue(i + 2);
	}
	cout << endl;
	for (int i = 0; i < qsize; i++)
	{
		cout<<aq.dequeue();
	}
	return 0;
}