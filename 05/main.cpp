#include <iostream>
#include <sstream>
#include "Serializer.hpp"
using namespace std;

struct Data
{
    uint64_t a;
    bool b;
    uint64_t c;

    template <class T>
    Error serialize(T& serializer)
    {
        return serializer(a, b, c);
    }
};


void DefaultSerializeTest()
{
    Data x{ 1, true, 2 };
    stringstream s1;
    Serializer serializer = Serializer(s1);
    if (serializer.save(x) == Error::NoError)
    {
        cout<<"OK: Default serialize test"<<endl;
    }
    else
    {
        cout<<"ERROR! Default serialize test error"<<endl;
    }
    Data y{ 0, false, 0 };
    Deserializer d1 = Deserializer(s1);
    if (d1.load(y) == Error::NoError)
    {
        if ((y.a == 1) && (y.b == true) && (y.c == 2))
        {
            cout<<"OK: Deserialize test"<<endl;
        }
        else
        {
            cout<<"ERROR! Deserialize error"<<endl;
        }
    }
    else
    {
        cout<<"ERROR! What???? Deserialize error"<<endl;
    }
}

void LimitDeserializeTest()
{
    Data y{ 0, false, 0 };
    stringstream s1 = stringstream("");
    Deserializer d = Deserializer(s1);
    if (d.load(y) == Error::CorruptedArchive)
    {
        cout<<"OK: Limit deserialization test"<<endl;
    }
    else
    {
        cout<<"ERROR! Stream must me empty"<<endl;
    }
}

void WithoutSerializationTest()
{
    Data y{ 0, false, 0 };
    stringstream s = stringstream("5 true 10");
    Deserializer d = Deserializer(s);
    d.load(y);
    if ((y.a == 5) && (y.b == true) && (y.c == 10))
    {
        cout<<"OK: Without serialization test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect deserialization input stringstream"<<endl;
    }
}



int main()
{
    DefaultSerializeTest();
    LimitDeserializeTest();
    WithoutSerializationTest();
    return 0;
}