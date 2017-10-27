#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	map<string, int> tmap;

	tmap["aaa"] = 100;
	//tmap["aaa"] = 900;
	
	tmap.insert(map<string, int>::value_type("bbb", 200));

	tmap.insert(pair<string, int>("ccc", 300));
	
	tmap.insert(make_pair("ddd", 400));
	
	map<string, int>::const_iterator it;
	for(it = tmap.begin(); it != tmap.end(); ++it)
	{
		cout << it->first << "    " << it->second << endl;
	}

}









