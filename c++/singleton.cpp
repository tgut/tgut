//https://zhuanlan.zhihu.com/p/37469260
#include <iostream>
//eager mode
class Singleton
{
private:
	Singleton() { };
	~Singleton() { };
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
public:
	static Singleton& getInstance() 
        {
		static Singleton instance;
		return instance;
	}
};

// init static member

int main(){
    // printf("start main\n");
	Singleton& data = Singleton::getInstance();
    // Singleton data = a.getInstance();
    Singleton& data2= Singleton::getInstance();
    printf(" data point = %p\n",&data);
    printf(" data2 point = %p\n",&data2);
    return 0;
}