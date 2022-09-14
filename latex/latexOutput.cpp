#ifndef HEADER_LATEXOUTPUT
#define HEADER_LATEXOUTPUT
#include "latexOutput.hpp"
#endif
#ifndef HEADER_IOSTREAM
#define HEADER_IOSTREAM
#include <iostream>
#endif
#ifndef HEADER_LOG
#define HEADER_LOG
#include "log.hpp"
#endif
#ifndef HEADER_STRING
#define HEADER_STRING
#include <string>
#endif

// 对换
latexOutput::swap::swap(int r1, int r2)
{
    this->r1 = r1 + 1;
    this->r2 = r2 + 1;
}
latexOutput::log &operator<<(latexOutput::log &out, const latexOutput::swap &t)
{
    std::string msg = "\\underset{\\longrightarrow}{ " + std::to_string(t.r1) + "\\leftrightarrow " + std::to_string(t.r2) + "}";
    out.push(msg);
    return out;
}

// 倍加
latexOutput::rowSum::rowSum(std::string k, bool upZero, int r1, int r2)
{
    this->k = k;
    this->upZero = upZero;
    this->r1 = r1 + 1;
    this->r2 = r2 + 1;
}
latexOutput::log &operator<<(latexOutput::log &out, const latexOutput::rowSum &t)
{
    std::string msg;
    if (t.upZero)
        if (t.k == "1")
            msg = "\\underset{\\longrightarrow}{ r_{" + std::to_string(t.r1) + "}+ r_{" + std::to_string(t.r2) + "}}";
        else
            msg = "\\underset{\\longrightarrow}{ r_{" + std::to_string(t.r1) + "}+ " + t.k + " r_{" + std::to_string(t.r2) + "}}";
    else if (t.k == "-1")
        msg = "\\underset{\\longrightarrow}{ r_{" + std::to_string(t.r1) + "} - r_{" + std::to_string(t.r2) + "}}";
    else
        msg = "\\underset{\\longrightarrow}{ r_{" + std::to_string(t.r1) + "} " + t.k + " r_{" + std::to_string(t.r2) + "}}";

    out.push(msg);
    return out;
}

//  倍乘
latexOutput::rowMul::rowMul(std::string k, int r)
{
    this->k = k;
    this->r = r + 1;
}
latexOutput::log &operator<<(latexOutput::log &out, const latexOutput::rowMul &t)
{
    std::string msg;
    if (t.k == "-1")
        msg = "\\underset{\\longrightarrow}{ - r_{" + std::to_string(t.r) + "}}";
    else
        msg = "\\underset{\\longrightarrow}{ " + t.k + " r_{" + std::to_string(t.r) + "}}";

    out.push(msg);
    return out;
}

// 倍除
latexOutput::rowDiv::rowDiv(std::string k, int r)
{
    this->k = k;
    this->r = r + 1;
}
latexOutput::log &operator<<(latexOutput::log &out, const latexOutput::rowDiv &t)
{
    std::string msg;
    if (t.k == "-1")
        msg = "\\underset{\\longrightarrow}{ " + t.k + " r_{" + std::to_string(t.r) + "}}";
    else
        msg = "\\underset{\\longrightarrow}{ \\frac{1}{" + t.k + "} r_{" + std::to_string(t.r) + "}}";

    out.push(msg);
    return out;
}