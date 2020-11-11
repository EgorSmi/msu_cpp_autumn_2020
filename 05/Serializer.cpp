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
    out_<<value<<Separator;
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
    try
    {
        value = stoul(text);
        return Error::NoError;
    }
    catch(const logic_error& e)
    {
        return Error::CorruptedArchive;
    }
}