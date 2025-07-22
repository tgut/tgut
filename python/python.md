# 语句
##  python的for循环

```python
#方法一：从0数到9
for i in range(0,10,1):
    print(i)
#输出0～9，回车隔开
#方法二：从0数到9
for i in range(10):
    print(i)
#输出0～9,回车隔开
#方法三：使用enumate

fruits = ["apple", "banana"]
for index, fruit in enumerate(fruits, start=1):
    print(index, fruit)
# 输出：
# 1 apple
# 2 banana
#方法四：使用zip
names = ["Alice", "Bob"]
scores = [90, 85]
```
## python中while循环的用法

```python
x, y = 0, 0
while x < 5 and y < 3:
    print(f"x={x}, y={y}")
    x += 1
    y += 1
# 输出：x=0,y=0 → x=1,y=1 → x=2,y=2
```

# 数据结构
## 基础数据结构

### 1. 列表（List）
**特点**：有序、可变、允许重复元素

**核心操作**：
```python
## 创建与访问
nums = [1, 2, 3]
nums[0]  ## 输出 1
nums[-1]  ## 输出 3

## 修改与增删
nums.append(4)       ## 末尾添加 → [1,2,3,4]
nums.insert(1, 10)   ## 插入 → [1,10,2,3,4]
nums.pop()           ## 移除末尾 → [1,10,2,3]
nums.remove(10)      ## 移除指定值 → [1,2,3]
slice = nums[1:3]    ## 切片 → [2,3]
```

**适用场景**：动态数据集合（如队列、栈）、频繁增删操作。

### 2. 元组（Tuple）
**特点**：有序、不可变、允许重复元素

**核心操作**：
```python
point = (3, 4)
x, y = point        ## 解包 → x=3, y=4
point[0]            ## 输出 3（不可修改）
```

**适用场景**：固定配置项、函数多返回值。

### 3. 字典（Dict）
**特点**：键值对（Key-Value）、键唯一、无序（Python 3.7+保持插入顺序）

**核心操作**：
```python
user = {"name": "Alice", "age": 30}
user["email"] = "alice@example.com"  ## 添加键值对
age = user.get("age", 0)           ## 安全获取（默认值0）
for key, value in user.items():    ## 遍历键值对
    print(f"{key}: {value}")

del user["age"]                    ## 删除键值对
user.update({"city": "NYC"})      ## 批量更新
keys = list(user.keys())          ## 获取所有键
values = list(user.values())      ## 获取所有值
user.pop("name", "Unknown")       ## 删除并返回值（带默认值）
user.setdefault("score", 0)       ## 不存在时设置默认值
user.clear()                      ## 清空字典
new_dict = user.copy()            ## 浅拷贝

```
**适用场景**：快速查找（如JSON数据）、关联数据存储。

### 4. 默认字典（defaultdict）
**特点**：访问不存在的键时，自动创建默认值

**核心操作**：
```python
from collections import defaultdict

# 创建默认字典
dd = defaultdict(int)        # 默认值为0
print(dd['count'])
dd['count'] += 1             # 不存在时自动创建为0，然后+1 → 1

# 其他类型的默认值
dd_list = defaultdict(list)  # 默认值为空列表
dd_list['items'].append(1)   # → {'items': [1]}

dd_set = defaultdict(set)    # 默认值为空集合
dd_set['tags'].add('python') # → {'tags': {'python'}}

# 自定义默认值函数
def default_value():
    return "N/A"
dd_custom = defaultdict(default_value)
print(dd_custom['missing'])  # → "N/A"
```

**适用场景**：分组统计、嵌套数据结构、避免KeyError异常。

**实用示例**：
```python
# 按首字母分组单词
from collections import defaultdict
words = ["apple", "banana", "cherry", "apricot"]
grouped = defaultdict(list)
for word in words:
    grouped[word[0]].append(word)
# → {'a': ['apple', 'apricot'], 'b': ['banana'], 'c': ['cherry']}

# 嵌套字典
nested = defaultdict(lambda: defaultdict(int))
nested['user1']['score'] = 100  # 自动创建嵌套结构
```

### 5. 集合（Set）
**特点**：无序、元素唯一、支持集合运算

