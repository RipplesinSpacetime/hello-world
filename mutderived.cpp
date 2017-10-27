#include <iostream>

using namespace std;

class Bed{
public:
	Bed(int weight):weight_(weight)
	{

	}
	void sleep()
	{
		cout << "I am sleeping..." << endl;
	}

	int weight_;	
};

class Sofa{
public:
	Sofa(int weight):weight_(weight)
	{

	}
	void Watch()
	{
		cout << "I am watching TV..." << endl;
	}
	int weight_;
};

class SofaBed: public Bed, public Sofa
{
public:
	SofaBed():Bed(200), Sofa(100)
	{

	}
	void FoldOut()
	{
		cout << "Fold out..."<<endl;
	}
	void FoldIn()
	{
		cout << "Fold in..."<<endl;
	}
	int weight_;
};
int main(void)
{
	SofaBed sb;
	sb.sleep();
	sb.Watch();
	sb.FoldOut();
	sb.FoldIn();
	cout << "Bed  "<< sb.Bed::weight_ << endl;
	cout << "Sofa " << sb.Sofa::weight_ << endl;

	cout << sizeof(Bed) << endl;
	cout << sizeof(Sofa) << endl;
	cout << sizeof(SofaBed) << endl;
	return 0;
}




