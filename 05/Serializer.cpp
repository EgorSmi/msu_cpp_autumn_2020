#include <iostream>
#include "Serializer.hpp"

using namespace std;

Error Serializer::MySave(bool flag)
{
    if (flag == true)
    {
        out_<<"true"<<Separator;
    }
    else if (flag == false)
    {
        out_<<"false"<<Separator;
    }
    return Error::NoError;
}


Error Serializer::MySave(uint64_t value)
{
    if (value == 0)
    {
        out_<<"0"<<Separator;
    }
    else
    {
        string text = "";
        while (value > 0)
        {
            text = char(value % 10 + '0') + text;
            value /= 10;
        }
        out_<<text<<Separator;
    }
    return Error::NoError;
}

Error Deserializer::MyLoad(bool& value)
{
    string text;
    in_ >> text;
    if (text == "true")
        value = true;
    else if (text == "false")
        value = false;
    else
        return Error::CorruptedArchive;
    return Error::NoError;
}

Error Deserializer::MyLoad(uint64_t& value)
{
    string text;
    in_ >> text;
    if (text.length() != 0)
    {
        value = 0;
        for (size_t i=0; i<text.length(); i++)
        {
            if (isdigit(text[i]))
            {
                value = 10 * value + (text[i] - '0');
            }
            else
            {
                return Error::CorruptedArchive;
            }
        }
    }
    return Error::NoError;
}