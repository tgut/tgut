#include <iostream>
#include <string>
using namespace std;
template <class T1,class T2>
class Pair
{
public:
    T1 key;  //关键字
    T2 value;  //值
    Pair(T1 k,T2 v):key(k),value(v) { };
    bool operator < (const Pair<T1,T2> & p) const;
};
template<class T1,class T2>
bool Pair<T1,T2>::operator < (const Pair<T1,T2> & p) const
//Pair的成员函数 operator <
{ //"小"的意思就是关键字小
    return key < p.key;
}
int main()
{
    Pair<string,int> student("Tom",19); //实例化出一个类 Pair<string,int>
    Pair<string,int> student2("Herry",20);
    cout << student.key << " " << student.value<<endl;
    cout<<"student < student2 is "<<(student<student2)<<endl;
    return 0;
}