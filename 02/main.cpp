#include <iostream>
#include "TokenParser.h"
#include "Myfunc.h"
#include "MyAdditionalfunc.h"

using namespace std;

void TestConstructor()
{
    TokenParser parser = TokenParser(OnDigit, OnWord, OnStart, OnFinish); 
    const char* test = "Some text about 39 symbols \t fdbfgn    ";
    parser.ParseText(test);
}

void NullMethodTest()
{
    TokenParser parser = TokenParser();
    const char* test = "Some text about 39 symbols \t fdbfgn    ";
    parser.ParseText(test);
}

void MethodTest()
{
    TokenParser parser = TokenParser();
    parser.SetDigitTokenCallback(OnDigit);
    parser.SetFinishCallback(OnFinish);
    parser.SetStartCallback(OnStart);
    parser.SetWordTokenCallback(OnWord);
    const char* test = "New text 423 40485 random numbers \n \r some random letters gnkngkrnkdfb";
    parser.ParseText(test);
}

void ChangeMethodTest()
{
    TokenParser parser = TokenParser(OnDigit, OnWord, OnStart, OnFinish); 
    const char* test = "New functions new fun random numbers 21 fkrk43 ";
    parser.SetDigitTokenCallback(AdditionalOnDigit);
    parser.SetFinishCallback(AdditionalOnFinish);
    parser.SetStartCallback(AdditionalOnStart);
    parser.SetWordTokenCallback(AdditionalOnWord);
    parser.ParseText(test);
}

void ChangeMethodOnNullTest()
{
    TokenParser parser = TokenParser(OnDigit, OnWord, OnStart, OnFinish); 
    const char* test = "The last test4324\n    ";
    parser.SetFinishCallback(nullptr);
    parser.ParseText(test);
}

int main()
{
    // Тест 1
    TestConstructor();
    // Тест 2
    NullMethodTest();
    // Тест 3
    MethodTest();
    // Тест 4
    ChangeMethodTest();
    // Тест 5
    ChangeMethodOnNullTest();
    return 0;
}