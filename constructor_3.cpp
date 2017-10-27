#include <iostream>

using namespace std;

class Box{
public:
	Box(int, int, int);
	Box(int, int);
	int volume();
	void show();

	int width;
	int length;
	static int height;
};
Box::Box(int w, int l, int h)
{
	height = h;
	width = w;
	length = l;
}

Box::Box(int w, int l)
{
	width = w;
	length = l;
}

int Box::height = 10;

int Box::volume()
{
	return (height*width*length);
}

void Box::show()
{
	cout << "width:  " << width << endl;
	cout << "length: " << length << endl;
	cout << "height: " << height << endl;
	cout << "The volume of box is:" << volume() << endl;
}

int main()
{
	Box box2(2, 1);
	box2.show();

	Box box1(1, 1, 2);
	box1.show();

	Box box3(1, 1);
	box3.show();
}




