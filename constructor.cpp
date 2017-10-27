#include <iostream>

using namespace std;

class Time{
public:
	Time();
	#if 0
	{
		hour = 0;
		minute = 0;
		second = 0;
	}
	#endif

	void set_time();
	void show_time();
private:
	int hour;
	int minute;
	int second;
};

Time::Time()
{
	hour = 0;
	minute = 0;
	second = 0;
}

void Time::set_time()
{
	cin >> hour;
	cin >> minute;
	cin >> second;
}

void Time::show_time()
{
	cout << hour <<":"<< minute << ":" << second;
	cout << endl;
}

int main()
{
	Time t1;
	t1.set_time();
	t1.show_time();

	Time t2;
	t2.show_time();

	return 0;
}
