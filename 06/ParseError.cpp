#include <iostream>
#include "ParseError.hpp"

using namespace std;

void SyntaxError::Message() noexcept
{
    cout<<"Syntax error!"<<endl;
}