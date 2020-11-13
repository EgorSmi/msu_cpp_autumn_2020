#pragma once


using namespace std;

class ParseError
{
public:
    virtual string Message() const noexcept = 0;
};

class SyntaxError: public ParseError
{
public:
    string Message() const noexcept override;
};

class ArgumentError: public ParseError
{
public:
    string Message() const noexcept override;
};

class LimitError: public ParseError
{
public:
    string Message() const noexcept override;
};