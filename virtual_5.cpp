#include <iostream>
using namespace std;

class Base{
public:
	virtual void func1()
	{
		cout << "Base::func1 "<< endl;
	}
	virtual void func2()
	{
		cout << "Base::func2" <<endl;
	}

	int data;
};

class Derived: public Base{
public:
	void func1()
	{
		cout << "Derived::func1" <<endl;
	}
	int data2;
};

typedef void (*FUNC)();

int main(void)
{
	cout<< sizeof(int) << endl;
	cout<< sizeof(Base) << endl;
	cout<< sizeof(Derived) << endl;
	Base b;
	long** p = (long**)&b;

	FUNC fun = (FUNC)p[0][0];
	fun();

	fun = (FUNC)p[0][1];
	fun();
	
	cout << "**************"<< endl;	
	Derived d;
	p = (long**)&d;
	fun = (FUNC)p[0][0];
	fun();

	fun = (FUNC)p[0][1];
	fun();

	return 0;
}



