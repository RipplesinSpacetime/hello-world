#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	map<int, string> mapStudent;

	mapStudent[0] = "student_0";
	mapStudent[2] = "student_2";
	mapStudent[3] = "student_3";

	map<int, string>::iterator iter;

	for(iter = mapStudent.begin(); iter != mapStudent.end(); ++iter)
	{
		cout<<iter->first << ' ' << iter->second << endl;
	}
}
