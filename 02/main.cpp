#include <iostream>
#include "TokenParser.h"
#include "Myfunc.h"

using namespace std;

int main()
{
    TokenParser parser = TokenParser(OnDigit, OnWord, OnStart, OnFinish); 
    const char* test1 = "Some string about 43 kfmk43gmlg \t fdbfgn    ";
    parser.ParseText(test1);
    return 0;
}
