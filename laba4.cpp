

#include <iostream>

using namespace std;

struct Spis2 {
    int info;
    Spis2* prev, * next;
};

//создание первого элемента
void createElement(Spis2 **b, Spis2 **e, int value) {
    Spis2* t = new Spis2;
    t->info = value;
    t->next = t->prev = NULL;
    *b = *e = t;
}

//добавление элемента в конец списка
void addEnd(Spis2** e, int value) {
    Spis2* t = new Spis2;
    t->info = value;
    t->next = NULL;
    t->prev = *e;
    (*e)->next = t;
    *e = t;
}

//добавление элемента в начало списка
void addBegin(Spis2** b, int value) {
    Spis2* t = new Spis2;
    t->info = value;
    t->prev = NULL;
    t->next = *b;
    (*b)->prev = t;
    *b = t;
}

//просмотр списка с конца
void viewEnd(Spis2* e) {
    while (e != NULL) {
        cout << e->info << endl;
        e = e->prev;
    }
}

//просмотр списка с начала
void viewBegin(Spis2* b) {
    while (b != NULL) {
        cout << b->info << endl;
        b = b->next;
    }
}

Spis2* deleteHead(Spis2* h)
{
    if (h == NULL)
        return NULL;

    Spis2* del = h;
    int x = h->info;
    h = h->next;

    if (h != NULL)
        h->prev = NULL;

    delete del;
    return h;
}

Spis2* deleteEnd(Spis2* e)
{
    if (e == NULL)
        return NULL;

    Spis2* del = e;
    int x = e->info;
    e = e->prev;

    if (e != NULL)
        e->next = NULL;

    delete del;
    return e;
}

//удаление четных элементов списка
Spis2* dellEven(Spis2** begin, Spis2** end)
{
    addBegin(&*begin,3);
    addEnd(&*end, 3);
    Spis2* b = *begin, * e = *end;
    while (b->next)
    {
        if (b->next->info % 2 == 0)
        {
            Spis2* m = b->next;
            b->next = m->next;
            m->next->prev = b;
            delete m;
        }
        else
            b = b->next;
    }
    *begin = deleteHead(*begin);
    //if (*begin == *end) *begin = *end =  NULL;
    if(*begin!=*end) *end = deleteEnd(*end);
    return *begin;
}

void dellAll(Spis2** b) {
    Spis2* buf;
    while (*b != NULL) {
        buf = *b;
        *b = (*b)->next;
        delete buf;
    }
}

int main() {
    Spis2* begin = NULL, * end = NULL, * t=NULL;
    
    while (true) {
        cout << "1. Create double list" << endl;
        cout << "2. Add element at the end" << endl;
        cout << "3. Add element at the start" << endl;
        cout << "4. View list at the end" << endl;
        cout << "5. View list at the start" << endl;
        cout << "6. Delete even elements" << endl;
        cout << "7. Delete all" << endl;
        cout << "0. Exit" << endl;
        int p, in;
        cin >> p;
        switch (p) {
        case 1:
            cout << "Enter first element:" << endl;
            cin >> in;
            createElement(&begin, &end, in);
            system("pause");
            break;

        case 2:
            cout << "Enter element:" << endl;
            cin >> in;
            addEnd(&end, in);
            system("pause");
            break;

        case 3:
            cout << "Enter element:" << endl;
            cin >> in;
            addBegin(&begin, in);
            system("pause");
            break;

        case 4:
            cout << "List:" << endl;
            viewEnd(end);
            system("pause");
            break;

        case 5:
            cout << "List:" << endl;
            viewBegin(begin);
            system("pause");
            break;

        case 6:
            dellEven(&begin, &end);
            system("pause");
            break;

        case 7:
            dellAll(&begin);
            system("pause");
            break;

        case 0:
            dellAll(&begin);
            return 0;
        }
    }
}

