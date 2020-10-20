#include <iostream>
#include "TokenParser.h"

using namespace std;

TokenParser::TokenParser(const NumHandler& CallDigit, const WordHandler& CallWord,
const BordHandler& CallStart, const BordHandler& CallFinish)
    : CallDigit(CallDigit),  CallWord(CallWord), CallStart(CallStart), CallFinish(CallFinish) { }

void TokenParser::SetStartCallback(const BordHandler& func)
{
    CallStart = func;
}

void TokenParser::SetDigitTokenCallback(const NumHandler& func)
{
    CallDigit = func;
}

void TokenParser::SetWordTokenCallback(const WordHandler& func)
{
    CallWord = func;
}

void TokenParser::SetFinishCallback(const BordHandler& func)
{
    CallFinish = func;
}

string TokenParser::RegToken(const string& token) // регистрирует токен
{
    if (token != "")
    {
        bool isNum = true;
        int i = 0;
        while ((i<token.length()) && (isNum))
        {
            isNum = isdigit(token[i]);
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
    }
    return "";
}

string TokenParser::ParseText(const string& text) // разделяет на токены по isspace()
{
    string res = "";
    string token = "";
    int i = 0;
    if (CallStart != nullptr)
    {
        res += CallStart();
    }
    else
    {
        res += "Default Callback function for start is missing\n";
    }
    while (i < text.length())
    {
        if (!isspace(text[i]))
        {
            token += text[i];
        }
        else
        {
            res += RegToken(token);
            token = "";
        }
        i++;
    }
    res += RegToken(token);
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
