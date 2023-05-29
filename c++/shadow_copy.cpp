#include <iostream>
// #include <string>
#include <cstring>

using namespace std;
class string
{
public:
    string(char *s)
    {
        m_str = s;
    }

    string(){};

    string &operator=(const string s)
    {
        m_str = s.m_str;
        return *this
    }

private:
    char *m_str;
};

int main()
{
    string s1("abc");
    string s2;
    s2 = s1;
    cout << s2.m_str;
}