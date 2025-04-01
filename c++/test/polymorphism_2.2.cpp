//https://blog.csdn.net/weixin_67596609/article/details/131839669?sharetype=blog&shareId=131839669&sharerefer=APP&sharesource=intellectualman&sharefrom=link
#include <iostream>
using namespace std;
class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
};
class Student : public Person {
public:
	virtual void BuyTicket() { cout << "买票-半价" << endl; }
};
void Func(Person* p)
{
	p->BuyTicket();
}
int main()
{
	Person Mike;
	Func(&Mike);
	Student Johnson;
	Func(&Johnson);
	return 0;
}