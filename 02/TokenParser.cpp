#include <iostream>
#include "TokenParser.h"

using namespace std;

TokenParser::TokenParser()
{
    CallDigit = nullptr;
    CallWord = nullptr;
    CallStart = nullptr;
    CallFinish = nullptr;
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
