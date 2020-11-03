#include "BigInt.h"
#include <iostream>

using namespace std;

void DefaultWorkTest()
{
    BigInt f = BigInt("456");
    BigInt n = BigInt();
    BigInt i = BigInt(-2);
    cout<<i<<endl;
    cout<<n<<endl;
    cout<<f<<endl;
}

int main()
{
    DefaultWorkTest();
    return 0;
}