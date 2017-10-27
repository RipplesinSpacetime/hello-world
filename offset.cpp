#include <iostream>

using namespace std;

class Student{
public:
	int id;
	int ip;
	void set_num(int);
	void set_count(int);
protected:
	int num;
private:
	int count;
};

void Student::set_num(int n)
{
	num = n;
}

void Student::set_count(int c)
{
	count = c;
}

int main()
{
	Student st;
	Student *p;

	p = &st;
	st.id = 10;
	st.ip = 11;

	st.set_num(12);
	st.set_count(13);
	cout << "ip: " << *(&(p->id) + 0) << endl;
	cout << "ip: " << *(&(p->id) + 1) << endl;
	cout << "ip: " << *(&(p->id) + 2) << endl;
	cout << "ip: " << *(&(p->id) + 3) << endl;

	cout << "sizeof(Student): " << sizeof(Student) << endl;
	cout << "sizeof(int): " << sizeof(int) << endl;
	//cout << "&num: " << &(p.num) << endl;
	//cout << "&sex: " << &(p.sex) << endl;

	return 0;
}





