#include <iostream>
using namespace std;

double Divide(double a, double b)
{
	if(b == 0.0)
	{
		throw 1;
	}
	else
	{
		return a / b;
	}
}

int main ()
{
	try
	{
		cout << "Dividing ..." << endl;;
		cout << Divide(5.0, 1.0) << endl;;
		cout << Divide(5.0, 0.0) << endl;;
		cout << Divide(5.0, 2.0) << endl;;
	}
	catch(int)
	{
		cout << "Division by zero "<< endl;
	}
   	return 0;
}



