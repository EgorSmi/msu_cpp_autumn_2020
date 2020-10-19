#include <iostream>
#include "TokenParser.h"
#include "Myfunc.h"
#include "MyAdditionalfunc.h"

using namespace std;

void ConstructorTest()
{
    TokenParser parser = TokenParser(OnDigit, OnWord, OnStart, OnFinish); 
    const char* test = "Some text about 39 symbols \t fdbfgn    ";
    if (parser.ParseText(test) == "Let's start the parsing\nWord = Some\nWord = text\nWord = about\nDigit = 39\nWord = symbols\nWord = fdbfgn\nParsing is over\n")
    {
        cout<<"OK: Test with constructor"<<endl;
    }
    else
    {
        cout<<"ERROR! Test with constructor is incorrect"<<endl;
    }
}

void NullMethodTest()
{
    TokenParser parser = TokenParser();
    const char* test = "Some text about 39 symbols \t fdbfgn    ";
    if (parser.ParseText(test) == "Default Callback function for start is missing\nDefault Callback function for word is missing\nDefault Callback function for word is missing\nDefault Callback function for word is missing\nDefault Callback function for digit is missing\nDefault Callback function for word is missing\nDefault Callback function for word is missing\nDefault Callback function for finish is missing\n")
    {
        cout<<"OK: Null method test"<<endl;
    }
    else
    {
        cout<<"ERROR! Null method test"<<endl;
    }
}

void MethodTest()
{
    TokenParser parser = TokenParser();
    parser.SetDigitTokenCallback(OnDigit);
    parser.SetFinishCallback(OnFinish);
    parser.SetStartCallback(OnStart);
    parser.SetWordTokenCallback(OnWord);
    const char* test = "New text 423 40485 random numbers \n \r some random letters gnkngkrnkdfb";
    if (parser.ParseText(test) == "Let's start the parsing\nWord = New\nWord = text\nDigit = 423\nDigit = 40485\nWord = random\nWord = numbers\nWord = some\nWord = random\nWord = letters\nWord = gnkngkrnkdfb\nParsing is over\n")
    {
        cout<<"OK: Method test"<<endl;
    }
    else
    {
        cout<<"ERROR! Methods work incorrectly"<<endl;
    }
}

void ChangeMethodTest()
{
    TokenParser parser = TokenParser(OnDigit, OnWord, OnStart, OnFinish); 
    const char* test = "New functions new fun random numbers 21 fkrk43 ";
    parser.SetDigitTokenCallback(AdditionalOnDigit);
    parser.SetFinishCallback(AdditionalOnFinish);
    parser.SetStartCallback(AdditionalOnStart);
    parser.SetWordTokenCallback(AdditionalOnWord);
    if (parser.ParseText(test) == "Let's start the additional parsing\nAdditional word = New\nAdditional word = functions\nAdditional word = new\nAdditional word = fun\nAdditional word = random\nAdditional word = numbers\nAdditional digit = 21\nAdditional word = fkrk43\nAdditional parsing is over\n")
    {
        cout<<"OK: Change method test"<<endl;
    }
    else
    {
        cout<<"ERROR! Unable to change methods"<<endl;
    }
}

void ChangeMethodOnNullTest()
{
    TokenParser parser = TokenParser(OnDigit, OnWord, OnStart, OnFinish); 
    const char* test = "The last test4324\n    ";
    parser.SetFinishCallback(nullptr);
    if (parser.ParseText(test) == "Let's start the parsing\nWord = The\nWord = last\nWord = test4324\nDefault Callback function for finish is missing\n")
    {
        cout<<"OK: Change method on null test"<<endl;
    }
    else
    {
        cout<<"ERROR! Change method on null test"<<endl;
    }
}

int main()
{
    // Тест 1
    ConstructorTest();
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