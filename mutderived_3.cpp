#include <iostream>

using namespace std;

class Furniture{
public:
	Furniture(int wei):weight(wei)
	{

	}
	int weight;
};

class Bed: virtual public Furniture{
public:
	Bed(int weight):Furniture(weight)
	{

	}
	void sleep()
	{
		cout << "I am sleeping..." << endl;
	}
};

class Sofa: virtual public Furniture{
public:
	Sofa(int weight):Furniture(weight)
	{

	}
	void Watch()
	{
		cout << "I am watching TV..." << endl;
	}
};

class SofaBed: public Bed, public Sofa
{
public:
	SofaBed(int we):Bed(we), Sofa(we), Furniture(we)
	{
		weight_ = we;
		cout << "SofaBed ..." << endl;
		FoldIn();
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
	SofaBed sb(300);
	sb.weight = 200;
	sb.sleep();
	sb.Watch();
	sb.FoldOut();
	sb.FoldIn();
	cout << "Sofa " << sb.weight << endl;

	cout << sizeof(Bed) << endl;
	cout << sizeof(Sofa) << endl;
	cout << sizeof(SofaBed) << endl;
	return 0;
}




