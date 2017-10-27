#include <iostream>  
   
using namespace std;  
   
class A  
{  
public:  
    virtual void print()  
    {  
        cout << "A::print()" << "\n";  
    }  
};  
   
class B: public A  
{  
public: virtual void print()  
    {  
        cout << "B::print()" << "\n";  
    }  
};  
   
class C: public A  
{  
public: virtual void print()  
    {  
        cout << "C::print()" << "\n";  
    }  
};  
   
void print(C b)  
{  
    b.print();  
}  
   
int main()  
{  
    A a, *aa, *ab, *ac;  
    B b;  
    C c;  
    aa = &a;  
    ab = &b;  
    ac = &c;  

    cout << "a.p  b.p  c.p " << endl;
    a.print();  
    b.print();  
    c.print();  

    cout << "*a.p  *b.p  *c.p " << endl;
    aa->print();  
    ab->print();  
    ac->print();  

    cout << "print   " << endl;
    //print(a);  
    //print(b);  
    print(c);  
}  



