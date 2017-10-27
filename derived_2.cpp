#include <iostream>

using namespace std;

class Base{
public:
	Base(int _i):i(_i)
	{
		cout << "Base ... "<< endl;
	}
	~Base()
	{
		cout << "~Base ... "<< endl;
	}
	int i;
};
class Derived:public Base{
public:
	Derived(int _j):j(_j), Base(8)
	{
		cout << "Derived ..." << endl;
	}
	~Derived()
	{
		cout << "~Derived ..." << endl;
	}
	int j;
};



int main(void)
{
	Base b(8);
	Derived d(5);
	cout << d.j << endl;
	cout << b.i << endl;
	cout << "sizeof(Base) = " << sizeof(Base) << endl;

	return 0;
}
