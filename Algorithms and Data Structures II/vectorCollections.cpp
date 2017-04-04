#include <iostream>
#include <vector>
#include <cstdio>

class zbior{
private:
    std::vector < int > dane;
public:
    int returnSize() //zwraca wielkosc wektora
    {
        return dane.size();
    }

    void removeInt(int x)//usuwa pozycje pod indexem zadanym intem
    {
        dane.erase(dane.begin() + x);
    }

    int returnInt(int x)//zwraca int znajdujacy sie na pozycji zadanej intem
    {
        return dane[x];
    }

    bool addNewInt(int x)//sprawdza czy dodawany element nie jest juz w zbioze- jezeli nie dodaje go
    {
        for( size_t i = 0; i < dane.size(); i++ )
            {
            if (x==dane[i]) return 0;
            }
        dane.push_back(x);
        return 1;
    }

    int findInt (int x)//zwraca index zadanego int-a, lub -1 gdy nie znaleziono
    {
    for( size_t i = 0; i < dane.size(); i++ )
        {
        if (dane[i]==x) return i;
        }
        return -1;
    }

    void printData()//drukuje vector data
    {
    for( size_t i = 0; i < dane.size(); i++ )
         printf( "%d, ", dane[ i ] );
    }

};

zbior sumaZbiorow(zbior a, zbior b) // zwraca sume zbiorow bez powtorzen
{
    for( size_t i = 0; i < b.returnSize(); i++ )
        {
        a.addNewInt(b.returnInt(i));
        }
        return a;
}

zbior roznicaZbiorow(zbior a, zbior b) //zwraca wynik dialania A/B
{
    zbior temp;
    for (size_t i = 0; i < a.returnSize(); i++)
        {
        if ((b.findInt(a.returnInt(i))) < 0)
            {
            temp.addNewInt(a.returnInt(i));
            }
        }
        return temp;
}

zbior iloczynZbiorow (zbior a, zbior b) //Zwraca czesc wspolna zbiorow A i B
{
    zbior temp;
    for (size_t i = 0; i < a.returnSize(); i++)
        {
        if ((b.findInt(a.returnInt(i))) >= 0)
            {
            temp.addNewInt(a.returnInt(i));
            }
        }
        return temp;
}

zbior roznicaSymetrycznaZbioru(zbior a, zbior b)
{
    zbior czescWspolna = iloczynZbiorow(a,b);
    zbior suma = sumaZbiorow(a,b);
    return roznicaZbiorow(suma, czescWspolna);
}

int main()
{
    zbior a;
    a.addNewInt(1);
    a.addNewInt(2);
    a.addNewInt(3);

    zbior b;
    b.addNewInt(1);
    b.addNewInt(2);
    b.addNewInt(4);

    std::cout<<"Zbior A: ";
    a.printData();
    std::cout<<std::endl<<"Zbior B: ";
    b.printData();

    zbior c = roznicaZbiorow(a,b);
    std::cout<<std::endl<<std::endl<<"Roznica zbiorow: ";
    c.printData();

    zbior d = sumaZbiorow(a,b);
    std::cout<<std::endl<<std::endl<<"Suma zbiorow: ";
    d.printData();

    zbior e = iloczynZbiorow(a,b);
    std::cout<<std::endl<<std::endl<<"Iloczyn zbiorow: ";
    e.printData();

    zbior f = roznicaSymetrycznaZbioru(a,b);
    std::cout<<std::endl<<std::endl<<"Roznica symetryczna zbiorow: ";
    f.printData();

    std::cout<<std::endl;
    return 0;

}