**核心操作**：
```python
a = {1,2,3}
b = {3,4,5}
union = a | b          ## 并集 → {1,2,3,4,5}
intersection = a & b   ## 交集 → {3}
diff = a - b          ## 差集 → {1,2}
```

**适用场景**：去重、成员检测、数学集合运算。

## 高级数据结构

### 1. 双端队列（deque）
**特点**：线程安全、高效头尾操作（O(1)时间复杂度）

**核心操作**：
```python
from collections import deque
dq = deque([1,2,3])
dq.appendleft(0)   ## 左端添加 → deque([0,1,2,3])
dq.popleft()       ## 左端弹出 → 0
```

**适用场景**：滑动窗口算法、任务调度。

### 2. 堆（Heap）
**特点**：最小堆结构（堆顶为最小值）

**核心操作**：
```python
import heapq
heap = []
heapq.heappush(heap, 3)    ## 添加元素 → [3]
heapq.heappop(heap)        ## 弹出最小 → 3
```

**适用场景**：优先队列、Top K问题。

### 3. 命名元组（namedtuple）
**特点**：具名字段的元组，增强可读性

**核心操作**：
```python
from collections import namedtuple
Point = namedtuple("Point", ["x", "y"])
p = Point(3, 4)
print(p.x, p.y)  ## 输出 3 4
```

**适用场景**：替代简单类、数据记录（如CSV行）。

### 4. 计数器（Counter）
**特点**：统计元素出现次数

**核心操作**：
```python
from collections import Counter
words = ["apple", "banana", "apple"]
cnt = Counter(words)  ## → Counter({"apple": 2, "banana": 1})
cnt.most_common(1)    ## → [("apple", 2)]
```

**适用场景**：词频统计、频率分析。

### 数据结构对比与选择原则

| 结构 | 有序性 | 可变性 | 元素唯一性 | 查找效率 | 典型用途 |
|------|--------|--------|------------|----------|----------|
| 列表 | 是 | 是 | 允许重复 | O(n) | 动态集合、序列操作 |
| 元组 | 是 | 否 | 允许重复 | O(n) | 不可变数据存储 |
| 字典 | 无（Python 3.7+保持插入顺序） | 是 | 键唯一 | O(1) | 键值映射、快速查找 |
| 集合 | 无 | 是 | 元素唯一 | O(1) | 去重、集合运算 |
| deque | 是 | 是 | 允许重复 | O(1) | 队列/栈实现 |

**选择原则**：
- 需要快速查找 → **字典、集合**
- 保持插入顺序 → **列表**（Python 3.7+字典也保持顺序）
- 不可变数据 → **元组**
- 高效头尾操作 → **deque**
- 元素频率统计 → **Counter**

## 实用技巧

**列表推导式**：
```python
squares = [x**2 for x in range(10)]  ## → [0,1,4,...,81]
```

**字典推导式**：
```python
word_lengths = {word: len(word) for word in ["apple", "banana"]}  ## → {"apple":5, "banana":6}
```

**合并字典（Python 3.9+）**：
```python
dict1 = {"a":1, "b":2}
dict2 = {"c":3}
merged = dict1 | dict2  ## → {"a":1, "b":2, "c":3}
```

## 性能优化建议

- **列表**：避免频繁插入/删除中间元素（时间复杂度O(n)），改用链表或deque。
- **字典**：预分配空间（dict.fromkeys()）减少扩容开销。
- **集合**：利用哈希特性快速判断存在性（如去重）。

通过合理选择数据结构，可显著提升代码效率和可读性。例如：
- **去重**：set(list) 比循环判断更高效。
- **排序**：sorted(list) 或列表的sort()方法。
- **键值存储**：优先使用字典而非嵌套列表。

## 在Python中，`__init__`和`init`是完全不同的概念。让我详细解释它们的区别：

### 1. `__init__` 方法（构造函数）

`__init__`是Python的**特殊方法**（也叫魔术方法或dunder方法），具有特殊含义：

````python
class MyClass:
    def __init__(self, name):
        """这是构造函数，创建对象时自动调用"""
        self.name = name
        print(f"对象 {name} 被创建了")
    
    def __str__(self):
        """另一个特殊方法，定义对象的字符串表示"""
        return f"MyClass对象: {self.name}"

