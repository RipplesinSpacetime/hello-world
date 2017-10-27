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
	~Student()
	{
		cout << "Destructor called." << endl;
	}

protected:
	int num;
	string name;

};


int main()
{
	Student stud1(10010, "Li");
	stud1.display();

	//Student *ptr = new Student(10011, "Lisa");
	Student *ptr;
	ptr = new Student(10011, "Lisa");

	ptr->display();

	delete ptr;

	return 0;
}








