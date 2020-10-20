#include <iostream>
#include <functional>
#include "MyAdditionalfunc.h"

using namespace std;

string AdditionalOnDigit(int num)
{
    return "Additional digit = " + to_string(num) + "\n";
}

string AdditionalOnWord(const string &word)
{
    return "Additional word = " + word + "\n";
}

string AdditionalOnStart()
{
    return "Let's start the additional parsing\n";
}

string AdditionalOnFinish()
{
    return "Additional parsing is over\n";
}