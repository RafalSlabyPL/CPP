#include<iostream>
#include<cstdio>
using namespace std;
typedef int elementtype, position ;
const int maxlength=10;
struct List
{
	elementtype elements[maxlength];
	int last;           //indeks ostatniego elementu listy
};

position END(List l)
{
	return l.last+1;
}

position First(List l)
{
	return 0;
}

position Next(position p,List l)
{
	return p+1;
}


position Previous(position p,List l)
{
	return p-1;
}


position Locate(elementtype x, List l)
{ //zwraca pozycje x w l, gdy nie ma x w l zwraca end(l)
	int i=0;
	for(i; i<END(l); i++)
	{
		if(l.elements[i]==x)
		{
			return i;
		}
	}

	return END(l);
}

elementtype Retrieve(position p, List l)
{
	return l.elements[p];
}

bool Insert(int x, position p, List &l)
{
	if (p==END(l))
	{
		l.elements[0]=x;
		l.last++;
	}
	else if (p<END(l))
	{
		position k=END(l)-1;

		while(k>=p)
		{
			l.elements[k+1]=l.elements[k];
			k--;
		}
		l.elements[p]=x;
		l.last++;
	}
}

bool Delete(position p, List &l)
{

	while (p< (END(l)-1))
	{
		l.elements[p] = l.elements[p + 1];
		p++;
	}

	l.last--;

}

void print(List l)
{
	position i=First(l);
	while (i!=END(l))
	{
		printf ("  %d,", Retrieve(i,l));
		i=Next(i,l);
	}
	printf("\n");

}

int main()
{
	List lista;
	lista.last=-1;
	cout <<"Wstawianie 100"<<endl;
	Insert(100,First(lista),lista);
	cout<<"Drukowanie listy: ";
	print (lista);

	cout <<"Wstawiam dodatkowe 3 elementy"<<endl;
	for (int i=0; i<3;i++)
	Insert(i,First(lista),lista);
	cout<<"Drokowanie listy: ";
	print (lista);

	cout <<"Wstawiam 20 po 100"<<endl;
	Insert (20,Previous(END(lista),lista) ,lista);
	cout<<"Drukowanie listy: ";
	print(lista);

	cout<<"Znajduje pozycje 20 na liscie: "<<Locate(20,lista)<<endl;
	cout<<"Znajduje pozycje 1 na liscie: "<<Locate(1,lista)<<endl;

	cout <<"Usuwam 20 z listy"<<endl;
	Delete( Locate(20,lista),lista);
	cout<<"Drokowanie listy: ";
	print(lista);

}
