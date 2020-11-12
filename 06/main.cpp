#include <iostream>
#include "Format.hpp"
#include "ParseError.hpp"

using namespace std;

int main()
{
    int a = 9;
    format("something", a);
    return 0;
}