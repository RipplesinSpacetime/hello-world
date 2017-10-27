#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	Student(int n, string nam)
	{
		num = n;
		name = nam;
	}
	void display()
	{
		cout << "num: " << num << endl;
		cout << "name: "<< name << endl;
	}

	static void show()
	{
		cout << "hello,world" << endl;
	}

protected:
	int num;
	string name;

};


int main()
{
	Student stud1(10010, "Li");
	stud1.display();

#if 1
	Student *ptr = new Student(10011, "Lisa");
#else
	Student *ptr;
	ptr = new Student(10011, "Lisa");
#endif

	ptr->display();
	ptr->show();

	delete ptr;

	int *p = new int(1024);

	cout << *p << endl;

	p = new int[1024];

	cout << *p << endl;

	return 0;
}








