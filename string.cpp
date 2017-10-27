#include <iostream>

using namespace std;

int main()
{
	string str = "";
	string tmp = "";
	char buff[16] ;

	str.append(1, 'h');
	str.append(1, 'e');
	str.append(buff, 15);

	cout << "hello" << endl;
	cout << str.size() << endl;
	cout << str << endl;

	tmp.append(str);
	cout << tmp << endl;

	string string1 = "hello";
	string1.erase(1, 1);
	cout << string1.size()<< "  "<<string1<<string1[0];
	cout << endl;

	tmp = "hello, world";
	int i = 0x4d;
	string *pstr = &str;
	str.clear();
	str += char(i);
	str += tmp;

	cout << "***********" << endl;
	cout << str << endl;

	string str1, str2;
	cin >> str1 >> str2;
	cout << str1 << endl;
	cout << str2 << endl;
}
