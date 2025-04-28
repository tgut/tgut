#include <iostream>
#include <cstring>
class string
{
public:
    string(char *s)
    {
        m_str = s;
    }

    string(){};

    string &operator=(string s)
    {
        if (strlen(m_str) != strlen(s.m_str))
        {
            m_str = new char[strlen(s.m_str) + 1];
        }

        if (*this != (s))
        {
            strcpy(m_str, s.m_str);
        }

        return *this;
    }

private:
    char *m_str;
};

int main()
{
    string s1("abc");
    string s2;
    s2 = s1;
    std::cout << s2.m_str;
}