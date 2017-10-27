#include <iostream>
using namespace std;

#define sizeof_v(x) (char*)(&x+1) - (char*)(&x)

#define sizeof_t(t) (size_t((t*)0 + 1))

#define ALIGN(v, b) ((v+b-1) & ~(b-1))
#define ALIGN_M(v, b) ((v<b||v==b)?b:b*2)

class Empty
{
public:
};

int main(void)
{
	Empty e;
	int i;

	cout<<sizeof_v(e)<< endl;
	cout<<sizeof_v(i)<< endl;

	cout<<sizeof_t(Empty)<< endl;
	cout<<sizeof_t(int)<< endl;

	cout<<ALIGN(0, 16) << endl;
	cout<<ALIGN(3, 16) << endl;
	cout<<ALIGN(15, 16) << endl;
	cout<<ALIGN(17, 16) << endl;

	cout<<ALIGN(1023, 1024) << endl;
	cout<<ALIGN(1025, 1024) << endl;

	cout<<ALIGN_M(1023, 1024) << endl;
	cout<<ALIGN_M(1024, 1024) << endl;
	cout<<ALIGN_M(1025, 1024) << endl;

	return 0;
}




