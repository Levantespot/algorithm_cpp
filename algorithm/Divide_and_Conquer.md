## 分而治之 Divide and Conquer



### 递归框架

- 练习分析问题的结构，当问题可以被分解成相同结构的小问题时，可以使用递归
- 最重要的就是明确递归函数的定义

```python
def recursion(x) {
    // 最简子问题，结束递归
    if (...) return ...;
    // 自我调用，并缩小规模
    return recursion(x[1:]) + ...;
}
```



### 基本框架

分治算法可以分三步走：分解 -> 解决 -> 合并

1. 分解原问题为结构相同的子问题。
2. 分解到某个容易求解的边界之后，进行递归求解。
3. 将子问题的解合并成原问题的解。

```python

```



### 题目

- [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)
- pass