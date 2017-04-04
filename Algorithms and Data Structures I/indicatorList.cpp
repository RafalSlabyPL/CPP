#include <iostream>
#include <cstdio>

using namespace std;

typedef int elementtype;

struct celltype
{
	elementtype element;
	celltype * next;
};

typedef celltype * position;

class Lista
{
	protected :
	position l; // wskaznik do glowy listy

	public:
	Lista();
	~Lista(); //destruktor
	void Insert(elementtype x, position p);
	void Delete(position p);
	void Print();
	elementtype Retrieve(position p);
	position Locate(elementtype x);
	position First();
	position Next(position p);
	position Previous(position p);
	position END();
};

elementtype Lista::Retrieve(position p)
{
	if (p->next!=NULL)
	return p->next->element;
}

position Lista::First()
{
	return l;
}

position Lista::Next(position p)
{
	return p->next;
}

position Lista::Previous(position p)
{
	position tmp;
	tmp=l;
	while (tmp->next!=p)
	{
		tmp=tmp->next;
	}
	return tmp;
}

position Lista::END()
{
	position tmp;
	tmp=l;
	while (tmp->next!=NULL)
	{
		tmp=tmp->next;
	}
	return tmp;
}

void Lista::Insert(elementtype x, position p)
{
	position tmp;
	tmp=p->next;
	p->next=new celltype;
	p->next->element=x;
	p->next->next=tmp;

}

void Lista::Delete(position p)
{
	position tmp;
	tmp=p->next;
	p->next=p->next->next;
	delete tmp;
}

position Lista::Locate(elementtype x)
{
	position tmp;
	tmp=l;

	while (tmp->next!=NULL)
	{
		if (tmp->next->element==x)
		{
			return tmp;
		}
		tmp=tmp->next;
	}

	return tmp;
}

void Lista::Print()
{
	position i=First();

	while (i!=END())
	{
		printf ("  %d,", Retrieve(i));
		i=Next(i);
	}
	printf("\n");
}

Lista::Lista() //tworzymy komorke header
{
	l=new celltype;
	l->next=NULL;
}

Lista::~Lista()
{
	position tmp;

	while (l->next!=NULL)
	{
		tmp=l->next;
		l->next=tmp->next;
		delete tmp;
	}

	delete l;

}


int main()
{
	Lista a;
	cout << "Wstawiam 100 do listy" << endl;
	a.Insert(100,a.First());
	cout<<"Drukowanie listy: ";
	a.Print();

	cout << "Dodaje 3 elementy do listy" << endl;
	for (int i=0; i<3;i++)
	{
		a.Insert(i,a.First());
	}
	cout<<"Drukowanie listy: ";
	a.Print();

	cout << "Wstawiam 20 do listy" << endl;
	a.Insert(20, a.Previous( a.END() ));
    cout<<"Drukowanie listy: ";
	a.Print();

	cout << "Usuwam 20 z listy" << endl;
	a.Delete( a.Locate(20) );
	cout<<"Drukowanie listy: ";
	a.Print();

	cout << "Wstawiam wartosc 50 przed wartoscia 1 " << endl;
	a.Insert(50, a.Locate( 1 ) );
	cout<<"Drukowanie listy: ";
	a.Print();
	a.Insert(30, a.Next(a.Locate( 1 )) );
	a.Print();


}
