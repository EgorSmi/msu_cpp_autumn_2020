#include <iostream>
#pragma once

using namespace std;

using NumHandler = string(*)(int);
using WordHandler = string(*)(const string&);
using BordHandler = string(*)();

class TokenParser
{
    private:
        NumHandler CallDigit;
        WordHandler CallWord;
        BordHandler CallStart;
        BordHandler CallFinish;
    public:
        TokenParser(NumHandler CallDigit = nullptr, WordHandler CallWord = nullptr, BordHandler CallStart = nullptr, BordHandler CallFinish = nullptr);
        void SetStartCallback(BordHandler func);
        void SetDigitTokenCallback(NumHandler func);
        void SetWordTokenCallback(WordHandler func);
        void SetFinishCallback(BordHandler func);
        string ParseText(const char* text);
        string RegToken(const string& token);
};