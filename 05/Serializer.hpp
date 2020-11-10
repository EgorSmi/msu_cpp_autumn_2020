#pragma once

using namespace std;

enum class Error
{
    NoError,
    CorruptedArchive
};

class Serializer
{
    static constexpr char Separator = ' ';
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
            if (process(value) == Error::CorruptedArchive)
            {
                return Error::CorruptedArchive;
            }
            return process(args...);
        }

        template <class T>
        Error process(T value)
        {
            return MySave(value);
        }

        Error MySave(bool flag);
        Error MySave(uint64_t value);
};

class Deserializer
{
    static constexpr char Separator = ' ';
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
        Error operator()(ArgsT&&... args)
        {
            return process(args...);
        }

        template <class T, class... ArgsT>
        Error process(T&& value, ArgsT&&... args)
        {
            if (process(value) == Error::CorruptedArchive)
            {
                return Error::CorruptedArchive;
            }
            return process(args...);
        }

        template <class T>
        Error process(T&& value)
        {
            return MyLoad(value);
        }

        Error MyLoad(bool& flag);
        Error MyLoad(uint64_t& value);
};