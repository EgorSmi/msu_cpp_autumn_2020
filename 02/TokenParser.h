#pragma once

using namespace std;

using NumHandler = void(*)(int);
using WordHandler = void(*)(string);
using BordHandler = void(*)();

class TokenParser
{
    private:
        NumHandler CallDigit;
        WordHandler CallWord;
        BordHandler CallStart;
        BordHandler CallFinish;
    public:
        TokenParser();
        void SetStartCallback(BordHandler func);
        void SetDigitTokenCallback(NumHandler func);
        void SetWordTokenCallback(WordHandler func);
        void SetFinishCallback(BordHandler func);
};