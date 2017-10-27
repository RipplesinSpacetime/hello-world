#include <iostream>
using namespace std;

class Base{
public:
	Base()
	{
		cout << "Base ..." << endl;
	}
	virtual void f(float x)
	{
		cout << "Base::f(float x) "<<x<< endl;
	}
	void g(float x)
	{
		cout << "Base::g(float x)" <<x<<endl;
	}
	void h(float x)
	{
		cout << "Base::h(float x)" <<x<<endl;
	}
	virtual ~Base()
	{
		cout << "~Base ..." << endl;
	}
	
};

class Derived: public Base{
public:
	Derived()
	{
		cout << "Derived ... "<< endl;
	}
	virtual void f(float x)
	{
		cout << "Derived::f(float x) "<<x<< endl;
	}
	void g(float x)
	{
		cout << "Derived::g(float x)" <<x<<endl;
	}
	void h(float x)
	{
		cout << "Derived::h(float x)" <<x<<endl;
	}
	virtual ~Derived()
	{
		cout << "~Derived ... "<< endl;
	}
};

int main(void)
{
	Base* pb = new Derived();
	delete pb;
	
	cout <<"***************" << endl;
	Derived* pd = new Derived();
	delete pd;
	return 0;
}
