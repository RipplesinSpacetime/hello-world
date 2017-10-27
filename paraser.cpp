#include "paraser.h"  
#include "scaner.h"  
#include "Node.h"  
#include <cassert>  
#include <iostream>  
using namespace std;
  
//�����ڳ�ʼ���б��н��г�ʼ��  
Parser::Parser(Scanner& scanner):scanner_(scanner),tree_(0)//0 ����null  
{  
  
}  

void Parser::Parse()  
{  
    tree_= Expr();//�����Ƿ���һ�����ʽ  ����һ��Node  
}  

Node* Parser::Expr()  
{  
    Node* node = Term();  
    EToken token = scanner_.Token();//��ǰɨ������״̬  
#if 0
    if(token == TOKEN_PLUS)  
    {  
        scanner_.Accept();//���ɨ��Ӻ� ���� �Ӻ�  Ϊ��ɨ����һ���ַ�  
        Node* nodeRight = Expr();  
        node = new AddNode(node,nodeRight);  
    }
    else if(token == TOKEN_MINUS)  
    {  
        scanner_.Accept();  
        Node* nodeRight = Expr();  
        node = new SubNode(node,nodeRight);  
    }  
#endif
    if(token == TOKEN_PLUS || token == TOKEN_MINUS)
    {
	MultipleNode* multipleNode = new SumNode(node);
	do
	{
        	scanner_.Accept();  
		Node* nextNode = Term();
		multipleNode->AppendChild(nextNode, (token == TOKEN_PLUS));
		token = scanner_.Token();
	}while(token == TOKEN_PLUS || token == TOKEN_MINUS);
	node = multipleNode;
    }
    return node;  
}  
Node* Parser::Factory()  
{  
    Node* node=0;  
    EToken token = scanner_.Token();  
    if(token == TOKEN_LPARENTHESIS)//������  
    {  
        scanner_.Accept();//ָ�����ƶ� accept'('  
        node = Expr();  
        if(scanner_.Token()==TOKEN_RPARENTHESIS)  
        {  
            scanner_.Accept();//accept ')'  
        }
	else  
        {  
            status_= STATUS_ERROR;  
            //Todo:�׳��쳣  
            cout<<"not a valid experssion"<<endl;  
            node = 0;  
        }  
    }
    else if(token == TOKEN_NUMBER)  
    {  
        node = new NumberNode(scanner_.Number());  
        scanner_.Accept();  
    }
    else if(token == TOKEN_MINUS)  
    {  
        scanner_.Accept();//accept minus ����  
        node = new UMinusNode(Factory());  
    }
    else  
    {  
        status_= STATUS_ERROR;  
        //Todo:�׳��쳣  
            cout<<"not a valid experession"<<endl;  
            node=0;  
    }  
    return node;  
}  
Node* Parser::Term()  
{  
    Node* node = Factory();  
    EToken token = scanner_.Token();  
#if 0
    if(token == TOKEN_MULTIPLY)  
    {  
        scanner_.Accept();  
        Node* nodeRight = Term();  
        node = new MultiplyNode(node, nodeRight);  
    }
    else if(token == TOKEN_DIVIDE)  
    {  
        scanner_.Accept();  
        Node* nodeRight = Term();  
        node = new DevideNode(node, nodeRight); 
  
    }  
#endif
    if(token == TOKEN_MULTIPLY || token == TOKEN_DIVIDE)
    {
	MultipleNode* multipleNode = new ProductNode(node);
	do
	{
        	scanner_.Accept();  
		Node* nextNode = Factory();
		multipleNode->AppendChild(nextNode, (token == TOKEN_MULTIPLY));
		token = scanner_.Token();
	}while(token == TOKEN_MULTIPLY || token == TOKEN_DIVIDE);
	node = multipleNode;
    }
    return node;  
}  

//��const �Ͳ���const �ǿ��Թ������صġ�  
double Parser::Calculate() const  
{  
    assert(tree_ != 0);  
    return tree_->Calc();  
}  



