/**************************************************
 *
 * pratice to use github...2017-10-26
 *
 **************************************************/
#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	map<int, string> mapStudent;

	mapStudent.insert(pair<int, string>(1, "Student_1"));

	mapStudent.insert(pair<int, string>(2, "Student_2"));

	mapStudent.insert(pair<int, string>(3, "Student_3"));

	map<int, string>::iterator iter;

	for(iter = mapStudent.begin(); iter != mapStudent.end(); ++iter)
	{
		cout<<iter->first << ' ' << iter->second << endl;
	}
}
