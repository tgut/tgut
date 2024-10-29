/*
 * @Descripttion: 
 * @version: 
 * @Author: tgut
 * @Date: 2024-08-02 09:55:31
 * @LastEditors: tgut
 * @LastEditTime: 2024-08-02 09:55:37
 */
#include <iostream>
using namespace std;
template <typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << '\n'; // C++17 折叠表达式
}

int main(){
    print(1, 2, 3, "Hello", 4.5);
    return 0;
}