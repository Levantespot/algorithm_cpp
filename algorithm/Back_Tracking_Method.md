## 回溯法 Back Tracking Method

### 基本框架

本质就是使用 DFS 遍历。

```python
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.append(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择

```

与动态规划的区别：

- 动态规划只需要求我们评估最优解是多少，最优解对应的具体解是什么并不要求。
- 回溯算法是一种遍历算法，可以搜索得到所有的方案，可能需要返回（最优）求解路径，时间复杂度很高。



### 题目

- [46. Permutations](https://leetcode.com/problems/permutations)
- [51. N-Queens](https://leetcode.com/problems/n-queens/)
- pass