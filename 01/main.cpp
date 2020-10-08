#include <cstdio>
#include <unistd.h>
#include <cstddef>
#include <iostream>
#include "Allocator.h"

using namespace std;

int main()
{
    int fl = 1;
	char *mas1, *mas2;
    Allocator a;
	a.makeAllocator(sizeof(char)*8);
	mas1 = a.alloc(sizeof(char)*4);
	mas2 = a.alloc(sizeof(char)*4);
	*mas1 = '1';
	*mas2 = '2';
	fl *= (mas1[0] == '1' && mas2[0] == '2');
	cout << "Изменим значение с 1 на 7" << endl;
	*mas1 = '7';
	cout << *mas1 << " \nПолучилось!!" << endl;
	a.reset();
	cout << "После reset:" <<endl;
	if (fl == 1)
		cout<<"OK"<<endl;
	if (fl == 0)
		cout<<"Error"<<endl;
	cout<<"А теперь попросим больше, чем есть у объекта Allocator"<<endl;
	a.makeAllocator(sizeof(char)*2);
	mas1 = a.alloc(sizeof(char)*3);
	return 0;
}