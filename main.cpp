#include <iostream>
#include "DebugNew.h"

using namespace std;

int main(void)
{
	int *p = new int;
	delete p;

	int *p2 = new int[5];
	delete[] p2;
	return 0;
}
