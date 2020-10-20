#include <iostream>
#include <functional>
#include "Myfunc.h"

using namespace std;

string OnDigit(int num)
{
    return "Digit = " + to_string(num) + "\n";
}

string OnWord(const string &word)
{
    return "Word = " + word + "\n";
}

string OnStart()
{
    return "Let's start the parsing\n";
}

string OnFinish()
{
    return "Parsing is over\n";
}