/*
 * 此文件将被包含到 Matrix.hpp 中，由此不需要也无法单独编译
 */
#ifndef HEADER_MATRIX
#define HEADER_MATRIX
#include "Matrix.hpp"
#endif

#ifndef HEADER_LATEXOUTPUT
#define HEADER_LATEXOUTPUT
#include "latexOutput.hpp"
#endif

#ifndef HEADER_STRING
#define HEADER_STRING
#include <string>
#endif

#ifndef HEADER_IOSTREAM
#define HEADER_IOSTREAM
#include <iostream>
#endif

#ifndef HEADER_ERROR
#define HEADER_ERROR
#include "ERROR.hpp"
#endif

// 构造矩阵，输入行和列
template <class T>
dataType::Matrix<T>::Matrix(int r, int c)
{
    this->root = new T[r * c];
    this->r = r;
    this->c = c;
}

template <class T>
dataType::Matrix<T>::~Matrix()
{
    delete this->root;
}

// 对换变换
// 交换a行和b行
template <class T>
const latexOutput::swap dataType::Matrix<T>::swap(int a, int b)
{
    if (a >= this->r || b >= this->r)
        throw new ERROR("In swap " + std::to_string(a) + ">=this->r || " + std::to_string(b) + ">=this->r");

    T tmp;
    for (int i = 0; i < this->c; ++i)
    {
        tmp = this->get(a, i);
        this->set(this->get(b, i), a, i);
        this->set(tmp, b, i);
    }

    latexOutput::swap out(a, b);
    return out;
}

template <class T>
const latexOutput::rowSum dataType::Matrix<T>::rowSum(int k, int r1, int r2)
{
    T tmp(k);
    return rowSum(tmp, r1, r2);
}

// 倍加变换
// r1行加上k倍的r2行
template <class T>
const latexOutput::rowSum dataType::Matrix<T>::rowSum(T k, int r1, int r2)
{
    if (r1 >= this->r || r2 >= this->r)
        throw new ERROR("In rowSum a>=this->r || b>=this->r");

    T tmp;
    for (int i = 0; i < this->c; ++i)
    {
        tmp = this->get(r2, i);
        tmp = tmp * k;
        tmp = this->get(r1, i) + tmp;
        this->set(tmp, r1, i);
    }

    latexOutput::rowSum out(k.toString(), k > 0, r1, r2);
    return out;
}

template <class T>
const latexOutput::rowMul dataType::Matrix<T>::rowMul(int k, int r)
{
    T tmp(k);
    return rowMul(tmp, r);
}

// 倍乘变换
template <class T>
const latexOutput::rowMul dataType::Matrix<T>::rowMul(T k, int r)
{
    if (r >= this->r)
        throw new ERROR("In rowMul r >= this->r");

    for (int i = 0; i < this->c; ++i)
        this->set(this->get(r, i) * k, r, i);

    latexOutput::rowMul out(k.toString(), r);
    return out;
}

template <class T>
const latexOutput::rowDiv dataType::Matrix<T>::rowDiv(int k, int r)
{
    T tmp(k);
    return rowDiv(tmp, r);
}
// 倍除变换
template <class T>
const latexOutput::rowDiv dataType::Matrix<T>::rowDiv(T k, int r)
{
    if (r >= this->r)
        throw new ERROR("In rowDiv r >= this->r");

    for (int i = 0; i < this->c; ++i)
        this->set(this->get(r, i) / k, r, i);

    latexOutput::rowDiv out(k.toString(), r);
    return out;
}

//设置第rc个元素为in
template <class T>
void dataType::Matrix<T>::set(T in, int r, int c)
{
    if (r >= this->r || c >= this->c)
        throw new ERROR("In set r>=this->r||c>=this->c");

    root[r * this->c + c] = in;
}

//获取第rc个元素
template <class T>
const T dataType::Matrix<T>::get(int r, int c) const
{
    if (r >= this->r || c >= this->c)
        throw new ERROR("In get r>=this->r||c>=this->c");

    return root[r * this->c + c];
}

//返回当前矩阵有多少行
template <class T>
int dataType::Matrix<T>::getRow() const
{
    return this->r;
}

//返回当前矩阵有多少列
template <class T>
int dataType::Matrix<T>::getCol() const
{
    return this->c;
}

//矩阵的输入
template <typename T>
std::istream &operator>>(std::istream &in, dataType::Matrix<T> &t)
{
    for (int i = 0; i < t.getRow(); ++i)
        for (int j = 0; j < t.getCol(); ++j)
        {
            T tmp;
            in >> tmp;
            t.set(tmp, i, j);
        }
    return in;
}

//矩阵的输出
template <typename T>
std::ostream &operator<<(std::ostream &out, const dataType::Matrix<T> &t)
{
    for (int i = 0; i < t.getRow(); ++i)
    {
        for (int j = 0; j < t.getCol(); ++j)
            out << t.get(i, j) << " ";
        out << std::endl;
    }
    return out;
}

// 输出到日志
template <typename T>
latexOutput::log &operator<<(latexOutput::log &out, const dataType::Matrix<T> &t)
{
    std::string msg;
    msg = "\\left[\\begin{matrix}";
    for (int i = 0; i < t.getRow(); ++i)
    {
        for (int j = 0; j < t.getCol() - 1; ++j)
        {
            msg += t.get(i, j).toString();
            msg += " & ";
        }
        msg += t.get(i, t.getCol() - 1).toString();
        if (i != t.getRow() - 1)
            msg += " \\\\ ";
    }
    msg += " \\end{matrix}\\right]\\\\";
    out.push(msg);
    return out;
}