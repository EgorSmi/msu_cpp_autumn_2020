#include <iostream>
#include "Myfunc.h"

using namespace std;

void OnDigit(int num)
{
    cout<<"Digit = "<<num<<endl;
}

void OnWord(const string &word)
{
    cout<<"Word = "<<word<<endl;
}

void OnStart()
{
    cout<<"Let's start the parsing"<<endl;
}

void OnFinish()
{
    cout<<"Parsing is over"<<endl;
}