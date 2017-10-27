#include <map>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
	map<int, string> mapStudent;

	pair<map<int, string>::iterator,  bool> Insert_Pair;

	int index;
	for(index = 0; index < 10; index++)
	{
		char buf[16];
		sprintf(buf, "%s%d", "Student_", index);
		Insert_Pair = mapStudent.insert(map<int, string>::value_type (index, buf));
		if(Insert_Pair.second == true)
			cout << "Insert sucessfully." << endl;
		else
			cout << "Insert fail." << endl;
	}

	cout << "*****************************************" << endl;
	for(index = 0; index < mapStudent.size(); index++)
	{
		cout<<mapStudent[index] << endl;
	}

	cout << "mapStudent size: " << mapStudent.size()<<endl;

	map<int, string>::iterator ite;
	ite = mapStudent.find(1);
	mapStudent.erase(ite);
	if(ite != mapStudent.end())
	{	
		cout << "Find " << endl;
	}
	else
	{
		cout << "Not find" << endl;
	}
	cout << "*after erase 1*********************************" << endl;
	for(index = 0; index < mapStudent.size(); index++)
	{
		cout<<mapStudent[index] << endl;
	}
	

	ite = mapStudent.lower_bound(0);
	cout << ite->first << endl;
	cout << ite->second << endl;

	ite = mapStudent.upper_bound(8);
	cout << ite->first << endl;
	cout << ite->second << endl;
}



