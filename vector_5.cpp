#include <vector>
#include <algorithm> 
#include <iostream> 
using namespace std; 
int ia[10] = {51, 23, 7, 88, 41, 98, 12, 103, 37, 6}; 
int main() 
{ 
	vector< int > vec(ia, ia + 10); 

	vector<int> ::iterator found;
	for(found = vec.begin(); found != vec.end(); found++)
	{
		cout << "found = "  << *found << endl;
	}

	sort(vec.begin(), vec.end()); 

	cout << "************after sort:" << endl;
	for(found = vec.begin(); found != vec.end(); found++)
	{
		cout << "found = "  << *found << endl;
	}

	int search_value;
	cout << "Please input the value you want to search" << endl;
	cin >> search_value;

	cout << "search_value = " << search_value << endl;
	found = find(vec.begin(), vec.end(), search_value);
	if(found != vec.end())
	{
		cout << "search_value found"<< endl;
	}
	else
	{
		cout << "search_value not found" << endl;
	}

	reverse(vec.begin(), vec.end());

	cout << "************after reverse:" << endl;
	for(found = vec.begin(); found != vec.end(); found++)
	{
		cout << "found = "  << *found << endl;
	}

}
