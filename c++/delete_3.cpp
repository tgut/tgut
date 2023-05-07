template<typename T>
void foo();

// 删除 foo<int> 特化
template<>
void foo<int>() = delete;
