#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
	char ch;

	ifstream fin("test6.txt");
	assert(fin);
	fin.seekg(2);
	fin.get(ch);
	cout << ch << endl;

	fin.seekg(-2, ios::end);
	fin.get(ch);
	cout<< ch << endl;

	streampos pos = fin.tellg();
	cout << pos << endl;
	fin.close();

	return 0;
}
