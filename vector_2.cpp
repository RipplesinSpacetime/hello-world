#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int i;
	int tmp[] = {-1, 0, 1, 2, 3, 4};
	vector< int > invc_2(tmp+1, tmp+2);
	vector< int > invc;

	invc = invc_2;

	cout << "vector size: " << invc.size()<< endl;

	for( i = 0; i < invc.size(); i++)
	{
		cout << invc[i] << ' ';
	}

	cout << endl;
}