## 创建对象时，__init__会自动调用
obj = MyClass("测试")  ## 输出: 对象 测试 被创建了
print(obj)  ## 输出: MyClass对象: 测试
````

### 2. `init` 函数（普通函数）

`init`只是一个**普通的函数名**，没有特殊含义：

````python
class MyClass:
    def __init__(self, name):
        self.name = name
    
    def init(self):
        """这是一个普通方法，需要手动调用"""
        self.name = "初始化后的名字"
        print("手动初始化完成")

## 使用示例
obj = MyClass("原始名字")
print(obj.name)  ## 输出: 原始名字

obj.init()  ## 需要手动调用
print(obj.name)  ## 输出: 初始化后的名字
````

### 3. 主要区别对比

| 特性 | `__init__` | `init` |
|------|------------|--------|
| **调用时机** | 对象创建时自动调用 | 需要手动调用 |
| **用途** | 对象初始化/构造函数 | 普通方法，任意用途 |
| **特殊性** | Python特殊方法 | 普通方法名 |
| **命名约定** | 固定名称，不能更改 | 可以任意命名 |
| **返回值** | 不能返回值（除了None） | 可以返回任意值 |

### 4. 实际应用示例

````python
class DatabaseConnection:
    def __init__(self, host, port):
        """构造函数：创建对象时自动调用"""
        self.host = host
        self.port = port
        self.connected = False
        print(f"数据库连接对象创建: {host}:{port}")
    
    def init(self):
        """普通方法：手动初始化连接"""
        self.connected = True
        print(f"连接到数据库 {self.host}:{self.port}")
        return True
    
    def close(self):
        """关闭连接"""
        self.connected = False
        print("数据库连接已关闭")

## 使用示例
db = DatabaseConnection("localhost", 5432)  ## __init__自动调用
print(f"连接状态: {db.connected}")  ## 输出: False

db.init()  ## 手动调用init方法
print(f"连接状态: {db.connected}")  ## 输出: True

db.close()
````

### 5. 改进你的代码

基于你提供的代码，这里是一些改进建议：

````python
class Test:  ## 类名建议使用大写开头
    def __init__(self):
        """构造函数：创建对象时初始化数据"""
        self.data = []
        print("Test对象已创建")
    
    def init(self, initial_data=None):
        """普通方法：重新初始化数据"""
        if initial_data is not None:
            self.data = list(initial_data)
        else:
            self.data = []
        print("数据已重新初始化")
        return self
    
    def add(self, value):
        self.data.append(value)
        return self  ## 支持链式调用
    
    def get(self):
        return self.data.copy()  ## 返回副本，避免外部修改
    
    def clear(self):
        self.data = []
        return self

def main():
    ## __init__在创建对象时自动调用
    t = Test()  ## 输出: Test对象已创建
    
    t.add(1).add(2).add(3)  ## 链式调用
    print(t.get())  ## 输出: [1, 2, 3]
    
    ## 手动调用init方法重新初始化
    t.init([10, 20, 30])  ## 输出: 数据已重新初始化
    print(t.get())  ## 输出: [10, 20, 30]
    
    t.clear()
    print(t.get())  ## 输出: []

if __name__ == "__main__":
    main()
````

### 总结

- `__init__`：Python的构造函数，对象创建时自动调用，用于初始化对象状态
- `init`：普通方法名，需要手动调用，可以用于重新初始化或其他用途
- 两者可以在同一个类中共存，服务于不同的目的

希望这个解释能帮助你理解它们的区别！

chenlz1: python中的赋值语句使用for循环是个什么操作

GitHub Copilot: 在Python中，赋值语句结合for循环有几种常见的操作模式，我来详细解释一下：

## 1. 基本的for循环赋值

```python
# 普通的for循环中的赋值
for i in range(5):
    x = i * 2  # 每次循环都会重新赋值
    print(x)   # 输出: 0, 2, 4, 6, 8
```

## 2. 列表推导式（List Comprehension）

这是Python中非常重要的特性，可以用一行代码创建列表：

```python
# 基本语法：[expression for item in iterable]
numbers = [x * 2 for x in range(5)]
print(numbers)  # 输出: [0, 2, 4, 6, 8]

# 带条件的列表推导式
even_squares = [x**2 for x in range(10) if x % 2 == 0]
print(even_squares)  # 输出: [0, 4, 16, 36, 64]
```

