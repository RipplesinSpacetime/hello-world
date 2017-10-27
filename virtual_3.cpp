#include <iostream>
using namespace std;

class Base{
public:
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
};

class Derived: public Base{
public:
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
};

int main(void)
{
	Derived d;
	Base b;
	Base* pb = &b;
	Derived* pd = &d;

	pb->f(3.14f);
	pd->f(3.14f);
	
	cout << "pb = &d ..." << endl;
	pb = &d;
	pb->f(3.14f);
	pb->g(3.14f);
	pb->h(3.14f);
	cout << "pd ..." << endl;
	pd->f(3.14f);
	pd->g(3.14f);
	pd->h(3.14f);
	return 0;
}
