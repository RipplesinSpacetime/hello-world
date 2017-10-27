#include <iostream>
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

class ShapFactory{
public:
	static Shap* CreatShap(const string& name)
	{
		Shap* ps = NULL;
		if(name == "Circle")
		{
			ps = new Circle;
		}
		else if(name == "Square")
		{
			ps = new Square;
		}
		return ps;
	}
};

void DrawAll(const vector<Shap*> &v)
{
	vector<Shap*>::const_iterator it;
	for(it = v.begin(); it != v.end(); ++it)
	{
		(*it)->draw();
	}
}

int main(void)
{
	vector<Shap *> vec;
	Shap* sp;
	sp = new Circle;
	vec.push_back(sp);
	
	sp = new Square;
	vec.push_back(sp);

	sp = new Circle;
	vec.push_back(sp);
	
	sp = ShapFactory::CreatShap("Circle");
	vec.push_back(sp);
	sp = ShapFactory::CreatShap("Square");
	
	vec.push_back(sp);
	DrawAll(vec);

	return 0;
}



