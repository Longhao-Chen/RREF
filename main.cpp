#ifndef HEADER_DATATYPE
#define HEADER_DATATYPE
#include "dataType.hpp"
#endif

#ifndef HEADER_MATRIX
#define HEADER_MATRIX
#include "Matrix.hpp"
#endif

#ifndef HEADER_LATEXOUTPUT
#define HEADER_LATEXOUTPUT
#include "latexOutput.hpp"
#endif

#ifndef HEADER_LOG
#define HEADER_LOG
#include "log.hpp"
#endif

#ifndef HEADER_RREF
#define HEADER_RREF
#include "RREF.hpp"
#endif

#ifndef HEADER_ERROR
#define HEADER_ERROR
#include "ERROR.hpp"
#endif

using namespace std;

template <typename T>
dataType::Matrix<T> input()
{
    int r, c;
    cin >> r >> c;
    dataType::Matrix<T> data(r, c);
    cin >> data;
    return data;
}

int main()
{
    latexOutput::log log;
    try
    {
        std::cout << "input Row Col and Matrix element:" << std::endl;
        auto data = input<dataType::Int>();
        log << data;
        log << RREF(data);
        cout << log;
    }
    catch (ERROR *&e)
    {
        std::cerr << log;
        std::cerr << *e;
    }
}