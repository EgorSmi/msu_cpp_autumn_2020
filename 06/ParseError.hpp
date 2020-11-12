#pragma once


class ParseError
{
public:
    virtual void Message() = 0;
};

class SyntaxError: public ParseError
{
public:
    void Message() noexcept override;
};