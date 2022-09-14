/*
 * 此文件将被包含到 RREF.hpp 中，由此不需要也无法单独编译
 */

#ifndef HEADER_RREF
#define HEADER_RREF
#include "RREF.hpp"
#endif

#ifndef HEADER_MATRIX
#define HEADER_MATRIX
#include "Matrix.hpp"
#endif

#ifndef HEADER_IOSTREAM
#define HEADER_IOSTREAM
#include <iostream>
#endif

#ifndef HEADER_LOG
#define HEADER_LOG
#include "log.hpp"
#endif

// 将data化简到简化阶梯型
template <typename T>
latexOutput::log RREF(dataType::Matrix<T> &data)
{
    latexOutput::log log;
    int row = 0; //当前正在处理的行，不能为最后一行
    int col = 0; //当前正在处理的列，不能为最后一列

    // i 为当前正在处理的列，最后一列为系数列，不需要处理
    for (col = 0; col < data.getCol() - 1; ++col)
    {
        // 最后一行需要特殊处理
        if (row == data.getRow() - 1)
        {
            break;
        }
        // 先将当前主元换成非零
        if (!nonZero(data, row, col, log))
        {
            // 如果当前列全部为零，则处理下一列
            continue;
        }
        // 查找当前列绝对值为1的行，如果有则直接换过来
        if (findOne(data, row, col, log))
        {
            mainToZero(data, row, col, log);
            ++row;
            continue;
        }

        // 尝试通过倍加来化简
        if (swapAndFindModOne(data, row, col, log))
        {
            mainToZero(data, row, col, log);
            ++row;
            continue;
        }

        // 尝试通过倍乘来化简
        if (tryNormalization(data, row, col, log))
        {
            mainToZero(data, row, col, log);
            ++row;
            continue;
        }

        // 如果执行到这里，说明无法用已知方法化简
        ++row;
    }
    if (row != data.getRow() - 1)
    {
        // 还不是最后一行，这说明列已经到了系数列
        return log;
    }
    else
    {
        // 现在该处理最后一行了
        // 查找非零元素
        for (; col < data.getCol() - 1; ++col)
        {
            if (!(data.get(row, col) == 0))
                break;
        }

        if (canNormalization(data, row, col))
        {
            log << data.rowDiv(data.get(row, col), row);
            log << data;
            mainToZero(data, row, col, log);
        }
    }

    return log;
}

// 使当前行主元不为0
template <typename T>
bool nonZero(dataType::Matrix<T> &data, int r, int c, latexOutput::log &log)
{
    if (!(data.get(r, c) == 0))
        return true;
    for (int i = r + 1; i < data.getRow(); ++i)
    {
        if (!(data.get(i, c) == 0))
        {
            log << data.swap(i, r);
            log << data;
            return true;
        }
    }
    return false;
}

// 找 当前行及下面的行 的 正在处理的列 是否有绝对值为1元素，如果有，则对换，并返回true
template <typename T>
bool findOne(dataType::Matrix<T> &data, int r, int c, latexOutput::log &log)
{
    if (data.get(r, c) == 1)
        return true;
    if (data.get(r, c) == -1)
    {
        log << data.rowMul(-1, r);
        log << data;
        return true;
    }
    for (int i = r + 1; i < data.getRow(); ++i)
    {
        if (data.get(i, c) == 1)
        {
            log << data.swap(r, i);
            log << data;
            return true;
        }
        if (data.get(i, c) == -1)
        {
            log << data.swap(r, i);
            log << data;
            log << data.rowMul(-1, r);
            log << data;
        }
    }
    return false;
}

template <typename T>
bool swapAndFindModOne(dataType::Matrix<T> &data, int r, int c, latexOutput::log &log)
{
    if (findModOne(data, r, c, log))
        return true;
    for (int i = r + 1; i < data.getRow(); ++i)
    {
        log << data.swap(r, i);
        log << data;
        if (findModOne(data, r, c, log))
            return true;

        log.pop();
        log.pop();
        data.swap(r, i);
    }
    return false;
}

// 找下面的行 与 当前行 的 正在处理的列 是否有相模余1元素，如果有，则利用那一行化简当前行
template <typename T>
bool findModOne(dataType::Matrix<T> &data, int r, int c, latexOutput::log &log)
{
    for (int i = r + 1; i < data.getRow(); ++i)
    {
        if (data.get(i, c) == 0)
            continue;
        if (data.get(r, c) % data.get(i, c) == 1)
        {
            int k = data.get(r, c).get_k(data.get(i, c));
            log << data.rowSum(-k, r, i);
            log << data;
            return true;
        }
    }
    return false;
}

// 尝试找到能够归一化的行
template <typename T>
bool tryNormalization(dataType::Matrix<T> &data, int r, int c, latexOutput::log &log)
{
    if (canNormalization(data, r, c))
    {
        log << data.rowDiv(data.get(r, c), r);
        log << data;
        return true;
    }
    for (int i = r + 1; i < data.getRow(); ++i)
    {
        if (canNormalization(data, i, c))
        {
            log << data.swap(i, r);
            log << data;
            log << data.rowDiv(data.get(r, c), r);
            log << data;
            return true;
        }
    }
    return false;
}
// 判断是否能被归一化
template <typename T>
bool canNormalization(dataType::Matrix<T> &data, int r, int c)
{
    for (int i = 0; i < data.getCol(); ++i)
    {
        if (data.get(r, c) == 0)
            return false;
        if (!(data.get(r, i) % data.get(r, c) == 0))
            return false;
    }
    return true;
}

// 将当前主元所在的列归零
template <typename T>
void mainToZero(dataType::Matrix<T> &data, int r, int c, latexOutput::log &log)
{
    for (int i = 0; i < data.getRow(); ++i)
        if (i != r && !(data.get(i, c) == 0))
        {
            log << data.rowSum(-data.get(i, c), i, r);
            log << data;
        }
}