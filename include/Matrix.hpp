#ifndef HEADER_LATEXOUTPUT
#define HEADER_LATEXOUTPUT
#include "latexOutput.hpp"
#endif

#ifndef HEADER_LOG
#define HEADER_LOG
#include "log.hpp"
#endif
namespace dataType
{
    template <class T>
    class Matrix
    {
    private:
        T *root;
        int r;
        int c;

    public:
        Matrix(int, int);
        ~Matrix();
        const latexOutput::swap swap(int, int);
        const latexOutput::rowSum rowSum(int, int, int);
        const latexOutput::rowSum rowSum(T, int, int);
        const latexOutput::rowMul rowMul(int, int);
        const latexOutput::rowMul rowMul(T, int);
        const latexOutput::rowDiv rowDiv(int, int);
        const latexOutput::rowDiv rowDiv(T, int);
        void set(T, int, int);
        const T get(int, int) const;
        int getRow() const;
        int getCol() const;
    };
}
template <typename T>
std::istream &operator>>(std::istream &in, dataType::Matrix<T> &t);
template <typename T>
std::ostream &operator<<(std::ostream &out, const dataType::Matrix<T> &t);
template <typename T>
latexOutput::log &operator<<(latexOutput::log &out, const dataType::Matrix<T> &t);

#define HEADER_MATRIX
#include "../dataType/Matrix.cpp"