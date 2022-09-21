/*
 * 错误处理
 */
#ifndef HEADER_STRING
#define HEADER_STRING
#include <string>
#endif

#ifndef HEADER_IOSTREAM
#define HEADER_IOSTREAM
#include <iostream>
#endif

#ifndef HEADER_VECTOR
#define HEADER_VECTOR
#include <vector>
#endif

class ERROR
{
private:
    void backtrace();

public:
    ERROR(std::string);
    std::vector<std::string> bt; //调用栈
    std::string msg;             // 错误信息
};
std::ostream &operator<<(std::ostream &out, const ERROR &t);