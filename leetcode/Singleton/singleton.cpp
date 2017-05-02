// #include <iostream>
// using namespace std;
// class ASingleton
// {
// public:
// 	static ASingleton* getInstance()
// 	{
// 		return &m_data;
// 	}
// 	void do_something()
// 	{
// 		cout<<"ASingleton do_something!"<<endl;
// 	}
// protected:
// 	static ASingleton m_data; //static data member 在类中声明，在类外定义
// 	ASingleton();
// 	~ASingleton() {}
// };
// 
// class BSingleton
// {
// public:
// 	static BSingleton* getInstance()
// 	{
// 		return &m_data;
// 	}
// 	void do_something()
// 	{
// 		cout<<"BSingleton do_something!"<<endl;
// 	}
// protected:
// 	static BSingleton m_data; //static data member 在类中声明，在类外定义
// 	BSingleton();
// 	~BSingleton() {}
// };
// BSingleton BSingleton::m_data;
// ASingleton ASingleton::m_data;
// 
// 
// ASingleton::ASingleton()
// {
// 	cout<<"ASingleton constructor!"<<endl;
// 	BSingleton::getInstance()->do_something();
// }
// 
// BSingleton::BSingleton()
// {
// 	cout<<"BSingleton constructor!"<<endl;
// }
// 
// int main()
// {
// 	return 1;
// }

#include <iostream>
using namespace std;
class Singleton
{
public:
	static Singleton* getInstance()
	{
		static Singleton _singleton;
		cout << "Singleton got" << endl;
		return &_singleton;
	}
protected:
	struct ObjectConstructor
	{
		ObjectConstructor()
		{
			getInstance();
		}
	};
	static ObjectConstructor _object_constructor;
	Singleton(){};
	~Singleton(){};
};

Singleton::ObjectConstructor Singleton::_object_constructor;

int main()
{
	return 0;
}