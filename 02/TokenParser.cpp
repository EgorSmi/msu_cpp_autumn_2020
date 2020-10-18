#include <iostream>
#include "TokenParser.h"

using namespace std;

TokenParser::TokenParser(NumHandler CallDigit, WordHandler CallWord, BordHandler CallStart, BordHandler CallFinish)
{
    this->CallDigit = CallDigit;
    this->CallFinish = CallFinish;
    this->CallStart = CallStart;
    this->CallWord = CallWord;
}

void TokenParser::SetStartCallback(BordHandler func)
{
    CallStart = func;
}

void TokenParser::SetDigitTokenCallback(NumHandler func)
{
    CallDigit = func;
}

void TokenParser::SetWordTokenCallback(WordHandler func)
{
    CallWord = func;
}

void TokenParser::SetFinishCallback(BordHandler func)
{
    CallFinish = func;
}

void TokenParser::ParseText(const char* text) //разделяет на токены по isspace()
{
    string token = "";
    if (CallStart != nullptr)
    {
        CallStart();
    }
    else
    {
        cout<<"Default Callback function for start is missing"<<endl;
    }
    while (*text != '\0')
    {
        if (!isspace(*text))
        {
            token += *text;
        }
        else
        {
            if (token != "")
            {
                cout<<token<<endl; //проверка для себя
                RegToken(token);
                token = "";
            }
        }
        text++;
    }
    if (token != "")
    {
        cout<<token<<endl; //проверка для себя
        RegToken(token);
    }
    if (CallFinish != nullptr)
    {
        CallFinish();
    }
    else
    {
        cout<<"Default Callback function for finish is missing"<<endl;
    }
}

void TokenParser::RegToken(string token) //регистрирует токен
{

}
