#ifndef HEADER_MATRIX
#define HEADER_MATRIX
#include "Matrix.hpp"
#endif

#ifndef HEADER_LOG
#define HEADER_LOG
#include "log.hpp"
#endif

template <typename T>
bool nonZero(dataType::Matrix<T> &, int, int, latexOutput::log &);

template <typename T>
bool findOne(dataType::Matrix<T> &, int, int, latexOutput::log &);

template <typename T>
void mainToZero(dataType::Matrix<T> &, int, int, latexOutput::log &);

template <typename T>
bool swapAndFindModOne(dataType::Matrix<T> &, int, int, latexOutput::log &);
template <typename T>
bool findModOne(dataType::Matrix<T> &, int, int, latexOutput::log &);

template <typename T>
void mainToZero(dataType::Matrix<T> &, int, int, latexOutput::log &);

template <typename T>
bool tryNormalization(dataType::Matrix<T> &, int, int, latexOutput::log &);
template <typename T>
bool canNormalization(dataType::Matrix<T> &, int, int);

template <typename T>
void mainToZero(dataType::Matrix<T> &, int, int, latexOutput::log &);

#define HEADER_RREF
#include "../RREF.cpp"