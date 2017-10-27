#ifndef _PARSER_H_  
#define _PARSER_H_  

class Scanner;  
class Node;//前项声明  

enum STATUS{  
    STATUS_OK,  
    STATUS_ERROR,  
    STATUS_QUIT, 
};  

class Parser  
{  
    //这里是引用的方式来使用Scanner 或者指针的方式，没有必要这么快就包含头文件，可以用前项声明。  
    //这样的话，头文件会比较小，cpp 中多次包含了，就会使得可执行文件增大  
public:  
    Parser(Scanner& scanner);  
    void Parse();  
    Node* Expr();//表达式  
    Node* Term();//项  
    Node* Factory();//因式  
    double Calculate() const;  
private:  
    Scanner& scanner_;  
    Node* tree_;//生成一棵表达式树  
    STATUS status_;  
};  
#endif  


