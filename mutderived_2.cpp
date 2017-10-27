#include <iostream>

using namespace std;

class Furniture{
public:
	#if 0
	Furniture(int wei):weight(wei)
	{

	}
	#endif
	int weight;
};

class Bed: virtual public Furniture{
public:
	#if 0
	Bed(int weight):Furniture(weight)
	{

	}
	#endif
	void sleep()
	{
		cout << "I am sleeping..." << endl;
	}
};

class Sofa: virtual public Furniture{
public:
	#if 0
	Sofa(int weight):Furniture(weight)
	{

	}
	#endif
	void Watch()
	{
		cout << "I am watching TV..." << endl;
	}
};

class SofaBed: public Bed, public Sofa
{
public:
	#if 0
	SofaBed():Bed(200), Sofa(100)
	{

	}
	#endif
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




