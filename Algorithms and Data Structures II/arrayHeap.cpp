#include <iostream>
#include <algorithm>

using namespace std;

class heap
{
private:
    float array[20];
    int counter=0;

public:
    void numberInput();
    void printNumbers();
    int pierwszeDziecko(int indeksRodzica);
    int rodzic(int indeksDziecka);
    void buildHeap(int i);
    float pobierzNajwiekszy();
    void addNewFloat();
    void heapSort();

};

void heap::numberInput()
    {

        cout<<"Podaj do 20 liczb, lub zakoncz wciskajac dowolna litere\n";

        for(int i = 0; 20 > counter; i++)
            {
            float temporary;
            cin>> temporary;
            if(cin.good())
                {
                counter++;
                array[i]= temporary;
                if(counter<20)cout<<"W kopczyku zostalo "<<20-counter<<" miejsc\n"; //aby nie wypisywalo ze zostalo 0 miejsc
                cin.clear();
                cin.sync();
                }
            else
                {
                cin.clear();
                cin.sync();
                break;
                }
            }
    }

void heap::printNumbers()
    {
        cout<<"\n";
        for(int i=0;i<counter;i++)
            {
            cout<<array[i]<<" ";
            }
        cout<<"\n";
    }

int heap::pierwszeDziecko(int indeksRodzica)
    {
    if((indeksRodzica + (indeksRodzica+1)-1> counter))return indeksRodzica;
    else return indeksRodzica + (indeksRodzica+1);
    }

int heap::rodzic(int indeksDziecka)
    {
    if(indeksDziecka%2!=0) return indeksDziecka/2;
    else return (indeksDziecka/2)-1;
    }

void heap::buildHeap(int i)
    {
    bool wroc = false;
    while(i!=pierwszeDziecko(i))
        {
        for(int k=0;k<2;k++)
            {
            if( (array[i] < array[(pierwszeDziecko(i))+k]) && ((pierwszeDziecko(i)+k)<counter) )
                {
                swap(array[i], array[pierwszeDziecko(i)+k]);
                if(i>0)wroc = true;
                }
            }
        if(wroc==false)i++;
        else
            {
            wroc =false;
            i= rodzic(i);
            }
        }
    }

float heap::pobierzNajwiekszy()
    {
    float wynik = array[0];
    array[0]=array[counter-1];
    counter--;
    buildHeap(0);
    return wynik;
    }

void heap::addNewFloat()
    {
    cout<<"\nPodaj element do wstawienia ";
    float temporary;
    cin>>temporary;
    if(cin.good() && counter<20)
        {
        counter++;
        array[counter-1]= temporary;
        if(counter<20)cout<<"\n\nWstawiono "<<temporary<<" na "<<counter<<" miejsce"; //aby nie wypisywalo ze zostalo 0 miejsc
        cin.clear();
        printNumbers();
        }
    else cout<<"zly format danych lub pelny kopiec";
    buildHeap(rodzic(counter-1));
    cout<<"\nI przywrocono wlasnosc kopca";
    }

void heap::heapSort()
    {
        cout<<"\nHeap Sort na powyzszym kopcu";
        int wielkoscKopca = counter;
        while(counter>1)
            {
            swap(array[0], array[counter-1]);
            counter--;
            buildHeap(0);
            }
        counter = wielkoscKopca;
        printNumbers();
    }


int main()
{
    heap a;
    a.numberInput();
    a.printNumbers();
    a.buildHeap(0);
    a.printNumbers();
    cout<<"\nNajwiekszy element to "<<a.pobierzNajwiekszy();
    a.printNumbers();
    a.addNewFloat();
    a.printNumbers();
    a.heapSort();
}
