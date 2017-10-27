#include <iostream>
#include <memory>

using namespace std;

class Test{
public:
	Test(string s)
	{
		str = s;
		cout<<"Test creat" << endl;
	}
	~Test()
	{
		cout <<"Test delete: "<< str << endl;
	}
	string& getStr()
	{
		return str;
	}
	void setStr(string s)
	{
		str = s;
	}
	void print()
	{
		cout << str << endl;
	}

private:
	string str;
};

int main(void)
{
	auto_ptr<Test> ptest(new Test("123"));
	auto_ptr<Test> ptest2(new Test("456"));

	ptest2 = ptest;

	cout << "ptest2->print: ";
	ptest2->print();

	if(ptest.get() == NULL)
	{
		cout<< "ptest = NULL " << endl;
	}

	return 0;
}




