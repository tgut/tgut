//极客时间SFINAE 章节代码
template <typename C, typename T>
void _append(C& container, T* ptr,
             size_t size,
             true_type)
{
  container.reserve(
    container.size() + size);
  for (size_t i = 0; i < size;
       ++i) {
    container.push_back(ptr[i]);
  }
}

template <typename C, typename T>
void _append(C& container, T* ptr,
             size_t size,
             false_type)
{
  for (size_t i = 0; i < size;
       ++i) {
    container.push_back(ptr[i]);
  }
}

template <typename C, typename T>
void append(C& container, T* ptr,
            size_t size)
{
  _append(
    container, ptr, size,
    integral_constant<
      bool,
      has_reserve<C>::value>{});
}

//cppreference.com中void_t中的示例代码

// 主模板处理无嵌套 ::type 成员的类型：
template< class, class = void >
struct has_type_member : std::false_type { };
 
// 特化识别拥有嵌套 ::type 成员的类型：
template< class T >
struct has_type_member<T, std::void_t<typename T::type>> : std::true_type { };