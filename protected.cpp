#include<iostream>
#include<assert.h>
using namespace std;
class A{
public:
  int a;
  A(){
    a1 = 1;
    a2 = 2;
    a3 = 3;
    a = 4;
  }
  void fun(){
    cout << a << endl;    //��ȷ
    cout << a1 << endl;   //��ȷ
    cout << a2 << endl;   //��ȷ�����ڷ���
    cout << a3 << endl;   //��ȷ�����ڷ���
  }
public:
  int a1;
protected:
  int a2;
private:
  int a3;
};
int main(){
  A itema;
  itema.a = 10;    //��ȷ
  itema.a1 = 20;    //��ȷ
  itema.a2 = 30;    //�������ⲻ�ܷ���protected��Ա
  //itema.a3 = 40;    //�������ⲻ�ܷ���private��Ա
  //system("pause");
  return 0;
}
