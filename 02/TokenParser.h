#include <iostream>
#pragma once

using namespace std;

using NumHandler = void(*)(int);
using WordHandler = void(*)(const string&);
using BordHandler = void(*)();

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
        void ParseText(const char* text);
        void RegToken(const string& token);
};