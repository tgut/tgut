//极客时间SFINAE 章节代码
template <typename C, typename T>
enable_if_t<has_reserve<C>::value,
            void>
append(C& container, T* ptr,
       size_t size)
{
  container.reserve(
    container.size() + size);
  for (size_t i = 0; i < size;
       ++i) {
    container.push_back(ptr[i]);
  }
}

template <typename C, typename T>
enable_if_t<!has_reserve<C>::value,
            void>
append(C& container, T* ptr,
       size_t size)
{
  for (size_t i = 0; i < size;
       ++i) {
    container.push_back(ptr[i]);
  }
}


//enable_if网站示例代码
/* 错误 */
 
struct T
{
    enum { int_t, float_t } type;
 
    template<typename Integer,
             typename = std::enable_if_t<std::is_integral<Integer>::value>>
    T(Integer) : type(int_t) {}
 
    template<typename Floating,
             typename = std::enable_if_t<std::is_floating_point<Floating>::value>>
    T(Floating) : m_type(float_t) {} // 错误：被当做重复定义
};
 
/* 正确 */
 
struct T
{
    enum { int_t, float_t } type;
 
    template<typename Integer,
             std::enable_if_t<std::is_integral<Integer>::value, bool> = true>
    T(Integer) : type(int_t) {}
 
    template<typename Floating,
             std::enable_if_t<std::is_floating_point<Floating>::value, bool> = true>
    T(Floating) : type(float_t) {} // OK
};