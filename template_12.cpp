#include <iostream>
#include <memory>
#include <cstdlib>

using namespace std;

template <typename T>

class Singleton
{
public:
	static T& GetInstance()
	{
		Init();
		return *instance_;
	}

private:
	static void Init()
	{
		if(instance_ == 0);
		{
			instance_ = new T;
			atexit(Destory);
		}
	}
	static void Destory()
	{
		delete instance_;
	}
	Singleton(const Singleton& other);
	Singleton& operator= (const Singleton& other);
	Singleton();
	~Singleton();

	static T* instance_;
};

template <typename T>
T* Singleton<T>::instance_ = 0;
class ApplicationImp
{
public:
	ApplicationImp()
	{
		cout << "Application ... "<<endl;
	}
	~ApplicationImp()
	{
		cout << "~Application ... "<<endl;
	}
	void Run()
	{
		cout << "Run ... "<<endl;
	}
};

typedef Singleton<ApplicationImp> Application;

int main(void)
{
	Application::GetInstance().Run();
	Application::GetInstance().Run();

	return 0;
}




