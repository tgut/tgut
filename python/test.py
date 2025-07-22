# test for and while loops

# x, y = 0, 0
# while x < 5 and y < 3:
#     print(f"x={x}, y={y}")
#     x += 1
#     y += 1
# # 输出：x=0,y=0 → x=1,y=1 → x=2,y=2

## test defaultdict
from collections import defaultdict

# 创建默认字典
dd = defaultdict(int)        # 默认值为0
print(dd['count'])
dd['count'] += 0             # 不存在时自动创建为0，然后+1 → 1
print(dd['count'])