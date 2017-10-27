#include <iostream>

using namespace std;

class Box{
public:
	Box(int w = 10, int l = 10, int h = 10);
	int volume();
	void show();

	int width;
	int length;
	int height;
};

Box::Box(int w, int l, int h)
{
	height = h;
	width = w;
	length = l;
}

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
	Box box1;
	box1.show();

	Box box2(2, 1);
	box2.show();

	Box box3(1, 1, 2);
	box3.show();
}




