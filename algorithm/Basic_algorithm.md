# 基本算法

## 一、动态规划 Dynamic Programming

### 基本框架

- 一般形式是求最值，如：求最长递增子序列呀，最小编辑距离
- 求解动态规划的核心问题是穷举
  - 存在「重叠子问题」，需要「备忘录」或者「DP table」来优化穷举过程
  - 需要列出正确的「状态转移方程」，才能正确地穷举。
- 动态规划问题一定会具备「最优子结构」，才能通过子问题的最值得到原问题的最值。
  - 要符合「最优子结构」，子问题间必须互相独立！


```c++
/* 自顶向下 */
定义备忘录 memo
状态 dp(状态, ...) {
	if memo[现在状态] 中已经有结果
        return memo[现在状态]
	else
        return dp(下一个状态) + 现在状态与下一个状态的差别
}

/* 自底向上 */
定义 dp table
# 初始化 dp table 中的 base case
dp[0][0][...] = base
# 进行状态转移（更新 dp table）
for 状态1 in 状态1的所有取值：
	for 状态2 in 状态2的所有取值：
		for ...
			dp[状态1][状态2][...] = 求最值(选择1，选择2...)
			直到转移到我们需要的状态，return dp[最终状态]
```



### 题目

- [322. Coin Change](https://leetcode.com/problems/coin-change)
- [300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence)
- [354. Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes)
- pass



## 二、分而治之 Divide and Conquer





## 三、贪心算法 Greedy Algorithm





## 四、回溯法 Back Tracking Method





## 五、分支界限法 Branch and Bound







