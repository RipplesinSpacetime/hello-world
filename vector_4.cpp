#include "class.h"

int main()
{
	vector < temp > t;
	vector < temp > ::iterator it;

	temp w1, w2;
	w1.str = "Hello,world";
	w1.id = 1;

	w2.str = "Hello,Ming";
	w2.id = 2;

	t.push_back(w1);
	t.push_back(w2);
	
	for(it = t.begin(); it != t.end(); it++)
	{
		cout << it->str << endl;
		cout << it->id << endl;
	}
	
}
