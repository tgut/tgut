#include <iostream>
using namespace std;
class Person {
public:
	 virtual ~Person() { cout << "~Person()" << endl; }
};
class Student : public Person {
public:
	virtual ~Student() { cout << "~Student()" << endl; }
};
 
int main()
{
	Person* p1 = new Person;
	Person* p2 = new Student;
 
	delete p1;
	delete p2;
	return 0;
}