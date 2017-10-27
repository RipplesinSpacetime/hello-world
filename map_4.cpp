#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	map<int, string> mapStudent;

	pair<map<int, string>::iterator,  bool> Insert_Pair;


	Insert_Pair = mapStudent.insert(map<int, string>::value_type (1, "Student_1"));
	if(Insert_Pair.second == true)
		cout << "Insert sucessfully." << endl;
	else
		cout << "Insert fail." << endl;

	Insert_Pair = mapStudent.insert(map<int, string>::value_type (2, "Student_2"));
	if(Insert_Pair.second == true)
		cout << "Insert sucessfully." << endl;
	else
		cout << "Insert fail." << endl;

	Insert_Pair = mapStudent.insert(map<int, string>::value_type (3, "Student_3"));
	if(Insert_Pair.second == true)
		cout << "Insert sucessfully." << endl;
	else
		cout << "Insert fail." << endl;

	map<int, string>::iterator iter;

	for(iter = mapStudent.begin(); iter != mapStudent.end(); ++iter)
	{
		cout<<iter->first << ' ' << iter->second << endl;
	}

	cout << "mapStudent size: " << mapStudent.size()<<endl;
}
