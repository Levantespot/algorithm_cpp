## 回溯法 Back Tracking Method

### 基本框架

本质就是使用 DFS 递归遍历决策树。通用办法是画出决策树，然后想想如何针对问题剪边达到优化加速的目的。

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
- 回溯算法是一种遍历算法，可以搜索得到所有的方案，需要返回（最优）求解路径，时间复杂度很高。

### 例题

- [46. Permutations](https://leetcode.com/problems/permutations)
- [51. N-Queens](https://leetcode.com/problems/n-queens/)
- pass

### 排列、组合、子集问题

本质还是是使用 DFS 递归遍历决策树

算法分类

- 排列
  - 所有数都会被使用，为避免重复取元素，常常使用 `used` 数组表示哪些数被使用过了
- 子集
  - 只使用一部分数，为避免重复取元素，常常先排序（如果需要的话），使用 `start_idx` 索引表示接下来处理的开始索引
- 组合
  - 传统意义上的组合 $C_m^n$，元素不可复选，等价于**特定大小**的**子集**算法。
  - 对于元素可以复选的组合，下一次迭代时 `start_idx` 不用 +1 即可解决。

元素性质分类

- 元素无重不可复选

  即 `nums` 中的元素都是唯一的，每个元素最多只能被使用一次

  ```c++
  /* 组合&子集问题回溯算法框架 */
  void backtrack(vector<int> &nums, int start) {
      // base case
      ...
      // 回溯算法标准框架
      for (int i = start; i < nums.length; i++) {
          // 做选择
          track.push_back(nums[i]);
          // 注意参数
          backtrack(nums, i + 1);
          // 撤销选择
          track.pop_back();
      }
  }
  
  /* 排列问题回溯算法框架 */
  void backtrack(vector<int> &nums, vector<bool> &used) {
      // base case
      ...
      for (int i = 0; i < nums.length; i++) {
          // 剪枝逻辑
          if (used[i]) {
              continue;
          }
          // 做选择
          used[i] = true;
          track.push_back(nums[i]);
  
          backtrack(nums);
          // 撤销选择
          track.pop_back();
          used[i] = false;
      }
  }
  ```

  

- 元素可重不可复选

  即 `nums` 中的元素可以存在重复，每个元素最多只能被使用一次，其关键在于排序和剪枝

  ```c++
  sort(nums.begin(), nums.end());
  /* 组合&子集问题回溯算法框架 */
  void backtrack(vector<int> &nums, int start) {
      // base case
      ...
      // 回溯算法标准框架
      for (int i = start; i < nums.length; i++) {
          // 剪枝逻辑，跳过值相同的相邻树枝
          if (i > start && nums[i] == nums[i - 1]) {
              continue;
          }
          // 做选择
          track.push_back(nums[i]);
          // 注意参数
          backtrack(nums, i + 1);
          // 撤销选择
          track.pop_back();
      }
  }
  
  
  sort(nums.begin(), nums.end());
  /* 排列问题回溯算法框架 */
  void backtrack(vector<int> &nums, vector<bool> &used) {
      // base case
      ...
      for (int i = 0; i < nums.length; i++) {
          // 剪枝逻辑
          if (used[i]) {
              continue;
          }
          // 剪枝逻辑，固定相同的元素在排列中的相对位置
          if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
              continue;
          }
          // 做选择
          used[i] = true;
          track.push_back(nums[i]);
  
          backtrack(nums);
          // 撤销选择
          track.pop_back();
          used[i] = false;
      }
  }
  ```

  

- 元素无重可复选

  即 `nums` 中的元素都是唯一的，每个元素可以被使用若干次，只要删掉去重逻辑即可

  ```c++
  /* 组合&子集问题回溯算法框架 */
  void backtrack(vector<int> &nums, int start) {
      // base case
      ...
      // 回溯算法标准框架
      for (int i = start; i < nums.length; i++) {
          // 做选择
          track.push_back(nums[i]);
          // 注意参数
          backtrack(nums, i);
          // 撤销选择
          track.pop_back();
      }
  }
  
  
  /* 排列问题回溯算法框架 */
  void backtrack(vector<int> &nums) {
      // base case
      ...
      for (int i = 0; i < nums.length; i++) {
          // 做选择
          track.push_back(nums[i]);
          backtrack(nums);
          // 撤销选择
          track.pop_back();
      }
  }
  ```



|      | 元素无重不可复选                                             | 元素可重不可复选                                             | 元素无重可复选                                               |
| ---- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 排列 | [46. Permutations](https://leetcode.com/problems/permutations) | [47. Permutations II](https://leetcode.com/problems/permutations-ii/) |                                                              |
| 组合 | [77. Combinations](https://leetcode.com/problems/combinations/) | [40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)<br />[216. Combination Sum III](https://leetcode.com/problems/combination-sum-iii/) | [39. Combination Sum](https://leetcode.com/problems/combination-sum/) |
| 子集 | [78. Subsets](https://leetcode.com/problems/subsets/)        | [90. Subsets II](https://leetcode.com/problems/subsets-ii/)  |                                                              |



### Ref

- [回溯算法秒杀所有排列/组合/子集问题](https://labuladong.github.io/algo/1/8/)