## 3. 其他推导式

```python
# 字典推导式
squares_dict = {x: x**2 for x in range(5)}
print(squares_dict)  # 输出: {0: 0, 1: 1, 2: 4, 3: 9, 4: 16}

# 集合推导式
unique_remainders = {x % 3 for x in range(10)}
print(unique_remainders)  # 输出: {0, 1, 2}

# 生成器表达式
squares_gen = (x**2 for x in range(5))
print(list(squares_gen))  # 输出: [0, 1, 4, 9, 16]
```

## 4. 多重赋值和解包

```python
# 在for循环中解包元组
pairs = [(1, 'a'), (2, 'b'), (3, 'c')]
for num, letter in pairs:
    print(f"数字: {num}, 字母: {letter}")

# 字典的键值对遍历
data = {'name': 'Alice', 'age': 25, 'city': 'Beijing'}
for key, value in data.items():
    print(f"{key}: {value}")
```

## 5. 嵌套循环中的赋值

```python
# 二维列表推导式
matrix = [[i * j for j in range(3)] for i in range(3)]
print(matrix)  # 输出: [[0, 0, 0], [0, 1, 2], [0, 2, 4]]

# 展平嵌套列表
nested = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
flattened = [item for sublist in nested for item in sublist]
print(flattened)  # 输出: [1, 2, 3, 4, 5, 6, 7, 8, 9]
```

## 6. 累积赋值

```python
# 在循环中累积值
total = 0
for i in range(1, 6):
    total += i  # 累积赋值
print(total)  # 输出: 15

# 构建列表
result = []
for i in range(5):
    result.append(i**2)
print(result)  # 输出: [0, 1, 4, 9, 16]
```

## 7. 枚举（enumerate）

```python
# 同时获取索引和值
fruits = ['apple', 'banana', 'orange']
for index, fruit in enumerate(fruits):
    print(f"索引 {index}: {fruit}")
```

## 主要优势：

1. **简洁性**：列表推导式比传统循环更简洁
2. **效率**：推导式通常比等价的for循环更快
3. **可读性**：对于简单操作，推导式更易读
4. **函数式编程**：支持更函数式的编程风格

这些操作让Python在处理数据集合时非常灵活和高效。你想了解其中哪个方面的更多细节吗？

chenlz1: python中__init__和init函数的区别

GitHub Copilot: 在Python中，`__init__`和`init`是完全不同的概念。让我详细解释它们的区别：

## 1. `__init__` 方法（构造函数）

`__init__`是Python的**特殊方法**（也叫魔术方法或dunder方法），具有特殊含义：

````python
class MyClass:
    def __init__(self, name):
        """这是构造函数，创建对象时自动调用"""
        self.name = name
        print(f"对象 {name} 被创建了")
    
    def __str__(self):
        """另一个特殊方法，定义对象的字符串表示"""
        return f"MyClass对象: {self.name}"

# 创建对象时，__init__会自动调用
obj = MyClass("测试")  # 输出: 对象 测试 被创建了
print(obj)  # 输出: MyClass对象: 测试
````

## 2. `init` 函数（普通函数）

`init`只是一个**普通的函数名**，没有特殊含义：

````python
class MyClass:
    def __init__(self, name):
        self.name = name
    
    def init(self):
        """这是一个普通方法，需要手动调用"""
        self.name = "初始化后的名字"
        print("手动初始化完成")

# 使用示例
obj = MyClass("原始名字")
print(obj.name)  # 输出: 原始名字

obj.init()  # 需要手动调用
print(obj.name)  # 输出: 初始化后的名字
````

## 3. 主要区别对比

| 特性 | `__init__` | `init` |
|------|------------|--------|
| **调用时机** | 对象创建时自动调用 | 需要手动调用 |
| **用途** | 对象初始化/构造函数 | 普通方法，任意用途 |
| **特殊性** | Python特殊方法 | 普通方法名 |
| **命名约定** | 固定名称，不能更改 | 可以任意命名 |
| **返回值** | 不能返回值（除了None） | 可以返回任意值 |

## 4. 实际应用示例

