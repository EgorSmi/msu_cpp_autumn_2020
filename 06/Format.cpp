#include <iostream>
#include "Format.hpp"
#include "ParseError.hpp"

using namespace std;

string format(const string& s)
{
    return s;
}

string Parse(const string& s, const vector<string>& v)
{
    cout<<s;
    for (size_t i = 0; i < v.size(); i++)
    {
        cout<<" "<<v[i];
    }
    cout<<endl;
    return s;
}
