#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int i;
	vector< int > text(20, 6);
	vector< int >::iterator it;

	cout << "words read are: \n";
	cout << "vector size: " << text.size()<<endl;

	for( it = text.begin(); it != text.end(); it++)
	{
		cout << *it << ' ';
	}

	cout << "\ninsert 7\n";
	text.insert(text.begin(), 7);
	cout << "words read are: \n";
	cout << "vector size: " << text.size()<<endl;

	for( it = text.begin(); it != text.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
	cout << "vector erase" << endl;

	text.erase(text.begin() + 6, text.end());

	for( it = text.begin(); it != text.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
	cout << "vector size: " << text.size()<<endl;
	cout << "vector capacity: " << text.capacity();
	cout << endl;

	text.clear();
}
