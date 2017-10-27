#include "scaner.h"  
#include <cctype>  
#include <stdlib.h>
#include <iostream>

using namespace std;
  
Scanner::Scanner(const std::string& buf):buf_(buf),curPos_(0)  
{  
    Accept();//调用构造方法就开始扫描了。  
}  

double Scanner::Number() const  
{  
    return number_;  
}  

EToken Scanner::Token() const  
{  
    return token_;  
}  

//忽略空白字符  
void Scanner ::SkipWhite()  
{  
    while(isspace(buf_[curPos_]))  
    {  
        ++curPos_;  
    }  
}  

void Scanner::Accept()  
{  
    SkipWhite();//首先忽略空白字符  
    //std::cout <<__LINE__ << ":  "<< __FUNCTION__ << endl;
    switch (buf_[curPos_])  
    {  
    case '+':  
        token_= TOKEN_PLUS;  
        ++curPos_;  
        break;  
    case '-':  
        token_= TOKEN_MINUS;  
        ++curPos_;  
        break;  
    case '*':  
        token_= TOKEN_MULTIPLY;  
        ++curPos_;  
        break;  
    case '/':  
        token_= TOKEN_DIVIDE;  
        ++curPos_;  
        break;  
    case '(':  
        token_= TOKEN_LPARENTHESIS;  
        ++curPos_;  
        break;  
    case ')':  
        token_= TOKEN_RPARENTHESIS;  
        ++curPos_;  
        break;  
    case '0':case '1':case '2': case '3': case '4': case '5':  
    case '6': case '7': case '8': case '9':case '.':  
        token_= TOKEN_NUMBER;  
        char* p;  
        number_ = strtod(&buf_[curPos_],&p);//&p 是指针的指针 指针指向了第一个不是数字的位置  
        //然后根据&p 得到cur_pos 的位置  指针的位置减去首地址  
        //curPos_  是一个整数  要将地址转换成数字  
        curPos_= p- &buf_[0];  
        break;  
    case '\0':case '\n':case '\r':  
        token_= TOKEN_END;//表达式结束  
        break;  
    default:  
        token_= TOKEN_ERROR;  
        break;  
    }  
}  



