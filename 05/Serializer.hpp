#pragma once

using namespace std;

enum class Error
{
    NoError,
    CorruptedArchive
};

class Serializer
{
    static char Separator;
    private:
        ostream& out_;
    public:
        explicit Serializer(ostream& out)
            : out_(out)
        {
        }

        template <class T>
        Error save(T& object)
        {
            return object.serialize(*this);
        }

        template <class... ArgsT>
        Error operator()(ArgsT... args)
        {
            return process(args...);
        }

        template <class T, class... ArgsT>
        Error process(T value, ArgsT... args)
        {
            process(value);
            process(args...);
        }

        template <class T>
        Error process(T value);
};

class Deserializer
{
    static char Separator;
    private:
        istream& in_;
    public:
        explicit Deserializer(istream& in)
            : in_(in)
        {
        }

        template <class T>
        Error load(T& object)
        {
            return object.deserialize(*this);
        }

        template <class... ArgsT>
        Error operator()(ArgsT... args)
        {
            return process(args...);
        }

        template <class T, class... ArgsT>
        Error process(T value, ArgsT... args)
        {
            process(value);
            process(args...);
        }

        template <class T>
        Error process(T value);
};