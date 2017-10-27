#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	map<int, string> mapStudent;

	mapStudent.insert(map<int, string>::value_type (1, "Student_1"));

	mapStudent.insert(map<int, string>::value_type (2, "Student_2"));

	mapStudent.insert(map<int, string>::value_type (3, "Student_3"));

	map<int, string>::iterator iter;

	for(iter = mapStudent.begin(); iter != mapStudent.end(); ++iter)
	{
		cout<<iter->first << ' ' << iter->second << endl;
	}
}



