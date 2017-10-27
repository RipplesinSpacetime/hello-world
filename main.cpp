#include <iostream>  
#include <string>  
#include "scaner.h"  
#include "paraser.h"  
using namespace std;  
int main(void)  
{  
    STATUS status = STATUS_OK;  
    do  
    {  
        cout<<"> ";  
        string buf;  
        getline(cin, buf);//输入一行表达式，放到buf 中。  
	if(buf.compare("exit") == 0) break;

        //cout<<buf<<endl;//输出  
        Scanner scanner(buf);//扫描表达式  
        Parser parser(scanner);  
        parser.Parse();//解析  
        cout<< parser.Calculate()<<endl;  //解析完毕，计算  
    }while(status!=STATUS_QUIT);  

    cout <<"calc exit"<<endl;
    return 0;  
}  