````python
class DatabaseConnection:
    def __init__(self, host, port):
        """构造函数：创建对象时自动调用"""
        self.host = host
        self.port = port
        self.connected = False
        print(f"数据库连接对象创建: {host}:{port}")
    
    def init(self):
        """普通方法：手动初始化连接"""
        self.connected = True
        print(f"连接到数据库 {self.host}:{self.port}")
        return True
    
    def close(self):
        """关闭连接"""
        self.connected = False
        print("数据库连接已关闭")

# 使用示例
db = DatabaseConnection("localhost", 5432)  # __init__自动调用
print(f"连接状态: {db.connected}")  # 输出: False

db.init()  # 手动调用init方法
print(f"连接状态: {db.connected}")  # 输出: True

db.close()
````

## 5. 改进你的代码

基于你提供的代码，这里是一些改进建议：

````python
class Test:  # 类名建议使用大写开头
    def __init__(self):
        """构造函数：创建对象时初始化数据"""
        self.data = []
        print("Test对象已创建")
    
    def init(self, initial_data=None):
        """普通方法：重新初始化数据"""
        if initial_data is not None:
            self.data = list(initial_data)
        else:
            self.data = []
        print("数据已重新初始化")
        return self
    
    def add(self, value):
        self.data.append(value)
        return self  # 支持链式调用
    
    def get(self):
        return self.data.copy()  # 返回副本，避免外部修改
    
    def clear(self):
        self.data = []
        return self

def main():
    # __init__在创建对象时自动调用
    t = Test()  # 输出: Test对象已创建
    
    t.add(1).add(2).add(3)  # 链式调用
    print(t.get())  # 输出: [1, 2, 3]
    
    # 手动调用init方法重新初始化
    t.init([10, 20, 30])  # 输出: 数据已重新初始化
    print(t.get())  # 输出: [10, 20, 30]
    
    t.clear()
    print(t.get())  # 输出: []

if __name__ == "__main__":
    main()
````

## 总结

- `__init__`：Python的构造函数，对象创建时自动调用，用于初始化对象状态
- `init`：普通方法名，需要手动调用，可以用于重新初始化或其他用途
- 两者可以在同一个类中共存，服务于不同的目的

希望这个解释能帮助你理解它们的区别！

## dunder方法
GitHub Copilot: 在Python中，带双下划线的方法被称为**魔术方法**（Magic Methods）或**特殊方法**（Special Methods），也叫**dunder方法**（double underscore）。这些方法让你的类能够与Python的内置操作符和函数进行交互。

### 1. 对象生命周期相关

#### 构造与销毁
```python
class MyClass:
    def __init__(self, name):
        """构造函数：创建对象时调用"""
        self.name = name
        print(f"对象 {name} 被创建")
    
    def __del__(self):
        """析构函数：对象被销毁时调用"""
        print(f"对象 {self.name} 被销毁")
    
    def __new__(cls, *args, **kwargs):
        """创建实例（在__init__之前调用）"""
        print("创建新实例")
        return super().__new__(cls)
```

### 2. 字符串表示相关

```python
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def __str__(self):
        """用户友好的字符串表示（print时调用）"""
        return f"Person(name={self.name}, age={self.age})"
    
    def __repr__(self):
        """开发者友好的字符串表示（调试时显示）"""
        return f"Person('{self.name}', {self.age})"
    
    def __format__(self, format_spec):
        """自定义格式化"""
        if format_spec == 'short':
            return f"{self.name}({self.age})"
        return str(self)

## 使用示例
p = Person("Alice", 25)
print(p)                    ## 调用 __str__
print(repr(p))              ## 调用 __repr__
print(f"{p:short}")         ## 调用 __format__
```

### 3. 数学运算符重载

