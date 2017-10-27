#include <iostream>
#include <sstream>

using namespace std;

string doubleToString(double val)
{
	ostringstream oss;
	oss<<val;

	return oss.str();
}

double stringToDouble(const string& str)
{
	istringstream iss(str);
	double val;
	iss >> val;

	return val;
}

int main(void)
{
	double val = 55.55;
	string str = doubleToString(val);

	cout << str << endl;

	str = "123.123";
	val = stringToDouble(str);
	cout << val << endl;
	return 0;
}



