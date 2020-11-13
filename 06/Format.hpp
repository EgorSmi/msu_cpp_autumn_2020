#pragma once
#include <iostream>
#include <vector>
#include "ParseError.hpp"
#include <sstream>


using namespace std;

string format(const string& s);
string Parse(const string& s, const vector<string>& arguments);

template <class T>
string convert(const T& val)
{
    ostringstream ss;
    ss << val;
    return ss.str();
}

template <class T, class... Args>
string Parse(const string& s, vector<string>& arguments, T&& val, Args&&... args)
{
    arguments.push_back(convert(forward<T>(val)));
    return Parse(s, arguments, forward<Args>(args)...);
}

template <class T, class... Args>
string format(const string& s, T&& val, Args&&... args)
{
    vector<string> arguments;
    return Parse(s, arguments, forward<T>(val), forward<Args>(args)...);
}