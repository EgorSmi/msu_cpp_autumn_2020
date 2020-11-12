#include <iostream>
#include "Format.hpp"
#include "ParseError.hpp"
#include <typeinfo>


using namespace std;

string format(const string& s)
{
    return s;
}

string Parse(const string& s, const vector<string>& arguments)
{
    string res = "";
    bool flag = true;
    string number = "";
    for (size_t i = 0; i < s.length(); i++)
    {
    }
    if (flag != true)
    {
        throw SyntaxError();
    }
    return res;
}


/*
        if (flag == false)
        {
            if (s[i] != '}')
            {
                // идет считывание числа
                number += s[i];
            }
            else
            {
                int i_numb;
                try
                {
                    i_numb = stoull(number);
                    cout<<"Проверка: "<<i_numb<<endl;
                }
                catch(const logic_error& e)
                {
                    throw ArgumentError();
                }
                if (i_numb < arguments.size())
                {
                    res += arguments[i_numb];
                    flag = true;
                }
                else
                {
                    throw ArgumentError();
                }
            }
        }
        else
        {
            if (s[i] == '{')
            {
                if (flag == true)
                {
                    flag = false;
                }
                else
                {
                    throw SyntaxError();
                }
            }
            else if (s[i] == '}')
            {
                throw SyntaxError();
            }
            else
            {
                res += s[i];
            }
        }*/