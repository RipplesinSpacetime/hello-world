#include <iostream>

using namespace std;

template <typename T>

class MyClass
{
private:	
	T value;
public:
	template <class X>
	void Assign(const MyClass<X>& x)
	{
		value = x.GetValue();
	}
	T GetValue() const
	{
		return value;
	}
};

int main(void)
{
	MyClass<double> d;
	MyClass<int> i;

	d.Assign(d);
	d.Assign(i); // error

	return 0;
}


