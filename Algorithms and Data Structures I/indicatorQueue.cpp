#include <iostream>

using namespace std;

typedef int elementtype;

typedef struct celltype
{
	elementtype element;
	celltype * next;
};
typedef celltype * position;

class Queue
{
	protected:
		position Front;
		position Rear;
	public:
		Queue();
		~Queue();
		void Enqueue(elementtype x);
		void Dequeue();
		elementtype FrontElem();
		bool Empty();
};

Queue::Queue()
{
	Front=new celltype;
	Rear=Front;
	Front->next=NULL;
}

Queue::~Queue(void)
{
	position tmp;

	while (Front->next!=NULL)
	{
		tmp=Front;
		Front=Front->next;
		delete tmp;
	}
	delete Front;
}

void Queue::Enqueue(elementtype x)
{
	position p=new celltype;
	p->next=NULL;
	p->element=x;
	Rear->next=p;
	Rear=p;
}

void Queue::Dequeue()
{
	if (!Empty())
 	{
		position p=Front;
		Front=Front->next;
		delete p;
	}
}

bool Queue::Empty()
{
	return (Front->next==NULL);
}

elementtype Queue::FrontElem()
{
	if (!Empty())
	return Front->next->element;
}

int main()
{
	Queue k;
	cout << "Czy pusta:" << k.Empty()<<endl;
	cout << "Wstaw 2" << endl;
	k.Enqueue(2);
	cout << "Czy pusta:" << k.Empty()<<endl;
	cout << "Pierwszy element:" << k.FrontElem() <<endl;
	cout << "Wstaw 3" << endl;
	k.Enqueue(3);
	cout << "Pierwszy element:" << k.FrontElem() <<endl;
	cout << "Usuwanie" << endl;
	k.Dequeue();
	cout << "Pierwszy element:" << k.FrontElem() <<endl;
}
