#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<string> text;
	static int i = 0;
	string word;

	cout << "vector size: " << text.size()<< endl;
	while(i++ < 5 && cin >> word)
	{
		text.push_back(word);
	}

	cout << "words read are: \n";

	for( i = 0; i < text.size(); i++)
	{
		cout << text[i] << ' ';
	}

	cout << endl;

	cout << "vector size: " << text.size()<< endl;

}
