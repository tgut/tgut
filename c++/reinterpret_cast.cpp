#include <iostream>
using namespace std;

int main() {
    int num = 10;
    int* ptr = &num;

    // 将 int* 转换为 char*，并输出指针指向的值
    char* cptr = reinterpret_cast<char*>(ptr);
    cout<<"here begin."<<endl;
    cout << *cptr << endl;

    return 0;
}
