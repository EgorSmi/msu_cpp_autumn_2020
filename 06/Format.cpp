#include <iostream>
#include "Format.hpp"
#include "ParseError.hpp"


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
        if (flag == false)
        {
            if (s[i] == '}')
            {
                flag = true;
                if (number != "")
                {
                    int i_numb = stoull(number);
                    if (i_numb < arguments.size())
                    {
                        res += arguments[i_numb];
                        number = "";
                    }
                    else
                    {
                        throw LimitError();
                    }
                }
                else
                {
                    throw ArgumentError();
                }
            }
            else if (isdigit(s[i]))
            {
                number += s[i];
            }
            else
            {
                throw ArgumentError();
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
        }    
    }
    if (flag != true)
    {
        throw SyntaxError();
    }
    return res;
}