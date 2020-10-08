#include <cstdio>
#include <unistd.h>
#include <cstddef>
#include <iostream>
#include "Allocator.h"

using namespace std;

int main()
{
    int fl=1;
	char *mas1, *mas2;
    Allocator a;
	a.makeAllocator(sizeof(char)*8);
	mas1 = a.alloc(sizeof(char)*4);
	mas2 = a.alloc(sizeof(char)*4);
	*mas1 = '1';
	*mas2 = '2';
	fl *= (mas1[0] == '1' && mas2[0] == '2');
	a.reset();
	a.makeAllocator(sizeof(char)*2);
	mas1 = a.alloc(sizeof(char)*3);
	fl*=(!mas1);
	if (fl==1)
		cout<<"OK"<<endl;
	if (fl==0)
		cout<<"Error"<<endl;
	return 0;
}