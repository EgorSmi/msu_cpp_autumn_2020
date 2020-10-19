#include <iostream>
#include "TokenParser.h"

using namespace std;

TokenParser::TokenParser(NumHandler CallDigit, WordHandler CallWord, BordHandler CallStart, BordHandler CallFinish)
    : CallDigit(CallDigit),  CallWord(CallWord), CallStart(CallStart), CallFinish(CallFinish) { }

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

string TokenParser::ParseText(const char* text) // разделяет на токены по isspace()
{
    string res = "";
    string token = "";
    if (CallStart != nullptr)
    {
        res += CallStart();
    }
    else
    {
        res += "Default Callback function for start is missing\n";
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
                res += RegToken(token);
                token = "";
            }
        }
        text++;
    }
    if (token != "")
    {
        res += RegToken(token);
    }
    if (CallFinish != nullptr)
    {
        res += CallFinish();
    }
    else
    {
        res += "Default Callback function for finish is missing\n";
    }
    return res;
}

string TokenParser::RegToken(const string& token) // регистрирует токен
{
    bool isNum = true;
    int i = 0;
    while ((i<token.length()) && (isNum))
    {
        isNum = ((token[i]>='0' && token[i]<='9'));
        i++;
    }
    if ((isNum) && (CallDigit != nullptr))
    {
        return CallDigit(stoi(token));
    }
    if ((CallDigit == nullptr) && (isNum))
    {
        return "Default Callback function for digit is missing\n";
    }
    if ((!isNum) && (CallWord != nullptr))
    {
        return CallWord(token);
    }
    if ((!isNum) && (CallWord == nullptr))
    {
        return "Default Callback function for word is missing\n";
    }
    return "";
}
