#include <iostream>

using namespace std;

int main()
{
	int i = 0;
	string str = "netshort";
	string tmp = str.substr(0, 3);

	cout << tmp << endl;
	

	i = tmp.compare("net");
	cout << "i = " << i << endl;

	i = tmp.compare("met");
	cout << "i = " << i << endl;
}
