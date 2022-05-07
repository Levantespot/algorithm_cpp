# 顺序表 List

## 数组

### 常用思路

- 前缀和
  - 可以快速计算一个区间内的和
  - 例题
    - [303. Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)
    - [304. Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/)
    - [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)
  
- 差分数组
  - 可以快速计算多次改变连续区间相同的值后的结果
  
    ```c++
    vector<int> nums{1,2,3,4,5};
    
    vector<int>diff;
    for (int i = 0; i < nums.size()-1; i++) {
        diff.push_back(nums[i+1] - nums[i]); // nums[i+1] = nums[i] + diff[i]
    }
    
    // 给 nums 的中间三个数 +1，即 [1,2,3,4,5] -> [1,3,4,5,5]
    // 等价于 diff[1] += 1 && diff[4] -= 1
    // 推断改变后的 nums 的计算公式为 nums[i+1] = nums[i] + diff[i]
    ```
  
    
  
  - 例题
    
    - [370. Range Addition](https://leetcode.com/problems/range-addition/)✨
    - [1109. Corporate Flight Bookings](https://leetcode.com/problems/corporate-flight-bookings/)
    - [1094. Car Pooling](https://leetcode.com/problems/car-pooling/)
  
- 滑动窗口

  - 每次要么增大窗口，要么减小窗口，时间复杂度为 O(N)。
  - 例题
    - [76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)
    - [567. Permutation in String](https://leetcode.com/problems/permutation-in-string/)
    - [438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)
    - [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

  - 见：数据结构-串


## 链表

### 常用思路

- 左右指针
  - 两个指针相向而行或者相背而行
    - [344. Reverse String](https://leetcode.com/problems/reverse-string/)
    - [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
- 快慢指针
  - 两个指针同向而行，一快一慢
    - [26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
    - [27. Remove Element](https://leetcode.com/problems/remove-element/)
    - [876. Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)
    - [19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
  - 链表循环问题：判断是否有循环、获取循环开始位置
    - [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)
    - [142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)



