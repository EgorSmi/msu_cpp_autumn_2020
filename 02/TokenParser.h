#include <iostream>
#include <functional>
#pragma once

using namespace std;

using NumHandler = function<string (int)>;
using WordHandler = function<string (const string&)>;
using BordHandler = function<string ()>;

class TokenParser
{
    private:
        NumHandler CallDigit;
        WordHandler CallWord;
        BordHandler CallStart;
        BordHandler CallFinish;
    public:
        TokenParser(const NumHandler& CallDigit = nullptr, const WordHandler& CallWord = nullptr,
            const BordHandler& CallStart = nullptr, const BordHandler& CallFinish = nullptr);
        void SetStartCallback(const BordHandler& func);
        void SetDigitTokenCallback(const NumHandler& func);
        void SetWordTokenCallback(const WordHandler& func);
        void SetFinishCallback(const BordHandler& func);
        string ParseText(const string& text);
        string RegToken(const string& token);
};