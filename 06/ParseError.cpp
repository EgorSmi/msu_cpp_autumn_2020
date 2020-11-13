#include <iostream>
#include "ParseError.hpp"


using namespace std;

void SyntaxError::Message() const noexcept
{
    cout<<"Syntax error!"<<endl;
}

void ArgumentError::Message() const noexcept
{
    cout<<"Argument must be positive number!"<<endl;
}

void LimitError::Message() const noexcept
{
    cout<<"No more arguments"<<endl;
}