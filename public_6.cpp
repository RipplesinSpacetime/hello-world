#include <iostream>

using namespace std;

class A{
public:
	A()
	{
		a = 1;
	}
	void func()
	{
		cout << "class A" << endl;
	}
public:
	int a;
};

class B:public A{
public:
	B()
	{
		a = 2;
	}
	void func()
	{
		cout << "class B" << endl;
	}
public:
	int a;
};

int main()
{
	B b;
	cout << "B:  "<< b.a << endl;
	cout << "B::A  "<< b.A::a << endl;
	b.func();
	b.A::func();
	return 0;
}



