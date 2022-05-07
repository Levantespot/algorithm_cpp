### 字符串匹配（滑动窗口）

算法思路：



注意事项：

1. 什么时候向右扩张、什么时候向左缩减。
2. `left` 是否可能会大于 `right`。
3. 如果要计算字串长度，注意是 `right-left+1` 还是 `right-left`（取决于何时递增 `right` 和 `left`）
4. 注意 `map` 和 `set` 判断其中有没有元素的方法，`map` 直接访问 `key` 判断是否为 0，`set` 用 `count()` 判断是否为 0。



例题

- [76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)
- [567. Permutation in String](https://leetcode.com/problems/permutation-in-string/)
- [438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)
- [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)