```python
class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def __add__(self, other):
        """加法：+"""
        return Vector(self.x + other.x, self.y + other.y)
    
    def __sub__(self, other):
        """减法：-"""
        return Vector(self.x - other.x, self.y - other.y)
    
    def __mul__(self, scalar):
        """乘法：*"""
        return Vector(self.x * scalar, self.y * scalar)
    
    def __truediv__(self, scalar):
        """除法：/"""
        return Vector(self.x / scalar, self.y / scalar)
    
    def __floordiv__(self, scalar):
        """整除：//"""
        return Vector(self.x // scalar, self.y // scalar)
    
    def __mod__(self, scalar):
        """取模：%"""
        return Vector(self.x % scalar, self.y % scalar)
    
    def __pow__(self, power):
        """幂运算：**"""
        return Vector(self.x ** power, self.y ** power)
    
    def __str__(self):
        return f"Vector({self.x}, {self.y})"

## 使用示例
v1 = Vector(3, 4)
v2 = Vector(1, 2)
print(v1 + v2)  ## Vector(4, 6)
print(v1 * 2)   ## Vector(6, 8)
```

### 4. 比较运算符重载

```python
class Student:
    def __init__(self, name, score):
        self.name = name
        self.score = score
    
    def __eq__(self, other):
        """等于：=="""
        return self.score == other.score
    
    def __ne__(self, other):
        """不等于：!="""
        return self.score != other.score
    
    def __lt__(self, other):
        """小于：<"""
        return self.score < other.score
    
    def __le__(self, other):
        """小于等于：<="""
        return self.score <= other.score
    
    def __gt__(self, other):
        """大于：>"""
        return self.score > other.score
    
    def __ge__(self, other):
        """大于等于：>="""
        return self.score >= other.score
    
    def __str__(self):
        return f"{self.name}({self.score})"

## 使用示例
s1 = Student("Alice", 90)
s2 = Student("Bob", 85)
print(s1 > s2)   ## True
print(s1 == s2)  ## False
```

### 5. 容器类型相关

```python
class MyList:
    def __init__(self):
        self.items = []
    
    def __len__(self):
        """长度：len()"""
        return len(self.items)
    
    def __getitem__(self, index):
        """获取项：obj[index]"""
        return self.items[index]
    
    def __setitem__(self, index, value):
        """设置项：obj[index] = value"""
        self.items[index] = value
    
    def __delitem__(self, index):
        """删除项：del obj[index]"""
        del self.items[index]
    
    def __contains__(self, item):
        """包含检查：item in obj"""
        return item in self.items
    
    def __iter__(self):
        """迭代器：for item in obj"""
        return iter(self.items)
    
    def __reversed__(self):
        """反向迭代：reversed(obj)"""
        return reversed(self.items)
    
    def append(self, item):
        self.items.append(item)
    
    def __str__(self):
        return str(self.items)

## 使用示例
my_list = MyList()
my_list.append(1)
my_list.append(2)
my_list.append(3)

print(len(my_list))      ## 3
print(my_list[1])        ## 2
print(2 in my_list)      ## True
for item in my_list:     ## 迭代
    print(item)
```

### 6. 类型转换相关

```python
class Temperature:
    def __init__(self, celsius):
        self.celsius = celsius
    
    def __int__(self):
        """转换为整数：int(obj)"""
        return int(self.celsius)
    
    def __float__(self):
        """转换为浮点数：float(obj)"""
        return float(self.celsius)
    
    def __str__(self):
        """转换为字符串：str(obj)"""
        return f"{self.celsius}°C"
    
    def __bool__(self):
        """转换为布尔值：bool(obj)"""
        return self.celsius != 0
    
    def __complex__(self):
        """转换为复数：complex(obj)"""
        return complex(self.celsius)

## 使用示例
temp = Temperature(25.5)
print(int(temp))     ## 25
print(float(temp))   ## 25.5
print(str(temp))     ## 25.5°C
print(bool(temp))    ## True
```

### 7. 上下文管理器

```python
class FileManager:
    def __init__(self, filename, mode):
        self.filename = filename
        self.mode = mode
        self.file = None
    
    def __enter__(self):
        """进入with语句时调用"""
        print(f"打开文件: {self.filename}")
        self.file = open(self.filename, self.mode)
        return self.file
    
    def __exit__(self, exc_type, exc_val, exc_tb):
        """退出with语句时调用"""
        print(f"关闭文件: {self.filename}")
        if self.file:
            self.file.close()
        ## 返回False表示不抑制异常

## 使用示例
with FileManager("test.txt", "w") as f:
    f.write("Hello World")
## 自动调用__exit__关闭文件
```

### 8. 调用相关

