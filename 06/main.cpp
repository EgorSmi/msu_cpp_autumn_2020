#include <iostream>
#include "Format.hpp"
#include "ParseError.hpp"


using namespace std;

int main()
{
    try
    {
        cout<<format("something {0} {1} ", "fdlmldg", 43)<<endl;
    }
    catch(const SyntaxError& er)
    {
        er.Message();
    }
    catch(const ArgumentError& er)
    {
        er.Message();
    }
    catch(const LimitError& er)
    {
        er.Message();
    }
    return 0;
}