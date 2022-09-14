#ifndef HEADER_VECTOR
#define HEADER_VECTOR
#include <vector>
#endif

#ifndef HEADER_STRING
#define HEADER_STRING
#include <string>
#endif

namespace latexOutput
{
    class log
    {
    private:
        std::vector<std::string> data;

    public:
        void push(std::string);
        void pop();
        std::string get(int) const;
        int size() const;
    };
}

std::ostream &operator<<(std::ostream &, const latexOutput::log &);
latexOutput::log &operator<<(latexOutput::log &, const latexOutput::log &);