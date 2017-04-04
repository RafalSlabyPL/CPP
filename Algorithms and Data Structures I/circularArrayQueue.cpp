#include <iostream>

using namespace std;

const int maxlength=10;
typedef int elementtype;

class Kolejka
{
	protected :
		elementtype Queue[maxlength];
		int Front;
		int Rear;
	public:
		Kolejka();
		int AddOne(int i);
		void Enqueue(elementtype x);
		void Dequeue();
		void Print();
		elementtype FrontElem();
		void Makenull();
		bool Empty();
};

Kolejka::Kolejka()
{
	Front=0;
	Rear=maxlength-1;
}

int Kolejka::AddOne(int i)
{
	return ((i + 1) % maxlength);
}

bool Kolejka::Empty()
{
	return (AddOne(Rear) == Front);
}

void Kolejka::Enqueue(elementtype x)
{
	if ( AddOne(AddOne(Rear)) != Front) //gdy nie jest pełna
	{
		Rear = AddOne(Rear);
		Queue[Rear] = x;
	}
}

void Kolejka::Dequeue()
{
	if (!Empty())
	{
		Front= AddOne(Front);
	}
}

elementtype Kolejka::FrontElem()
{
	if (!Empty())
	{
		return Queue[Front];
	}
}

void Kolejka::Makenull()
{
	Front=0;
	Rear=maxlength-1;
}

void Kolejka::Print()
{
	cout << "Wypisanie:" ;
	for (int i=Front; i<=Rear; i++)
	{
		cout << " " << Queue[i] << "," ;
	}
	cout << endl;
}

int main()
{
	int i;
	Kolejka k;
	cout << "Czy kolejka pusta: " << k.Empty()<<endl;
	for (i=0; i<=3; i++)
	{
		cout << "Wstaw " << i << endl;
		k.Enqueue(i);
		k.Print();
	}
	cout << "Czy kolejka pusta: " << k.Empty()<<endl;
	cout << "Usunięcie elementu:" <<endl;
	k.Dequeue();
	k.Print();

}
