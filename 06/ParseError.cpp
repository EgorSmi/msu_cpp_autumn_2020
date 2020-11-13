#include <iostream>
#include "ParseError.hpp"


using namespace std;

string SyntaxError::Message() const noexcept
{
    return "Syntax error!";
}

string ArgumentError::Message() const noexcept
{
    return "Argument must be positive number!";
}

string LimitError::Message() const noexcept
{
    return "No more arguments";
}