#include <iostream>

using namespace std;

template <typename T>

class MyClass
{
private:	
	typename T::SubType* ptr_;
};

int main(void)
{

	return 0;
}


