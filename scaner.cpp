#include "scaner.h"  
#include <cctype>  
#include <stdlib.h>
#include <iostream>

using namespace std;
  
Scanner::Scanner(const std::string& buf):buf_(buf),curPos_(0)  
{  
    Accept();//���ù��췽���Ϳ�ʼɨ���ˡ�  
}  

double Scanner::Number() const  
{  
    return number_;  
}  

EToken Scanner::Token() const  
{  
    return token_;  
}  

//���Կհ��ַ�  
void Scanner ::SkipWhite()  
{  
    while(isspace(buf_[curPos_]))  
    {  
        ++curPos_;  
    }  
}  

void Scanner::Accept()  
{  
    SkipWhite();//���Ⱥ��Կհ��ַ�  
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
        number_ = strtod(&buf_[curPos_],&p);//&p ��ָ���ָ�� ָ��ָ���˵�һ���������ֵ�λ��  
        //Ȼ�����&p �õ�cur_pos ��λ��  ָ���λ�ü�ȥ�׵�ַ  
        //curPos_  ��һ������  Ҫ����ַת��������  
        curPos_= p- &buf_[0];  
        break;  
    case '\0':case '\n':case '\r':  
        token_= TOKEN_END;//���ʽ����  
        break;  
    default:  
        token_= TOKEN_ERROR;  
        break;  
    }  
}  



