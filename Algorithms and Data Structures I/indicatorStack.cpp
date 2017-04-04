#include <iostream>
#include <cstdio>

typedef int elementtype;
struct celltype {
        elementtype element;
        celltype * next;
};
typedef celltype * position;
class Lista
{
protected:
        position l; // wskaznik do glowy listy
public:
        Lista();
        ~Lista();
        void Insert(elementtype x, position p);
        void Delete(position p);
        elementtype Retrieve(position p);
        position Locate(elementtype x);
        position First();
        position Next(position p);
        position Previous(position p);
        position END();
        void Duplicate();
        void Remove();
        void PUSH(elementtype x);
        void POP();
        void TOP();

};

Lista::Lista()
{
        l = new celltype();
        l->next = NULL;
}

Lista:: ~Lista(){}

void Lista:: Insert(elementtype x, position p){
        position tmp = p->next;
        p->next = new celltype;
        p->next->element = x;
        p->next->next = tmp;
}

void Lista::Delete(position p)
{
        position tmp;
        tmp = p->next;
        p->next = p->next->next;
        delete tmp;
}

elementtype Lista::Retrieve(position p)
{
        if (p->next != NULL)
                return p->next->element;

}

position Lista::Locate(elementtype x)
{
        position tmp;
        tmp = l;
        while (tmp->next != NULL)
        {
                if (tmp->next->element == x)  return tmp;
                tmp = tmp->next;
        }
        return tmp;

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
        tmp = l;
        while (tmp->next != p)
        {
                tmp = tmp->next;
        }
        return tmp;


}

position Lista::END()
{
        position p = l;
        while (p->next != NULL){
                p = p->next;
        }
        return p;
}


void Lista::PUSH(elementtype x)
{
        Insert(x,First());

}

void Lista::POP()
{
        Delete(l);
}

void Lista::TOP()
{
        std::cout<<Retrieve(First())<<std::endl;
}

void print(Lista l){
        position i = l.First();
        while (i != l.END())
        {
                std::cout << l.Retrieve(i);
                //printf("  %d,", l.Retrieve(i));
                i = l.Next(i);
        }
        printf("\n");

}



int main()
{
        Lista lista;
        std::cout << "Dodaje element 5" << std::endl;
        lista.PUSH(5);
        std::cout << "Na gorze jest:" << std::endl;
        lista.TOP();
        std::cout << "Dodaje element 4" << std::endl;
        lista.PUSH(4);
        std::cout << "Na gorze jest: " << std::endl;
        lista.TOP();
        std::cout << "POP()" << std::endl;
        lista.POP();
        std::cout << "Na gorze jest: " << std::endl;
        lista.TOP();
}
