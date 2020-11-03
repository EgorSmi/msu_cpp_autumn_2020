#include "BigInt.h"
#include <iostream>

using namespace std;

void DefaultTest()
{
    BigInt f = BigInt("00456");
    BigInt null = BigInt();
    BigInt i = BigInt(-2);
    BigInt n1 = BigInt("2435943435343384454332");
    BigInt n2 = BigInt(2147483647);
    BigInt n3 = BigInt(-2147483647);
    BigInt n4 = BigInt("-43534819032537124");
    BigInt m = BigInt(9);
    BigInt m1 = move(m);
    if ((i == BigInt("-2")) && (null == BigInt(0)) && (f == 456) &&(n1 == BigInt("2435943435343384454332")) &&
    (n2 == 2147483647) && (n3 == -2147483647) && (n4 == BigInt("-43534819032537124")) && (m1 == 9))
    {
        cout<<"OK: Default test"<<endl;
    }
    else
    {
        cout<<"ERROR! Defult test"<<endl;
    }
}

void EqualityTest()
{
    BigInt n1 = BigInt(33412);
    BigInt n2 = BigInt("33412");
    BigInt n3 = BigInt("00033412");
    BigInt r1 = BigInt(-2324);
    BigInt r2 = BigInt("-2324");
    BigInt r3 = BigInt("-00002324");
    if ((n1 == n2) && (n2 == n3) && (r1 == r2) && (r2 == r3))
    {
        cout<<"OK: Equality test"<<endl;
    }
    else
    {
        cout<<"ERROR! Objects should be equal"<<endl;
    }
}

void InequalityTest()
{
    BigInt n1 = BigInt(33412);
    BigInt n2 = BigInt("-33412");
    BigInt n3 = BigInt("33413");
    BigInt n4 = BigInt(3341);
    if ((n1 != n2) && (n1 != n3) && (n1 != n4))
    {
        cout<<"OK: Inequality test"<<endl;
    }
    else
    {
        cout<<"ERROR! Object should be inequal"<<endl;
    }
}

void ComparisonTest()
{
    BigInt n1 = BigInt(33412);
    BigInt n2 = BigInt("-33412");
    BigInt n3 = BigInt(3341);
    if ((n1 > n2) && (n1 >= n2) && (n1 > n3) && (n2 < n3) && (n3 < n1))
    {
        cout<<"OK: Comparison test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect comparison"<<endl;
    }
}

void MinusTest()
{
    BigInt n1 = BigInt(2455);
    BigInt n2 = BigInt("-9597594023523543");
    if ((-n1 == -2455) && (-n2 == BigInt("9597594023523543")))
    {
        cout<<"OK: Unary minus test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect unary minus"<<endl;
    }
}

void SummaryTest()
{
    BigInt n1 = BigInt(2455);
    BigInt n2 = BigInt("-9597594023523543");
    BigInt n3 = BigInt("-325215");
    BigInt n4 = BigInt(596740000);
    BigInt n5 = BigInt("533554653256533564526463");
    if ((n1 + n2 == BigInt("-9597594023521088")) && (n2 + n3 == BigInt("-9597594023848758")) && 
    (n1 + n4 == 596742455) && (n2 + n5 == BigInt("533554643658939541002920")))
    {
        cout<<"OK: Summary test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect summary"<<endl;
    }
}

void SubtractionTest()
{
    BigInt n1 = BigInt(2455);
    BigInt n2 = BigInt("-9597594023523543");
    BigInt n3 = BigInt("-325215");
    BigInt n4 = BigInt(596740000);
    BigInt n5 = BigInt("533554653256533564526463");
    if ((n1 - n2 == BigInt("9597594023525998")) && (n2 - n3 == BigInt("-9597594023198328")) &&
    (n3 - n2 == BigInt("9597594023198328")) && (n5 - n4 == BigInt("533554653256532967786463")) &&
    (n4 - n5 == BigInt("-533554653256532967786463")))
    {
        cout<<"OK: Subtraction test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect subtraction"<<endl;
    }
}

void MultiplyTest()
{
    BigInt n1 = BigInt(2455);
    BigInt n2 = BigInt("-9");
    BigInt n3 = BigInt("-325215");
    BigInt n4 = BigInt(-90);
    BigInt n5 = BigInt("53355465325");
    if ((n1 * n2 == BigInt("-22095")) && (n3 * n4 == BigInt("29269350"))
    && (n5 * n1 == BigInt("130987667372875")))
    {
        cout<<"OK: Multiply test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect multiplication"<<endl;
    }
}

void ControlTest()
{
    BigInt a = 1;
    BigInt b("123456789012345678901234567890");
    BigInt c = b * a + 2;
    BigInt d;
    d = move(c);
    a = d + b;
    if (a == BigInt("246913578024691357802469135782"))
    {
        cout<<"OK: Control test"<<endl;
    }
    else
    {
        cout<<"ERROR! Incorrect answer"<<endl;
    }
}

int main()
{
    DefaultTest();
    EqualityTest();
    InequalityTest();
    ComparisonTest();
    MinusTest();
    SummaryTest();
    SubtractionTest();
    MultiplyTest();
    ControlTest();
    return 0;
}