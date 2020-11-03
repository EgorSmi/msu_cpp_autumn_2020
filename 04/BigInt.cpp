#include "BigInt.h"
#include <iostream>

using namespace std;

void BigInt::MakeBeauty()
{
    //удаляет некрасивые нули в начале числа
    int nulls = len - 1;
    while ((number[nulls] == '0') && (nulls > 0))
    {
        nulls--;
    }
    char* res_num = (char*)malloc(sizeof(char)*(nulls+2));
    res_num[nulls + 1] ='\0';
    len = nulls + 1;
    for (int i = nulls; i>=0; i--)
    {
        res_num[i] = number[i];
    }
    free(number);
    number = res_num;
}

BigInt::BigInt() : sign(false), len(1)
{
    number = (char*) malloc(sizeof(char) * 2);
    number[0] = '0';
    number[1] = '\0';
}

BigInt::BigInt(int num)
{
    if (num < 0)
    {
        sign = true;
        num *= -1;
    }
    else
    {
        sign = false;
    }
    number = (char*) malloc(sizeof(char));
    len = 0;
    while (num >= 10)
    {
        number[len] = num % 10 + '0';
        num /= 10;
        len++;
        number = (char*) realloc(number, sizeof(char) * (len + 1));
    }
    number[len] = num % 10 + '0';
    len++;
    number[len] = '\0';
}

BigInt::BigInt(const string& str)
{
    int i = 0;
    if (str[0] == '-')
    {
        len = str.length() - 1;
        i++;
        sign = true;
    }
    else
    {
        len = str.length();
        sign = false;
    }
    number = (char*) malloc(sizeof(char) * (len + 1));
    for (int i = 0; i<len; i++)
    {
        number[i] = str[str.length() - 1 - i];
    }
    number[len] = '\0';
    MakeBeauty();
}

ostream& operator <<(ostream& out, const BigInt& obj)
{
    // храним числа перевернутыми, выводить - нормальными
    if (obj.sign)
    {
        out<<'-';
    }
    for (int i = obj.len - 1; i >= 0; i--)
    {
        out << obj.number[i];
    }
    return out;
}

BigInt::BigInt(const BigInt& obj) : sign(obj.sign), len(obj.len)
{
    number = (char*) malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++)
    {
        number[i] = obj.number[i];
    }
}

BigInt::BigInt(BigInt&& obj) : number(obj.number), sign(obj.sign), len(obj.len)
{
    obj.number = nullptr;
    obj.sign = false;
    obj.len = 0;
}

BigInt& BigInt::operator=(const BigInt& obj)
{
    if (*this != obj)
    {
        if (number)
        {
            free(number);
        }
        sign = obj.sign;
        len = obj.len;
        number = (char*) malloc(sizeof(char) * (len + 1));
        for (size_t i = 0; i < len; i++)
        {
            number[i] = obj.number[i];
        }
    }
    return *this;
}

BigInt& BigInt::operator=(BigInt&& obj)
{
    if (*this != obj)
    {
        if (number)
        {
            free(number);
        }
        sign = obj.sign;
        len = obj.len;
        number = obj.number;
        obj.number = nullptr;
        obj.len = 0;
        obj.sign = false;
    }
    return *this;
}

bool BigInt::operator==(const BigInt& obj) const
{
    if (sign != obj.sign)
    {
        return false;
    }
    if (len != obj.len)
    {
        return false;
    }
    for (size_t i=0; i<len; i++)
    {
        if (number[i] != obj.number[i])
        {
            return false;
        }
    }
    return true;
}

bool BigInt::operator!=(const BigInt& obj) const
{
    return !(*this == obj);
}

bool BigInt::operator>(const BigInt& obj) const
{
    if ((sign == true) && (obj.sign == false))
    {
        return false;
    }
    if ((sign == false) && (obj.sign == true))
    {
        return true;
    }
    if ((sign == false) && (obj.sign == false))
    {
        if (len > obj.len)
        {
            return true;
        }
        if (obj.len > len)
        {
            return false;
        }
        int i = len - 1; 
        while (number[i] == obj.number[i])
        {
            i--;
        }
        return number[i] > obj.number[i];
    }
    if (len > obj.len)
    {
        return false;
    }
    if (obj.len > len)
    {
        return true;
    }
    int i = len - 1; 
    while (number[i] == obj.number[i])
    {
        i--;
    }
    return number[i] < obj.number[i];
}

bool BigInt::operator<(const BigInt& obj) const
{
    if ((sign == true) && (obj.sign == false))
    {
        return true;
    }
    if ((sign == false) && (obj.sign == true))
    {
        return false;
    }
    if ((sign == false) && (obj.sign == false))
    {
        if (len < obj.len)
        {
            return true;
        }
        if (obj.len < len)
        {
            return false;
        }
        int i = len - 1; 
        while (number[i] == obj.number[i])
        {
            i--;
        }
        return number[i] < obj.number[i];
    }
    if (len < obj.len)
    {
        return false;
    }
    if (obj.len < len)
    {
        return true;
    }
    int i = len - 1; 
    while (number[i] == obj.number[i])
    {
        i--;
    }
    return number[i] > obj.number[i];
}

