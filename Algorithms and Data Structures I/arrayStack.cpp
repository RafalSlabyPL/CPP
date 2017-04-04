#include <iostream>

using namespace std;

const int maxlegth=20;

typedef int elementtype;
typedef int position;

class Stos
{
	int S[maxlegth] ;
	position Top;//szczyt stosu

	public:
	Stos();
	void Push(elementtype x);
	void Pop();
	bool Empty();
	elementtype TopElem();
	void Makenull();
};

Stos::Stos(void)
{
	Top=-1;
}

void Stos::Makenull()
{
	Top=-1;
}

void Stos::Push(elementtype x)
{
	if (Top <maxlegth-1)
 	{
 		Top++;
 		S[Top]= x;
 	}
}

void Stos::Pop()
{
	if (Top >= 0) Top--;
}

bool Stos::Empty()
{
	return (Top==-1);
}

elementtype Stos::TopElem()
{
	if (Top>=0) return S[Top];
}

int main()
{
	Stos stos;

	cout<<"Czy stos pusty: "<<stos.Empty()<<endl;
	cout<<"Wstawiam wartos 1"<<endl;
	stos.Push(1);
	cout<<"Gorna wartosc: "<<stos.TopElem()<<endl;
	cout<<"Czy stos pusty: "<<stos.Empty()<<endl;
	cout<<"stos.Pop(): "<<endl;
	stos.Pop();
	cout<<"Czy stos pusty:"<<stos.Empty()<<endl;
    cout<<"Wstawiam wartosci 2 i 3"<<endl;
	stos.Push(2);
	stos.Push(3);
	cout<<"Gorna wartosc:"<<stos.TopElem()<<endl;
	stos.Makenull();
	cout<<"Usuwanie elementow na stosie"<<endl;
	cout<<"Czy stos pusty: "<<stos.Empty()<<endl;

}
