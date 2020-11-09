#include <iostream>
#include <typeinfo>
#include "Serializer.hpp"

using namespace std;

char Serializer::Separator = ' ';
char Deserializer::Separator = ' ';

template <class T>
Error Serializer::process(T value)
{
    if (strcmp(typeid(value).name(),"bool") == 0)
    {
        std::string text;
        if (value == true)
            out_<<"true"<<Separator;
        else if (value == false)
            out_<<"false"<<Separator];

        return Error::NoError;
    }
    else if (strcmp(typeid(value).name(),"int") == 0)
    {
        if (value == 0)
        {
            out_<<"0"<<Separator;
        }
        else
        {
            string text = "";
            bool neg = false;
            if (value < 0)
            {
                neg = true;
                value *= (-1);
            }
            while (value > 0)
            {
                text = string(value % 10 + '0') + text;
                value /= 10;
            }
            if (neg == true)
            {
                out_<<"-"<<text<<Separator;
            }
            else
            {
                out_<<text<<Separator;
            }
        }
        return Error::NoError;
    }
    return Error::CorruptedArchive;
}

template <class T>
Error Deserializer::process(T value)
{
    std::string text;
    in_ >> text;
}