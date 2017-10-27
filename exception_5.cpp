#include <iostream>
#include <string>

using namespace std;

class MyException
{
public:
	MyException(const char* message) : message_(message)
	{
		cout <<"MyException ... " << endl;
	}
	MyException(const MyException& other) : message_(other.message_)
	{
		cout << "Copy MyException ... " << endl;
	}
	~MyException()
	{
		cout << "~MyEexception ... " << endl;
	}
	const char* what() const
	{
		return message_.c_str();
	}
private:
	string message_;
};

double Divide(double a, double b)
{
	if(b == 0.0)
	{
		MyException e("division by zero");
		throw e;
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
		//cout << Divide(5.0, 1.0) << endl;;
		cout << Divide(5.0, 0.0) << endl;;
		//cout << Divide(5.0, 2.0) << endl;;
	}
	catch(MyException& e) 
	{
		cout << e.what()<< endl;
	}
	catch(int)
	{
		cout << "catch a exception ... " << endl;
	}
	catch(double)
	{
		cout << "catch a exception ... " << endl;
	}
   	return 0;
}



