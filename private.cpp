#include <iostream>

using namespace std;

class Student{
public:
	void get_value();
	int get_num();
	void set_num(int);
	void display();
	void set_id(int);
	int get_id();
protected:
	int id;
private:
	int num;
	string name;
	char sex;
};

void Student::get_value()
{
	cout << "Please input num, name and sex:" << endl;
	cin >> num >> name >> sex;
}

void Student::set_num(int number)
{
	num = number;
}

int Student::get_num() 
{
	return num;
}

void Student::set_id(int iid)
{
	id = iid;
}

int Student::get_id()
{
	return id;
}

void Student::display()
{
	cout << "num:  " << num << endl;
	cout << "name: " << name << endl;
	cout << "sex:  " << sex << endl;
	cout << "id:  " << id << endl;
}

class Test{
public:
	Student st;
};

int main()
{
	Student st;
	st.set_num(13);
	cout << "num: " << st.get_num() << endl;

	//st.id = 9;
	st.set_id(15);
	st.get_value();
	st.display();

	Test tt;
	//tt.st.id = 10;
	return 0;
}





