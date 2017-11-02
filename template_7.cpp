#include <iostream>
#include <exception>
#include <deque>
#include <vector>

using namespace std;

template <typename T, typename CONT = deque<T> >

class Stack
{
public:
	Stack():c_()
	{
	}
	~Stack()
	{
	}
	void Push(const T& elem)
	{
		c_.push_back(elem);
	}
	void Pop()
	{
		c_.pop_back();
	}
	T& Top()
	{
		return c_.back();
	}
	const T& Top() const
	{
		return c_.back();
	}
	bool Empty() const
	{
		return c_.empty();
	}

private:
	CONT c_;
	int top_;
};


int main(void)
{
	//Stack<int> s;
	Stack<int, vector<int> > s;
	s.Push(1);
	s.Push(2);
	s.Push(3);

	while(!s.Empty())
	{
		cout<<s.Top()<<endl;
		s.Pop();
	}
	return 0;
}






