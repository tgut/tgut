#include <type_traits>
#include <iostream>

// 主模板
template<typename T>
struct is_pointer : std::false_type {};

// 特化模板
template<typename T>
struct is_pointer<T*> : std::true_type {};



int main() {
    std::cout << std::boolalpha;
    std::cout << "is_pointer<float*>::value: " << is_pointer<float*>::value << std::endl; // false
    std::cout << "is_pointer<int*>::value: " << is_pointer<int*>::value << std::endl; // true
    return 0;
}