bool BigInt::operator>=(const BigInt& obj) const
{
    return !(*this<obj);
}

bool BigInt::operator<=(const BigInt& obj) const
{
    return !(*this>obj);
}

BigInt& BigInt::operator-()
{
    if ((len == 0) && (number[0] == '0'))
    {
        return *this;
    }
    sign = !sign;
    return *this;
}

BigInt BigInt::operator+(const BigInt& obj) const
{
    if ((sign == false) && (obj.sign == true))
    {
        BigInt tmp = BigInt(obj);
        tmp.sign = false;
        return *this - tmp;
    }
    if ((sign == true) && (obj.sign == false))
    {
        BigInt tmp = BigInt(*this);
        tmp.sign = false;
        return obj - tmp;
    }
    BigInt res;
    if (sign == true)
    {
        res.sign = true;
    }
    else
    {
        res.sign = false;
    }
    char* max_num = nullptr;
    int max_len;
    int min_len;
    if (len > obj.len)
    {
        max_num = number;
        max_len = len;
        min_len = obj.len;
    }
    else
    {
        max_num = obj.number;
        max_len = obj.len;
        min_len = len;
    }
    res.number = (char*)malloc(sizeof(char) * (max_len + 2));
    int add = 0;
    int i = 0;
    while (i < min_len)
    {
        int tmp = number[i] + obj.number[i] - 2 * '0' + add;
        if (tmp >= 10)
        {
            add = 1;
        }
        else
        {
            add = 0;
        }
        res.number[i] = tmp % 10 + '0';
        i++;
    }
    while (i < max_len)
    {
        int tmp = max_num[i] + add - '0';
        if (tmp >= 10)
        {
            add = 1;
        }
        else
        {
            add = 0;
        }
        res.number[i] = tmp % 10 + '0';
        i++;
    }
    if (add == 1)
    {
        res.number[i] = add + '0';
        i++;
    }
    res.number[i] = '\0';
    res.len = i;
    return res;
}

BigInt BigInt::operator-(const BigInt& obj) const
{
    if ((sign == false) && (obj.sign == true))
    {
        BigInt tmp = BigInt(obj);
        tmp.sign = false;
        return *this + tmp;
    }
    if ((sign == true) && (obj.sign == false))
    {
        BigInt tmp = BigInt(obj);
        tmp.sign = true;
        return obj + tmp;
    }
    BigInt res;
    BigInt tmp1 = *this;
    BigInt tmp2 = obj;
    tmp1.sign = false;
    tmp2.sign = false; 
    char* min_num;
    char* max_num;
    int max_len;
    int min_len;
    if (*this >= obj)
    {
        res.sign = false;
    }
    else
    {
        res.sign = true;
    }
    if (tmp1 >= tmp2)
    {
        max_num = number;
        min_num = obj.number;
        max_len = len;
        min_len = obj.len;
    }
    else
    {
        max_num = obj.number;
        min_num = number;
        max_len = obj.len;
        min_len = len;
    }
    res.number = (char*) malloc(sizeof(char) * (max_len + 2));
    int i = 0;
    int deduct = 0;
    while (i < min_len)
    {
        if (max_num[i] - deduct >= min_num[i])
        {
            res.number[i] = max_num[i] - deduct - min_num[i] + '0';
            deduct = 0;
        }
        else
        {
            res.number[i] = max_num[i] + 10 - deduct - min_num[i] + '0';
            deduct = 1;
        }
        i++;
    }
    while (i < max_len)
    {
        if (max_num[i] - deduct >= '0')
        {
            res.number[i] = max_num[i] - deduct;
            deduct = 0;
        }
        else
        {
            res.number[i] = max_num[i] + 10 - deduct;
            deduct = 1;
        }
        i++;
    }
    res.number[i] = '\0';
    res.len = i;
    res.MakeBeauty();
    return res;
}

BigInt BigInt::operator*(const BigInt& obj) const
{
    BigInt res;
    int length = len + obj.len + 1;
    long long mas[length];
    for (int i=0; i <length; i++)
    {
        mas[i] = 0;
    }
    for (int i = 0; i < len; i++)
        for (int j = 0; j < obj.len; j++)
            mas[i + j] += (number[i] - '0') * (obj.number[j] - '0');
    res.number = (char*) malloc(sizeof(char) * (length + 1));
    for (int i = 0; i < length; i++)
    {
        mas[i + 1] += int(mas[i]) / 10;
        mas[i] = int(mas[i]) % 10;
    }
    for (int i = 0; i < length; i++)
    {
        res.number[i] = mas[i] + '0';
    }
    res.number[length] = '\0';
    if (sign == obj.sign)
    {
        res.sign = false;
    }
    else
    {
        res.sign = true;
    }
    res.len = length;
    res.MakeBeauty();
    return res;
}

BigInt::~BigInt()
{
    if (number)
    {
        free(number);
    }
}
