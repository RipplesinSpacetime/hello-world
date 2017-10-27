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
    cout << a << endl;    //正确
    cout << a1 << endl;   //正确
    cout << a2 << endl;   //正确，类内访问
    cout << a3 << endl;   //正确，类内访问
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
  itema.a = 10;    //正确
  itema.a1 = 20;    //正确
  itema.a2 = 30;    //错误，类外不能访问protected成员
  //itema.a3 = 40;    //错误，类外不能访问private成员
  //system("pause");
  return 0;
}
