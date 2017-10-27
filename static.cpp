#include <iostream>

using namespace std;

class Box{
public:
	Box(int, int, int);
	int volume();

	static int height;
	int width;
	int length;
};

Box::Box(int w, int len, int hei)
{
	width = w;
	length = len;
	height = hei;
}

int Box::volume()
{
	return (height*width*length);
}

int Box::height = 10;

int main()
{
	Box b(1, 1, 1);
	Box a(1, 2, 5);

	cout << a.height << endl;
	cout << b.height << endl;

	cout << Box::height << endl;
	cout << a.volume() << endl;
	cout << b.volume() << endl;
}




