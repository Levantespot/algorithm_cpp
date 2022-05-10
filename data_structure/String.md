### 滑动窗口

适用：

- 字符串匹配

**算法思路**：

每个元素只会进入一次处理窗口，离开一次处理窗口，后续不再进入（有可能只进不出）。时间复杂度为 O(N)。

```c++
定义当前处理窗口 window = {}; // window = s[left, right)
int left = 0, right = 0;

while (right < s.size()) {
    // expand 向右增大窗口
    将 s[right] 放入 window 中;
    right++;
    
    while (需要缩减 window) {
        // shrink 从左缩小窗口
        将 s[left] 从 window 中删除
        left++;
    }
}
```

字符串中常用的滑动窗口算法模板：

```c++
void slidingWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;
    
    int left = 0, right = 0; // window = s[left, right)
    int valid = 0; // 记录完成多少个（通常是 unique 的）字符匹配
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        // 增大窗口
        right++;
        // 进行窗口内数据的一系列更新
        ...

        /*** debug 输出的位置 ***/
        printf("window: [%d, %d)\n", left, right);
        /********************/
        
        // 判断左侧窗口是否要收缩
        while (window needs shrink) {
            // d 是将移出窗口的字符
            char d = s[left];
            // 缩小窗口
            left++;
            // 进行窗口内数据的一系列更新
            ...
        }
    }
}
```



**注意事项**：

1. 什么时候向右扩张、什么时候向左缩减。
2. `left` 是否可能会大于 `right`。
3. 如果要计算字串长度，注意是 `right-left+1` 还是 `right-left`（取决于何时递增 `right` 和 `left`）
4. 注意 `map` 和 `set` 判断其中有没有元素的方法，`map` 直接访问 `key` 判断是否为 0，`set` 用 `count()` 判断是否为 0。



例题

- [76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)
- [567. Permutation in String](https://leetcode.com/problems/permutation-in-string/)
- [438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)
- [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)