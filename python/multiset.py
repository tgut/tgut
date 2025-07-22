from collections import defaultdict

class Multiset:
    def __init__(self, iterable=None):
        self._data = defaultdict(int)
        if iterable:
            for item in iterable:
                self.add(item)

    def add(self, item):
        self._data[item] += 1

    def remove(self, item):
        if item in self._data:
            self._data[item] -= 1
            if self._data[item] == 0:
                del self._data[item]

    def __contains__(self, item):
        return item in self._data

    def __iter__(self):
        # 返回展开后的迭代器（如 [a, a, b]）
        return (item for item, count in self._data.items() for _ in range(count))

    def __repr__(self):
        return f"Multiset({dict(self._data)})"

# 使用示例
mset = Multiset(['apple', 'apple', 'banana'])
mset.add('grape')
print(mset)  # 输出：Multiset({'apple': 2, 'banana': 1, 'grape': 1})
print('apple' in mset)  # 输出：True
list(mset)  # 输出：['apple', 'apple', 'banana', 'grape']