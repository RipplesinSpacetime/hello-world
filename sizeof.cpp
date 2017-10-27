#include <iostream>

using namespace std;

class Car{
public:
	int price;
	static int size;

};

int main()
{
	Car car;

	cout << "Sizeof(car): " << sizeof(car) << endl;
}
