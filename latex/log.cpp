#ifndef HEADER_LOG
#define HEADER_LOG
#include "log.hpp"
#endif

#ifndef HEADER_VECTOR
#define HEADER_VECTOR
#include <vector>
#endif

#ifndef HEADER_STRING
#define HEADER_STRING
#include <string>
#endif

#ifndef HEADER_IOSTREAM
#define HEADER_IOSTREAM
#include <iostream>
#endif

void latexOutput::log::push(std::string in)
{
    this->data.push_back(in);
}

void latexOutput::log::pop()
{
    this->data.pop_back();
}

std::string latexOutput::log::get(int i) const
{
    return this->data[i];
}

int latexOutput::log::size() const
{
    return this->data.size();
}

std::ostream &operator<<(std::ostream &out, const latexOutput::log &t)
{
    for (int i = 0; i < t.size(); ++i)
    {
        std::cout << t.get(i) << std::endl;
    }

    return out;
}

latexOutput::log &operator<<(latexOutput::log &out, const latexOutput::log &t)
{
    for (int i = 0; i < t.size(); ++i)
    {
        out.push(t.get(i));
    }

    return out;
}