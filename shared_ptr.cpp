#include <boost/shared_ptr.hpp>
#include <iostream>
using namespace std;

class X{
public:
	X()
	{
		cout<<"X..."<<endl;
	}
	~X()
	{
		cout<<"~X..."<<endl;
	}
};

int main(void)
{
	cout<<"Entering main..."<<endl;
	boost::shared_ptr<X> p1(new X);
	cout<<p1.use_count()<<endl; //1
	boost::shared_ptr<X> p2 = p1;
	cout<<p1.use_count()<<endl; //2
	cout<<p2.use_count()<<endl; //2

	p1.reset();
	cout<<p2.use_count()<<endl; //1

	cout<<"Exiting main..."<<endl;
}
