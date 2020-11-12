#pragma once
#include <iostream>
#include <vector>
#include "ParseError.hpp"

using namespace std;

string format(const string& s);
string Parse(const string& s, const vector<string>& v);

template <class T, class... Args>
string Parse(const string& s, vector<string>& v, T&& val, Args&&... args)
{
    v.push_back(to_string(forward<T>(val)));
    return Parse(s, v, forward<Args>(args)...);
}

template <class T, class... Args>
string format(const string& s, T&& val, Args&&... args)
{
    vector<string> vect;
    return Parse(s, vect, forward<T>(val), forward<Args>(args)...);
}

// написать свои исключениЯ, наследовать от std::exception; можно сделать свой абстрактный класс исключений и 
// минимум два наследуемых
// фигня с 001
// распарсить аргументы, распарсить строку, если строка не парсится -- кидаем исключение