#include <iostream>
#include <string>

using namespace std;

class A{
public:
	int a;
	A()
	{
		a1 = 1;
		a2 = 2;
		a3 = 3;
		a = 4;
	}
	void fun()
	{
		cout << a << endl;
		cout << a1 << endl;
		cout << a2 << endl;
		cout << a3 << endl;
	}

public:
	int a1;
protected:
	int a2;
private:
	int a3;
};

int main(void)
{
	A itema;
	itema.a = 10;
	itema.a1 = 20;
	//itema.a2 = 30; // error , because a2 is protected
	//itema.a3 = 40; // error, because a3 is private
	itema.fun();
}






