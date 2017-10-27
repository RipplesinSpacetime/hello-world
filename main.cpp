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
        getline(cin, buf);//����һ�б��ʽ���ŵ�buf �С�  
	if(buf.compare("exit") == 0) break;

        //cout<<buf<<endl;//���  
        Scanner scanner(buf);//ɨ����ʽ  
        Parser parser(scanner);  
        parser.Parse();//����  
        cout<< parser.Calculate()<<endl;  //������ϣ�����  
    }while(status!=STATUS_QUIT);  

    cout <<"calc exit"<<endl;
    return 0;  
}  
