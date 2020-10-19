#include <iostream>
#include "TokenParser.h"

using namespace std;

void OnDigit(int num)
{
    cout<<"Digit = "<<num<<endl;
}

void OnWord(string word)
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

int main()
{
    TokenParser parser = TokenParser(OnDigit, OnWord, OnStart, OnFinish); 
    const char* test1 = "Some string about 43 kfmk43gmlg \t fdbfgn    ";
    parser.ParseText(test1);
    return 0;
}
