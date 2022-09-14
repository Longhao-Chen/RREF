#ifndef HEADER_IOSTREAM
#define HEADER_IOSTREAM
#include <iostream>
#endif

#ifndef HEADER_STRING
#define HEADER_STRING
#include <string>
#endif

namespace dataType
{
    class Int
    {
    public:
        int data;

        Int();

        Int(int);

        int get_k(const Int &t) const;

        std::string toString() const;

        Int get_abs() const;

        Int operator+(const Int &t) const;

        Int operator-(const Int &t) const;

        Int operator*(const Int &t) const;
        Int operator*(const int t) const;

        Int operator/(const Int &t) const;
        Int operator/(const int t) const;

        Int operator%(const Int &t) const;

        Int operator-() const;

        void operator=(const Int &t);

        bool operator==(const Int &t) const;
        bool operator==(const int t) const;
        bool operator>(const int t) const;
        bool operator>(const Int &t) const;
    };
}

std::istream &operator>>(std::istream &in, dataType::Int &t);
std::ostream &operator<<(std::ostream &out, const dataType::Int t);