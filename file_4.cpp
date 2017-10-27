#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Test
{
	int a;
	int b;
};

int main(void)
{
	Test test = {100, 200};

	ofstream fout("test4.txt");
	//fout.write(reinterpret_cast<char*>(&test), sizeof(Test));
	fout.write((char*)(&test), sizeof(Test));
	fout.close();

	Test test2;
	ifstream fin("test4.txt", ios::in | ios::binary);
	//fin.read(reinterpret_cast<char*>(&test2), sizeof(Test));
	fin.read((char*)(&test2), sizeof(Test));
	cout<< test2.a <<" "<< test2.b<<endl;

	return 0;
}	
