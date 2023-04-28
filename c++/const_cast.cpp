/*
** FileName     : ConstCastDemo
** Author       : Jelly Young
** Date         : 2013/12/27
** Description  : More information, please go to http://www.jellythink.com
*/
#include <iostream>
using namespace std;
class CA
{
public:
     CA():m_iA(10){}
     int m_iA;
};
int main()
{
     const CA *pA = new CA;
     // pA->m_iA = 100; // Error
     CA *pB = const_cast<CA *>(pA);
     pB->m_iA = 100;
     // Now the pA and the pB points to the same object
     cout<<pA->m_iA<<endl;
     cout<<pB->m_iA<<endl;
     const CA &a = *pA;
     // a.m_iA = 200; // Error
     CA &b = const_cast<CA &>(a);
     pB->m_iA = 200;
     // Now the a and the b reference to the same object
     cout<<b.m_iA<<endl;
     cout<<a.m_iA<<endl;
}
