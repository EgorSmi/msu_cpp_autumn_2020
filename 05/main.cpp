#include <iostream>
#include <sstream>
#include "Serializer.hpp"
using namespace std;

#define checkEqual(x, y)                                                                           \
    do                                                                                             \
    {                                                                                              \
        if ((x) != (y))                                                                            \
        {                                                                                          \
            std::cout << "at line " << __LINE__ << ": " << (x) << " != " << (y) << '\n';           \
        };                                                                                         \
    } while (0)
#define checkTrue(cond)                                                                            \
    do                                                                                             \
    {                                                                                              \
        if (!(cond))                                                                               \
            std::cout << "at line " << __LINE__ << ": " << #cond << '\n';                          \
    } while (0)

struct Data
{
    uint64_t a;
    bool b;
    uint64_t c;

    template <class Serializer>
    Error serialize(Serializer& serializer)
    {
        return serializer(a, b, c);
    }

    template <class Deserializer>
    Error deserialize(Deserializer& deserializer)
    {
        return deserializer(a, b, c);
    }
};


void DefaultSerializeTest()
{
    Data x{ 1, true, 2 };

    stringstream s1;
    Serializer serializer(s1);
    if (serializer.save(x) == Error::NoError)
    {
        cout<<"OK: Default serialize test"<<endl;
    }
    else
    {
        cout<<"ERROR! Default serialize test error"<<endl;
    }
    Data y{ 0, false, 0 };
    Deserializer d1(s1);
    if (d1.load(y) == Error::NoError)
    {
        cout<<y.a<<endl;
        cout<<y.b<<endl;
        cout<<y.c<<endl;
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


int main()
{
    DefaultSerializeTest();
    return 0;
}