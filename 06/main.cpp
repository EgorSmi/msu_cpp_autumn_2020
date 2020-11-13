#include <iostream>
#include "Format.hpp"
#include "ParseError.hpp"


using namespace std;

void DefaultWorkTest()
{
    string right_answer = "arguments: one, 2 and 3.14159";
    if (format("arguments: {0}, {1} and {2}", "one", 2, 3.14159) == right_answer)
    {
        cout<<"OK: Default work test"<<endl;
    }
    else
    {
        cout<<"Error! Incorrect function work"<<endl;
    }
}

void AdditionalArgumentsTest()
{
    string right_answer = "arguments: one + two = 5";
    if (format("arguments: {0} + {1} = {2}", "one", "two", 5, 6, 7, 8) == right_answer)
    {
        cout<<"OK: Additional arguments test"<<endl;
    }
    else
    {
        cout<<"Error! Incorrect function with additional arguments work"<<endl;
    }
}

void WithoutArgumentsTest()
{
    string simple_str = "Something";
    if (format("Something") == simple_str)
    {
        cout<<"OK: Without arguments test"<<endl;
    }
    else
    {
        cout<<"Error! Incorrect function without arguments work"<<endl;
    }
}

void SyntaxErrorTest()
{
    try
    {
        format("{0} something {", 3);
        cout<<"Error! It's syntax error"<<endl;
    }
    catch(const SyntaxError& er)
    {
        if (er.Message() == "Syntax error!")
        {
            cout<<"OK: Syntax error test"<<endl;
        }
        else
        {
            cout<<"Error! It's syntax error"<<endl;
        }
    }
    catch(...)
    {
        cout<<"Error! It's syntax error"<<endl;
    }
}

void ArgumentErrorTest()
{
    try
    {
        format("{0fdg} something {", 3);
        cout<<"Error! It's argument error"<<endl;
    }
    catch(const ArgumentError& er)
    {
        if (er.Message() == "Argument must be positive number!")
        {
            cout<<"OK: Argument error test"<<endl;
        }
        else 
        {
            cout<<"Error! It's argument error"<<endl;
        }
    }
    catch(...)
    {
        cout<<"Error! It's argument error"<<endl;
    }
}

void EndlessArgumentErrorTest()
{
    try
    {
        format("{0} something {01234567", 3, 5);
    }
    catch(const SyntaxError& e)
    {
        if (e.Message() == "Syntax error!")
        {
            cout<<"OK: Endless argument error test"<<endl;
        }
        else
        {
            cout<<"Error! It's syntax error"<<endl;
        }
    }
    catch(...)
    {
        cout<<"Error! It's syntax error"<<endl;
    }
}

void LimitErrorTest()
{
    try
    {
        format("{0}, {1} something {", 3);
        cout<<"Error! It's limit of argument error"<<endl;
    }
    catch(const LimitError& er)
    {
        if (er.Message() == "No more arguments")
        {
            cout<<"OK: Limit of argument error test"<<endl;
        }
        else 
        {
            cout<<"Error! It's limit of argument error"<<endl;
        }
    }
    catch(...)
    {
        cout<<"Error! It's limit of argument error"<<endl;
    }
}

void EmptyArgumentTest()
{
    try
    {
        format("{0}, {} something {", 3, 5);
        cout<<"Error! It's empty argument"<<endl;
    }
    catch(const ArgumentError& er)
    {
        if (er.Message() == "Argument must be positive number!")
        {
            cout<<"OK: Empty argument error test"<<endl;
        }
        else 
        {
            cout<<"Error! It's empty argument"<<endl;
        }
    }
    catch(...)
    {
        cout<<"Error! It's empty argument"<<endl;
    }
}

int main()
{
    DefaultWorkTest();
    AdditionalArgumentsTest();
    WithoutArgumentsTest();
    SyntaxErrorTest();
    ArgumentErrorTest();
    LimitErrorTest();
    EmptyArgumentTest();
    EndlessArgumentErrorTest();
    return 0;
}