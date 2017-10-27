#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	//ofstream fout("test3.txt");
	ofstream fout("test3.txt", ios::out | ios::binary);

	fout<<"ABC";
	fout.close();

	return 0;
}
