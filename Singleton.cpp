#include <iostream>
#include <memory>

using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		#if 0
		if(instance_ == NULL)
		{
			instance_ = new Singleton;
		}
		return instance_;
		#endif

		if(!instance_.get())
		{
			instance_ = auto_ptr<Singleton>(new Singleton);
		}

		return instance_.get();
	}

	~Singleton()
	{
		cout <<"~Singleton..." << endl;
	}

private:
	Singleton(const Singleton& other);
	Singleton& operator= (const Singleton& other);
	Singleton()
	{
		cout<< "Singleton ..." << endl;
	}
	//static Singleton* instance_;
	static auto_ptr<Singleton> instance_;
};

//Singleton* Singleton::instance_;
auto_ptr<Singleton> Singleton::instance_;

int main(void)
{
	Singleton* s1 = Singleton::GetInstance();
	Singleton* s2 = Singleton::GetInstance();

	return 0;
}




