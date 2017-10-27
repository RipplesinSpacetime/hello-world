/*******************************
 *
 *
 *******************************/
#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;

class Shap{
public:
	virtual void draw() = 0;
};

class Square: public Shap{
public:
	void draw()
	{
		cout << "Square " << endl;
	}
};

class Circle: public Shap{
public:
	void draw()
	{
		cout << "Circle " << endl;
	}
};


int main(void)
{
	Shap* sp;
	Circle c;;

	sp = &c;
	if(dynamic_cast<Circle*>(sp))
	{
		cout<<"sp is point to a Circle object." << endl;
		Circle* cp = dynamic_cast<Circle*>(sp);
		cp->draw();
	}
	else
	{
		cout<<"sp is point to other object."<<endl;
	}

	cout <<"class name:"<< typeid(*sp).name()<<endl;
	cout <<"class name:"<< typeid(Circle).name()<<endl;

	if(typeid(Circle).name() == typeid(*sp).name())
	{
		cout<<"sp is point to a Circle object." << endl;
	}

	return 0;
}



