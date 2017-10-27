#include <iostream>

using namespace std;

class Box{
public:
	Box(int h, int w, int l):height(h), width(w), \
		length(l){}
	int volume();
	void show();
private:
	int height;
	int width;
	int length;
};

#if 0
Box::Box(int h, int w, int l)
{
	height = h;
	width = w;
	length = l;
}
#endif

int Box::volume()
{
	return (height*width*length);
}

void Box::show()
{
	cout << "height: " << height << endl;
	cout << "width:  " << width << endl;
	cout << "length: " << length << endl;
	cout << "The volume of box is:" << volume() << endl;
}

int main()
{
	Box box1(1, 1, 2);
	box1.show();
}




