#ifndef HEADER_TYPE_TRAITS
#define HEADER_TYPE_TRAITS
#include <type_traits>
#endif
#ifndef HEADER_STRING
#define HEADER_STRING
#include <string>
#endif

namespace latexOutput
{
    class swap
    {
    public:
        int r1;
        int r2;
        swap(int r1, int r2);
    };

    class rowSum
    {
    public:
        rowSum(std::string k, bool upZero, int r1, int r2);
        std::string k;
        bool upZero;
        int r1;
        int r2;
    };

    class rowMul
    {
    public:
        rowMul(std::string k, int r);
        std::string k;
        int r;
    };

    class rowDiv
    {
    public:
        rowDiv(std::string k, int r);
        std::string k;
        int r;
    };

    template <typename T>
    concept VALID = (std::is_same_v<T, const swap> ||
                     std::is_same_v<T, const rowSum> ||
                     std::is_same_v<T, const rowMul> ||
                     std::is_same_v<T, const rowDiv>);

};
#ifndef HEADER_IOSTREAM
#define HEADER_IOSTREAM
#include <iostream>
#endif

#ifndef HEADER_LOG
#define HEADER_LOG
#include "log.hpp"
#endif
// 使用标准输出
template <latexOutput::VALID T>
std::ostream &operator<<(std::ostream &, T &);

template <latexOutput::VALID T>
std::ostream &operator<<(std::ostream &out, T &t)
{
    latexOutput::log msg;
    out << msg << t;
    return out;
}

#ifndef HEADER_LOG
#define HEADER_LOG
#include "log.hpp"
#endif
latexOutput::log &operator<<(latexOutput::log &, const latexOutput::swap &);
latexOutput::log &operator<<(latexOutput::log &, const latexOutput::rowSum &);
latexOutput::log &operator<<(latexOutput::log &, const latexOutput::rowMul &);
latexOutput::log &operator<<(latexOutput::log &, const latexOutput::rowDiv &);