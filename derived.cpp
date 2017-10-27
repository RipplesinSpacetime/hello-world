#include <iostream>

using namespace std;

class Base{
public:
	Base()
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
	Derived()
	{
		cout << "Derived ..."<< endl;
	}
	~Derived()
	{
		cout << "~Derived ..."<< endl;
	}
	int j;
};

int main(void)
{
	Derived d;
	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(derived) = " << sizeof(Derived) << endl;

	return 0;
}
