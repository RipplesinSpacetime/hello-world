#ifndef _PARSER_H_  
#define _PARSER_H_  

class Scanner;  
class Node;//ǰ������  

enum STATUS{  
    STATUS_OK,  
    STATUS_ERROR,  
    STATUS_QUIT, 
};  

class Parser  
{  
    //���������õķ�ʽ��ʹ��Scanner ����ָ��ķ�ʽ��û�б�Ҫ��ô��Ͱ���ͷ�ļ���������ǰ��������  
    //�����Ļ���ͷ�ļ���Ƚ�С��cpp �ж�ΰ����ˣ��ͻ�ʹ�ÿ�ִ���ļ�����  
public:  
    Parser(Scanner& scanner);  
    void Parse();  
    Node* Expr();//���ʽ  
    Node* Term();//��  
    Node* Factory();//��ʽ  
    double Calculate() const;  
private:  
    Scanner& scanner_;  
    Node* tree_;//����һ�ñ��ʽ��  
    STATUS status_;  
};  
#endif  


