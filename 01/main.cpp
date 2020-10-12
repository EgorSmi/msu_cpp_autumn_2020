#include <iostream>
#include "Allocator.h"

using namespace std;

int main()
{
    char *mas1, *mas2, *mas3;
    Allocator a;
    // Тест 1
    cout<<"Проверка makeAllocator на size = 0"<<endl;
    a.makeAllocator(0);
    // Тест 2
    cout<<"Занесем нормальные данные:"<<endl;
    a.makeAllocator(sizeof(char)*8);
    mas1 = a.alloc(sizeof(char)*4);
    mas2 = a.alloc(sizeof(char)*4);
    *mas1 = '1';
    *mas2 = '2';
    cout<<mas1[0]<<' '<<mas2[0]<< endl;
    // Тест 3
    cout<<"Вызов makeAllocator и занесение данных без reset:"<<endl;
    a.makeAllocator(sizeof(char)*8);
    mas3 = a.alloc(sizeof(char)*4);
    *mas3= '5';
    cout<<*mas3<<endl;
    // Тест 4
    cout << "Изменим значение с 5 на 7" << endl;
    *mas3 = '7';
    cout << *mas3 << " \nПолучилось!!" << endl;
    cout<<"Вызываем reset"<<endl;
    a.reset();
    // Тест 5
    cout << "После reset добавим данные" <<endl;
    mas1 = a.alloc(sizeof(char)*4);
    mas2 = a.alloc(sizeof(char)*4);
    *mas2 = '6';
    *mas1 = '4';
    cout<<*mas1<<' '<<*mas2<<endl;
    // Тест 6
    cout<<"А теперь попросим больше, чем есть у объекта Allocator"<<endl;
    mas1 = a.alloc(sizeof(char)*1);
    if (!mas1)
    {
        cout<<"Alloc вернул nullptr"<<endl;
    }
    // Тест 7
    cout<<"Вызовем снова makeAllocator"<<endl;
    a.makeAllocator(sizeof(char)*4);
    mas1 = a.alloc(sizeof(char)*4);
    *mas1 = '9';
    cout<<mas1[0]<<endl;
    mas2 = a.alloc(sizeof(char)*1);
    if (!mas2)
    {
        cout<<"Alloc снова вернул nullptr"<<endl;
    }
    return 0;
}