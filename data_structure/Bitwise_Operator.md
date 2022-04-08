# BITWISE OPERATOR

## 基础部分

### 位运算符

| 符号 | 描述 | 运算规则                                                     |
| :--- | :--- | :----------------------------------------------------------- |
| &    | 与   | 两个位都为 1 时，结果才为 1，其他情况结果为 0。              |
| \|   | 或   | 两个位都为 0 时，结果才为 0，其他情况结果为 1。              |
| ^    | 异或 | 两个位相同为 0，相异为 1。                                   |
| ~    | 取反 | 0 变 1，1 变 0。                                             |
| <<   | 左移 | 各二进位全部左移若干位，高位丢弃，低位补 0                   |
| >>   | 右移 | 各二进位全部右移若干位，对无符号数，高位补 0；<br />有符号数，取决于编译器，或补符号位（算术右移），或补 0（逻辑右移）。 |

### 基本性质

**交换律**

- `a|b = b|a`
- `a&b = b&a`
- `a^b = b^a`

**结合律**

- `(a|b)|c = a|(b|c)`
- `(a&b)&c = a&(b&c)`
- `(a^b)^c = a^(b^c)`

**分配律**

- `a&(b|c) = (a&b)|(a&c)`
- `a^(b|c)=(a^b)|(a^c)`

**其他**

- `a|0 = a`
- `a&1 = a`
- `a&0 = 0`
- `a^a = 0`
- `a^0 =a`
- `a|~a = 1`
- `a&~a = 0`
- `a&a = a`
- `a|a = a`
- `a|(a&b) = a`
- `a&(a|b) = a`

### 使用位运算达成一些功能

- 使用位运算交换两个数

  ```c++
  // 初始值 a = 11_(10) = 1011_(2), b = 5_(10) = 0101_(2), 
  a=a^b; // a=1110,b=0101
  b=a^b; // b=1011,a=1110
  a=a^b; // a=0101,b=1011 交换完成
  ```

- 



## 常见题目

[136. Single Number](https://leetcode.com/problems/single-number/)

>Given a **non-empty** array of integers `nums`, every element appears *twice* except for one. Find that single one.
>
>You must implement a solution with a linear runtime complexity and use only constant extra space.

```c++
// Way 1: XOR operator.
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
    	result ^= num;
    }
    return result;
}

// Way 2: hash map(TODO)
```



