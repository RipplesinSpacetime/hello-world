#include <iostream>

using namespace std;

template <typename T>

int compare(const T v1, const T v2)
{
	if(v1 < v2) return -1;
	if(v1 > v2) return 1;

	return 0;
}

int main()
{
	float i1 = 8.1;
	float i2 = 5;

	int i = 0;

	i = compare(i1, i2);

	cout << "i_max = " << i << endl;
}




