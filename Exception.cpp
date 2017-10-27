#include "Exception.h"

const char* Exception::what() const
{
    return message_.c_str();
}
const char* Exception::StackTrace() const throw()
{
    return message_.c_str();
}

void Exception::FillStackTrace()
{
    const int len = 200;
    void* buffer[len];
    int nptrs = ::backstrce(buffer, len);
    char** strings = ::backtrace_symbols(buffer, nptrs);
    if(strings)
    {
        for(int i = 0; i < nptrs; i++)
        {
            stackTrace_.append(strings[i]);
            stackTrace.push_back('\n');
        }
        free(strings);
    }
}




