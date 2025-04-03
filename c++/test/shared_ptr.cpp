#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> sp;
    std::cout << "shared_ptr size: " << sizeof(sp) << " bytes\n";//8
    return 0;
}