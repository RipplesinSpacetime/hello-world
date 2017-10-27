#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	//system("chcp 936"); 
	int n = 64;
	double d = 123.5;
	double d2 = 0.0187;

	cout <<"===================宽度控制=============="<<endl;
	cout<<n<<'#'<<endl;
	cout<<setw(10)<<n<<'#'<<endl;
	cout.width(10);
	cout<<n<<'#'<<endl;

	cout <<"===================对齐控制=============="<<endl;
	cout<<setw(10)<<setiosflags(ios::left)<<n<<'#'<<endl;

	cout<<setw(10)<<setiosflags(ios::right)<<n<<'#'<<endl;

	cout <<"===================填充控制=============="<<endl;
	cout<<setw(10)<<setfill('?')<<n<<'#'<<endl;
	cout<<setw(10)<<n<<'#'<<endl;
	cout<<setw(10)<<setfill(' ')<<n<<'#'<<endl;

	cout <<"===================精度控制=============="<<endl;
	cout<<setprecision(4)<<d<<endl;
	cout<<setprecision(2)<<d<<endl;

	cout<<setiosflags(ios::fixed);
	cout<<setprecision(4)<<d<<endl;
	cout<<setprecision(2)<<d<<endl;

	cout <<"===================进制输出=============="<<endl;
	cout<<n<<endl;
	cout<<oct<<n<<endl;
	cout<<hex<<n<<endl;
	cout<<resetiosflags(ios::dec)<<n<<endl;
	cout<<setiosflags(ios::oct)<<n<<endl;
	cout<<setiosflags(ios::hex)<<n<<endl;

	cout<<endl;
	cout<<setbase(10)<<n<<endl;
	cout<<setbase(8)<<n<<endl;
	cout<<setbase(16)<<n<<endl;

	return 0;
}
