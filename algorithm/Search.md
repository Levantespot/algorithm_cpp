## 线性表查找

### 二分查找

1. 首先要明确自己的「搜索区间」是开还是闭，「搜索区间」影响：
   1. `left`、`right` 的初始化
   2. 循环结束的条件：`<=` or `<`（具体看题目）
   3. 更新左右边界的方式：`=mid±1` or `=mid`
2. 注意细节
   1. 注意整型溢出：`(left+right)/2` 改为 `left + (right-left)/2`
   1. 注意终止条件，避免溢出：如终止条件为 `left==right+1` ，检查是否可能出现 `right=nums.size()-1` ，并访问 `nums[left]` 的情况。

```c++
// 一种 [left, right] 的二分查找
int binary_search(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1, mid;  // attention

    mid = left + (right-left)/2;
    while (left <= right) { // attention
        if (nums[mid] == target) {
            break;
        } else if (nums[mid] < target) {
            left = mid+1; // attention
        } else {
            right = mid-1; // attention
        }
        mid = (left + right) / 2;
    }
    return (nums[mid] == target) ? mid : -1;
}
```



题目

- [34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
- 