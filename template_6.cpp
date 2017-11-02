#include <iostream>
#include <exception>

using namespace std;

template <typename T, int MAX_SIZE>

class Stack
{
public:
	Stack();
	~Stack();

	void Push(const T& elem);
	void Pop();
	T& Top();
	const T& Top() const;
	bool Empty() const;

private:
	T* elems_;
	int top_;
};

template <typename T, int MAX_SIZE>
Stack<T, MAX_SIZE>::Stack() : top_(-1)
{
	elems_ = new T[MAX_SIZE];
}

template <typename T, int MAX_SIZE>
Stack<T, MAX_SIZE>::~Stack()
{
	delete[] elems_;
}

template <typename T, int MAX_SIZE>
void Stack<T, MAX_SIZE>::Push(const T& elem)
{
	if(top_ + 1 >= MAX_SIZE)
		cout <<"Stack<>Push() stack full" << endl;;
	else
		elems_[++top_] = elem;
	
}

template <typename T, int MAX_SIZE>
void Stack<T, MAX_SIZE>::Pop()
{
	if(top_ + 1 <= 0)
		cout <<"Stack<>Push() stack full" << endl;;
	--top_;
}

template <typename T, int MAX_SIZE>
T& Stack<T, MAX_SIZE>::Top() 
{
	if(top_ + 1 == 0)
		cout <<"Stack<>Push() stack full" << endl;;
	return elems_[top_];
}

template <typename T, int MAX_SIZE>
const T& Stack<T, MAX_SIZE>::Top() const
{
	if(top_ + 1 == 0)
		cout <<"Stack<>Push() stack full" << endl;;
	return elems_[top_];
}

template <typename T, int MAX_SIZE>
bool Stack<T, MAX_SIZE>::Empty() const
{
	return (top_ + 1 == 0);
}


int main(void)
{
	Stack<int, 10> s;
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






