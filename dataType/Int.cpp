#ifndef HEADER_DATATYPE
#define HEADER_DATATYPE
#include "dataType.hpp"
#endif

#ifndef HEADER_CMATH
#define HEADER_CMATH
#include <cmath>
#endif

#ifndef HEADER_STRING
#define HEADER_STRING
#include <string>
#endif

#ifndef HEADER_IOSTREAM
#define HEADER_IOSTREAM
#include <iostream>
#endif

dataType::Int::Int()
{
    this->data = 0;
}

dataType::Int::Int(int in)
{
    this->data = in;
}

// 返回当前Int整除t的结果
int dataType::Int::get_k(const Int &t) const
{
    if (t.data == 0)
        throw "In get_k t.data == 0";
    int tmp;
    tmp = this->data % t.data;
    return (this->data - tmp) / t.data;
}

std::string dataType::Int::toString() const
{
    return std::to_string(this->data);
}

dataType::Int dataType::Int::get_abs() const
{
    return dataType::Int(std::abs(this->data));
}

dataType::Int dataType::Int::operator+(const dataType::Int &t) const
{
    dataType::Int res;
    res.data = this->data + t.data;
    return res;
}

dataType::Int dataType::Int::operator-(const dataType::Int &t) const
{
    dataType::Int res;
    res.data = this->data - t.data;
    return res;
}

dataType::Int dataType::Int::operator*(const dataType::Int &t) const
{
    dataType::Int res;
    res.data = this->data * t.data;
    return res;
}

dataType::Int dataType::Int::operator*(const int t) const
{
    dataType::Int res;
    res.data = this->data * t;
    return res;
}

dataType::Int dataType::Int::operator/(const dataType::Int &t) const
{
    if (t.data == 0)
        throw "In /(Int) t.data == 0";
    dataType::Int res;
    if (this->data % t.data == 0)
    {
        res.data = this->data / t.data;
        return res;
    }
    else
    {
        throw "this->data % t.data != 0";
    }
}

dataType::Int dataType::Int::operator/(const int t) const
{
    if (t == 0)
        throw "In / t == 0";
    dataType::Int res;
    if (this->data % t == 0)
    {
        res.data = this->data / t;
        return res;
    }
    else
    {
        throw "this->data % t != 0";
    }
}

dataType::Int dataType::Int::operator%(const dataType::Int &t) const
{
    if (t.data == 0)
        throw "In % t.data == 0";
    dataType::Int res;
    res.data = this->data % t.data;
    return res;
}

void dataType::Int::operator=(const dataType::Int &t)
{
    this->data = t.data;
}

bool dataType::Int::operator==(const dataType::Int &t) const
{
    return this->data == t.data;
}

bool dataType::Int::operator==(const int t) const
{
    return this->data == t;
}

dataType::Int dataType::Int::operator-() const
{
    dataType::Int res;
    res.data = -this->data;
    return res;
}

bool dataType::Int::operator>(const int t) const
{
    return this->data > t;
}

bool dataType::Int::operator>(const Int &t) const
{
    return this->data > t.data;
}

std::istream &operator>>(std::istream &in, dataType::Int &t)
{
    in >> t.data;
    return in;
}

std::ostream &operator<<(std::ostream &out, dataType::Int t)
{
    out << t.data;
    return out;
}