```python
class Calculator:
    def __init__(self, name):
        self.name = name
    
    def __call__(self, a, b, operation='+'):
        """使对象可调用：obj()"""
        if operation == '+':
            return a + b
        elif operation == '-':
            return a - b
        elif operation == '*':
            return a * b
        elif operation == '/':
            return a / b
        else:
            raise ValueError("不支持的操作")
    
    def __str__(self):
        return f"Calculator({self.name})"

## 使用示例
calc = Calculator("我的计算器")
print(calc(10, 5, '+'))  ## 15
print(calc(10, 5, '*'))  ## 50
```

### 9. 属性访问相关

```python
class DynamicObject:
    def __init__(self):
        self._data = {}
    
    def __getattr__(self, name):
        """获取不存在的属性时调用"""
        print(f"访问属性: {name}")
        return self._data.get(name, f"属性 {name} 不存在")
    
    def __setattr__(self, name, value):
        """设置属性时调用"""
        if name.startswith('_'):
            super().__setattr__(name, value)
        else:
            print(f"设置属性: {name} = {value}")
            if not hasattr(self, '_data'):
                super().__setattr__('_data', {})
            self._data[name] = value
    
    def __delattr__(self, name):
        """删除属性时调用"""
        print(f"删除属性: {name}")
        if name in self._data:
            del self._data[name]
    
    def __getattribute__(self, name):
        """所有属性访问都会调用（慎用）"""
        print(f"访问任意属性: {name}")
        return super().__getattribute__(name)

## 使用示例
obj = DynamicObject()
obj.name = "Alice"        ## 调用 __setattr__
print(obj.name)           ## 调用 __getattr__
del obj.name              ## 调用 __delattr__
```

### 10. 常用魔术方法速查表

| 方法 | 用途 | 触发时机 |
|------|------|----------|
| `__init__` | 构造函数 | 创建对象时 |
| `__del__` | 析构函数 | 对象被销毁时 |
| `__str__` | 字符串表示 | `str(obj)`, `print(obj)` |
| `__repr__` | 开发者表示 | `repr(obj)`, 调试时 |
| `__len__` | 长度 | `len(obj)` |
| `__add__` | 加法 | `obj1 + obj2` |
| `__eq__` | 相等比较 | `obj1 == obj2` |
| `__lt__` | 小于比较 | `obj1 < obj2` |
| `__getitem__` | 索引访问 | `obj[key]` |
| `__setitem__` | 索引赋值 | `obj[key] = value` |
| `__contains__` | 成员检查 | `item in obj` |
| `__iter__` | 迭代 | `for item in obj` |
| `__call__` | 对象调用 | `obj()` |
| `__enter__` | 上下文进入 | `with obj:` |
| `__exit__` | 上下文退出 | `with obj:` 结束 |

### 11. 实际应用示例

```python
class BankAccount:
    def __init__(self, owner, balance=0):
        self.owner = owner
        self._balance = balance
        self.transactions = []
    
    def __str__(self):
        return f"账户({self.owner}): ¥{self._balance}"
    
    def __repr__(self):
        return f"BankAccount('{self.owner}', {self._balance})"
    
    def __add__(self, amount):
        """存款"""
        self._balance += amount
        self.transactions.append(f"存款: +¥{amount}")
        return self
    
    def __sub__(self, amount):
        """取款"""
        if amount <= self._balance:
            self._balance -= amount
            self.transactions.append(f"取款: -¥{amount}")
        else:
            raise ValueError("余额不足")
        return self
    
    def __len__(self):
        """交易记录数量"""
        return len(self.transactions)
    
    def __bool__(self):
        """账户是否有余额"""
        return self._balance > 0
    
    def __getitem__(self, index):
        """获取交易记录"""
        return self.transactions[index]

## 使用示例
account = BankAccount("张三", 1000)
print(account)          ## 账户(张三): ¥1000
account = account + 500 ## 存款
account = account - 200 ## 取款
print(account)          ## 账户(张三): ¥1300
print(len(account))     ## 2 (交易记录数)
print(bool(account))    ## True (有余额)
print(account[0])       ## 存款: +¥500
```

这些魔术方法让你的类能够像内置类型一样自然地使用，大大提高了代码的可读性和pythonic程度！