

```markdown
# GCC 源码中  STL 与六大组件学习计划

**目标**：通过分析 GCC 的 `libstdc++` 源码，深入理解 STL 原理及六大组件（容器/算法/迭代器/仿函数/适配器/分配器），每日投入 **30 分钟** 编码实践。

---

## 一、环境准备（1-2 天）

### 1. 源码获取与定位
```bash
git clone git://gcc.gnu.org/git/gcc.git
cd gcc/libstdc++-v3  # STL 实现核心目录
```

### 2. 关键文件路径
| 目录/文件                     | 说明                     |
|------------------------------|-------------------------|
| `include/bits/`              | STL 容器实现（vector、list 等） |
| `include/ext/`               | 扩展组件（如 rope、mt_alloc）  |
| `src/c++98/`                 | 传统组件实现（如 ios、locale） |
| `testsuite/`                 | 官方测试用例               |

---

## 二、分阶段学习路径

### 阶段 1：容器实现原理（7 天）
#### 学习目标
- 理解内存管理、迭代器设计、异常安全机制

#### 源码分析
```cpp
// 分析 vector 核心实现
// 文件：include/bits/stl_vector.h
template<typename _Tp, typename _Alloc = std::allocator<_Tp>>
class vector {
protected:
  pointer _M_start;      // 内存起始位置
  pointer _M_finish;     // 最后一个元素后位置
  pointer _M_end_of_storage; // 内存块末尾
};
```

#### 每日编码任务
- **Day 1-3**：实现简化版 `vector`（支持 push_back/迭代器）
- **Day 4-7**：实现 `list`（节点内存分配、双向迭代器）

```cpp
// 示例：简化 vector 实现
template<typename T>
class MyVector {
private:
    T* _data;
    size_t _size;
    size_t _capacity;
public:
    void push_back(const T& val) {
        if (_size == _capacity) 
            reserve(_capacity * 2 + 1);
        _data[_size++] = val;
    }
};
```

---

### 阶段 2：算法与迭代器（5 天）
#### 学习目标
- 理解泛型算法设计、迭代器分类（input/forward/bidirectional/random_access）

#### 源码分析
```cpp
// 分析 sort 算法实现
// 文件：include/bits/stl_algo.h
template<typename _RandomAccessIterator>
void sort(_RandomAccessIterator __first, _RandomAccessIterator __last) {
  // 内省排序（快速排序+堆排序混合）
  std::__introsort_loop(__first, __last, std::__lg(__last - __first) * 2);
  std::__final_insertion_sort(__first, __last);
}
```

#### 每日编码任务
- **Day 1-2**：实现 `find`/`count` 算法（支持自定义迭代器）
- **Day 3-5**：实现 `reverse_iterator` 适配器

```cpp
template<typename Iterator>
class ReverseIterator {
private:
    Iterator _current;
public:
    ReverseIterator(Iterator it) : _current(it) {}
    auto operator*() { auto tmp = _current; return *--tmp; }
};
```

---

### 阶段 3：分配器与适配器（5 天）
#### 学习目标
- 理解内存池设计、容器适配器（stack/queue）实现

#### 源码分析
```cpp
// 分析 std::allocator 核心逻辑
// 文件：include/bits/allocator.h
template<typename _Tp>
class allocator {
public:
    pointer allocate(size_type __n) {
        return static_cast<_Tp*>(::operator new(__n * sizeof(_Tp)));
    }
    void deallocate(pointer __p, size_type) { ::operator delete(__p); }
};
```

#### 每日编码任务
- **Day 1-3**：实现内存池分配器（固定块大小）
- **Day 4-5**：基于 `deque` 实现 `stack` 适配器

```cpp
template<typename T, typename Container = deque<T>>
class MyStack {
protected:
    Container c;
public:
    void push(const T& val) { c.push_back(val); }
    void pop() { c.pop_back(); }
};
```

---

## 三、工具与调试技巧

### 1. 源码调试
```bash
# 查看 STL 容器内存布局
g++ -g test.cpp -o test
gdb --args ./test
(gdb) p *(std::vector<int>*)0x7fffffffdca0
```

### 2. 可视化工具
```bash
# 生成类继承图
doxygen -g && doxygen  # 生成文档包含继承图
```

---

## 四、每日30分钟编码模板

### 周一/三/五：源码分析日
1. 选择 1 个 STL 组件（如 `unordered_map`）
2. 使用 `ctags` 跳转关键函数（如 `_M_rehash`）
3. 记录该组件的 **3 个设计特点**

### 周二/四/六：编码实践日
1. 实现简化版 STL 组件（如 `priority_queue`）
2. 编写对应单元测试（如验证堆性质）
```cpp
TEST(PriorityQueueTest, PushPopOrder) {
    MyPriorityQueue<int> q;
    q.push(3); q.push(1); q.push(4);
    ASSERT_EQ(q.top(), 4);
}
```

---

## 五、关键学习资源
1. [GCC libstdc++ 文档](https://gcc.gnu.org/onlinedocs/libstdc++/)
2. 《STL 源码剖析》- 侯捷（对照 GCC 4.9 源码）
3. [CppCon 编译器相关演讲](https://www.youtube.com/CppCon)

---

**核心原则**：通过 **"源码阅读 → 简化实现 → 对比优化"** 的循环，将底层机制与编码实践深度结合，逐步构建对 STL 的体系化认知。
```