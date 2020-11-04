#pragma once
#include <iostream>

using namespace std;

class BigInt
{
    private:
        char* number;
        bool sign;
        int len;
    public:
        BigInt();
        BigInt(int num);
        BigInt(const string& str);
        BigInt(const BigInt& obj);
        BigInt(BigInt&& obj);
        BigInt& operator=(const BigInt& obj);
        BigInt& operator=(BigInt&& obj);
        friend ostream& operator<<(ostream& out, const BigInt& obj);
        bool operator==(const BigInt& obj) const;
        bool operator!=(const BigInt& obj) const;
        bool operator>(const BigInt& obj) const;
        bool operator<(const BigInt& obj) const;
        bool operator>=(const BigInt& obj) const;
        bool operator<=(const BigInt& obj) const;
        BigInt operator-();
        BigInt operator+(const BigInt& obj) const;
        BigInt operator-(const BigInt& obj) const;
        BigInt operator*(const BigInt& obj) const;
        void MakeBeauty();
        ~BigInt();
};