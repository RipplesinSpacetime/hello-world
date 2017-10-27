#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char c;
	int i = 255;
	ofstream outfile;
	ifstream infile;

	outfile.open("test.txt");
	outfile << "Hello, world!";
	outfile << "ZF,73 ";
	outfile << i;


	outfile.close();

	infile.open("test.txt");
	while(!infile.eof())
	{
		infile >> c;
		cout<< c;
	}

	cout << endl;
}

