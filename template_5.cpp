#include <iostream>
#include <exception>

using namespace std;

template <typename T>

class Stack
{
public:
	explicit Stack(int maxSize);
	~Stack();

	void Push(const T& elem);
	void Pop();
	T& Top();
	const T& Top() const;
	bool Empty() const;

private:
	T* elems_;
	int maxSize_;
	int top_;
};

template <typename T>
Stack<T>::Stack(int maxSize) : maxSize_(maxSize), top_(-1)
{
	elems_ = new T[maxSize];
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] elems_;
}

template <typename T>
void Stack<T>::Push(const T& elem)
{
	if(top_ + 1 >= maxSize_)
	{
		cout <<"Stack<>Push() stack full" << endl;;
	}
	elems_[++top_] = elem;
	
}

template <typename T>
void Stack<T>::Pop()
{
	if(top_ + 1 <= 0)
		cout <<"Stack<>Push() stack full" << endl;;
	--top_;
}

template <typename T>
T& Stack<T>::Top()
{
	if(top_ + 1 == 0)
		cout <<"Stack<>Push() stack full" << endl;;
	return elems_[top_];
}

template <typename T>
const T& Stack<T>::Top() const
{
	if(top_ + 1 == 0)
		cout <<"Stack<>Push() stack full" << endl;;
	return elems_[top_];
}

template <typename T>
bool Stack<T>::Empty() const
{
	return (top_ + 1 == 0);
}


int main(void)
{
	Stack<int> s(10);
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






