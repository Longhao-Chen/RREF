// 错误处理模块
#ifndef HEADER_ERROR
#define HEADER_ERROR
#include "ERROR.hpp"
#endif

#ifndef HEADER_STRING
#define HEADER_STRING
#include <string>
#endif

#ifndef HEADER_IOSTREAM
#define HEADER_IOSTREAM
#include <iostream>
#endif

#ifndef HEADER_LIBUNWIND
#define HEADER_LIBUNWIND
#include <libunwind.h>
#endif

#ifndef HEADER_VECTOR
#define HEADER_VECTOR
#include <vector>
#endif

ERROR::ERROR(std::string msg)
{
    this->msg = msg;
    this->backtrace();
}
// 获取函数调用栈
void ERROR::backtrace()
{
    unw_cursor_t cursor;
    unw_context_t context;

    unw_getcontext(&context);
    unw_init_local(&cursor, &context);

    while (unw_step(&cursor) > 0)
    {
        unw_word_t offset, pc;
        unw_get_reg(&cursor, UNW_REG_IP, &pc);
        if (pc == 0)
            break;

        char sym[256];
        if (unw_get_proc_name(&cursor, sym, sizeof(sym), &offset) == 0)
        {
            this->bt.push_back("0x" + std::to_string(pc) + ": (" + std::string(sym) + "0x" + std::to_string(offset) + ")");
        }
        else
        {
            this->bt.push_back("0x" + std::to_string(pc) + ": -- error: unable to obtain symbol name for this frame");
        }
    }
}

std::ostream &operator<<(std::ostream &out, const ERROR &t)
{
    out << "----------" << std::endl;
    out << "ERROR: " << t.msg << std::endl << std::endl;
    out << "Backtrace: " << std::endl;
    for (int i = 0; i < t.bt.size(); ++i)
    {
        out << t.bt[i] << std::endl;
    }
    return out;
}