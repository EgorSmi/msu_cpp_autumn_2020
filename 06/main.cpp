#include <iostream>
#include "Format.hpp"
#include "ParseError.hpp"

using namespace std;

int main()
{
    try
    {
        cout<<format("something {0} {1}", 678)<<endl;
    }
    catch(const ParseError& er)
    {
        cout<<"Error"<<endl;
    }
    return 0;
}