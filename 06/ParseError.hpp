#pragma once


class ParseError
{
public:
    virtual void Message() noexcept = 0;
};

class SyntaxError: public ParseError
{
public:
    void Message() noexcept override;
};

class ArgumentError: public ParseError
{
public:
    void Message() noexcept override;
};