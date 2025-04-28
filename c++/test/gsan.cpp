#include <iostream>
#include <vector>

std::vector<int> createVector() {
    return std::vector<int>{1, 2, 3, 4, 5};
}
int main() {
    const std::vector<int>& vec = createVector(); // no use-after-free
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    const auto& val = createVector().back(); // Use-after-free
    std::cout << "Last value: " << val << std::endl;
    return 0;
}