#pragma once


class ParseError
{
public:
    virtual void Message() const noexcept = 0;
};

class SyntaxError: public ParseError
{
public:
    void Message() const noexcept override;
};

class ArgumentError: public ParseError
{
public:
    void Message() const noexcept override;
};

class LimitError: public ParseError
{
public:
    void Message() const noexcept override;
};