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
	ptest->setStr("hello ");
	cout << "ptest->print: ";
	ptest->print();

	cout << "ptest.get()->print: ";
	ptest.get()->print();
	ptest->getStr() += "world !";

	cout << "(*ptest).print: ";
	(*ptest).print();

	cout << "ptest->print: ";
	ptest->print();

	ptest.reset(new Test("123"));
	cout << "ptest->print: ";
	ptest->print();

	return 0;
}




