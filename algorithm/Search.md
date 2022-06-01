## 搜索 Search

目的：遍历结构，找到满足条件的目标 `target`，返回目标值或者路径。

拓展应用：

1. 需要一次次尝试，且尝试结果有递增、递减特性，因此可以用二分搜索减少尝试次数
   - [875. Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)

### 二分搜索 Binary Search

1. 首先要明确自己的「搜索区间」是开还是闭，「搜索区间」影响：
   1. `left`、`right` 的初始化
   2. 循环结束的条件：`<=` or `<`（具体看题目）
   3. 更新左右边界的方式：`=mid±1` or `=mid`
2. 注意细节
   1. 注意整型溢出：`(left+right)/2` 改为 `left + (right-left)/2`
   1. 注意终止条件，避免溢出：如终止条件为 `left==right+1` ，检查是否可能出现 `right=nums.size()-1` ，并访问 `nums[left]` 的情况。

```c++
// 一种 [left, right] 的二分查找
int binary_search(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1, mid;  // attention

    while (left <= right) { // attention
        mid = left + (right-left)/2;
        if (nums[mid] == target) {
            break;
        } else if (nums[mid] < target) {
            left = mid+1; // attention
        } else {
            right = mid-1; // attention
        }
    }
    return (nums[mid] == target) ? mid : -1;
}

// 寻找左侧边界的二分查找（容易理解，但是计算量大一点），即 1,2,2,2,3 找 2，返回索引为 1
int binary_search_left(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1, mid;  // attention

    mid = left + (right-left)/2;
    while (left <= right) { // attention
        if (nums[mid] == target && (mid == 0 || nums[mid-1] != target)) {
            break;
        } else if (nums[mid] < target) {
            left = mid+1; // attention
        } else if (nums[mid] > target || (nums[mid] == target && nums[mid-1] == target)){
            right = mid-1; // attention
        }
        mid = (left + right) / 2;
    }
    return (nums[mid] == target) ? mid : -1;
}

// 左边界优化版本
// 思路是先去找正确位置的左边一位，找到后 left=mid=right，然后不满足条件导致 left+=1，即正确的位置，然后退出循环
// 退出循环的条件为 mid=left=right+1
// 如果没找到，则返回第一个比目标大的位置（可能为 nums.size()）
int binary_search_left(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1, mid;  // attention

    while (left <= right) { // attention
        mid = left + (right-left)/2;
        if (nums[mid] >= target) {
            right = mid-1; //
        } else { // if (nums[mid] < target)
            left = mid+1; // 最后
        }
    }
    if (left == nums.size()) return -1;
    return (nums[left] == target) ? left : -1;
}

// 寻找右侧边界的二分查找，即 1,2,2,2,3 找 2，返回索引为 3
// 退出循环的条件为 mid=right=left-1
// 如果没找到，则返回第一个比目标小的位置（可能为 -1）
int binary_search_right(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1, mid;  // attention

    while (left <= right) { // attention
        mid = left + (right-left)/2;
        if (nums[mid] <= target) {
            left = mid+1;
        } else { // if (nums[mid] > target)
            right = mid-1;
        }
    }
    if (right == -1) return -1;
    return (nums[right] == target) ? right : -1;
}
```



题目

- [34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
- pass





### 广度优先搜索 Breadth First Search, BFS

- 利用队列，将当前节点所能进行的所有变化、操作压进队列后，再对队列中的下一个节点进行相同处理
- 本质是图的遍历，类似于树的层序遍历
- BFS 找到的路径一定是最短的，但代价就是空间复杂度可能比 DFS 大很多
- 适用：求最短距离、最少次数等等

```c++
// 二叉树循环版本
int BFS(TreeNode* root, int target) {
    queue<TreeNode *> q;
    int count;
    TreeNode *p;

    if (root) q.push(root);
    while (!q.empty()) {
        count = q.size();
        while (count--) {
            p = q.front();
            q.pop();
            // 判断是否到达终点
            if (root->val == target) return ...;
            // 将其所有的变化（子节点）压进队列
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
        }
    }
    // 没有满足条件的路径
    return ...;
}

// 通用版本 1
int BFS(Node start, Node target) {
    queue<Node> q; // 核心数据结构
    set<Node> visited; // 避免走回头路
    
    q.push(start); // 将起点加入队列
    visited.insert(start);

    while (!q.empty()) {
        int sz = q.size();
        /* 将当前队列中的所有节点向四周扩散 */
        for (int i = 0; i < sz; i++) {
            Node cur = q.top();
            q.pop();
            
            // 判断是否到达终点
            if (cur == target) return ...
            // 将 cur 的相邻节点加入队列
            for (Node x : cur.adj()) { // cur.adj() 代表其所有邻居
                if (!visited.count(x)) {
                    q.push(x);
                    visited.insert(x);
                }
            } // for end
        } // for end
    } // while end
    // 没有满足条件的路径
    return ...;
}
```

细节与优化

1. `visited` 的更新位置，通用版本 1 更快，因为通用版本 1 可以保证永远不会出现重复的节点进队列的情况，而通用版本 2 的队列中会在刚开始的时候出现重复的节点。

2. 双向 BFS 优化：传统的 BFS 就是从起点开始向四周扩散，遇到终点时停止；而双向 BFS 则是从起点和终点同时开始扩散，当两边有交集的时候停止。

     - 优点：虽然时间复杂度依然是 O(N)，但大部分情况遍历的节点比原版本少，也就是更快。

     - 缺点：原版用知道终点的位置（可以直接访问其邻居节点），双向必须知道终点的位置。

     - 思路：使用两个集合代替一个队列，分别存储从起点和终点方向**待**扩展的节点，若两个集合有重合，代表形成一条从起点到终点的最短路径。

     - 关键：`visited` 的更新位置只能使用版本 2，因判断是否出现满足要求的路径的条件是两个集合发生重合，而使用版本 1 就不可能发生重合。

     - 双向 BFS 的优化：按照 BFS 的逻辑，队列（集合）中的元素越多，扩散之后新的队列（集合）中的元素就越多；在双向 BFS 算法中，如果我们每次都选择一个较小的集合进行扩散，那么占用的空间增长速度就会慢一些，效率就会高一些。

       

```c++
// 通用版本 2
int BFS(Node start, Node target) {
    queue<Node> q; // 核心数据结构
    set<Node> visited; // 避免走回头路
    
    q.push(start); // 将起点加入队列

    while (!q.empty()) {
        int sz = q.size();
        /* 将当前队列中的所有节点向四周扩散 */
        for (int i = 0; i < sz; i++) {
            Node cur = q.top();
            q.pop();
            if (visited.count(cur)) continue;
            visited.insert(x);
            
            // 判断是否到达终点
            if (cur == target) return ...;
            // 将 cur 的相邻节点加入队列
            for (Node x : cur.adj()) // cur.adj() 代表其下一个邻居
                if (!visited.count(x)) q.push(x);
        } // for end
    } // while end
    // 没有满足条件的路径
    return ...;
}

// 双向 BFS
int Bi_BFS(Node start, Node target) {
    set<Node> q1, q2; // 核心数据结构
    set<Node> q_tmp; // q_tmp 用于交换 q1&q2，因此循环中只需要对 q1 进行扩展即可。
    
    q1.insert(start); // 将起点加入集合1
    q2.insert(target); // 将起点加入集合1

    while (!q1.empty() || !q2.empty()) {
        /* 将当前 q1 集合中的所有节点向四周扩散 */
        q_tmp.erase(q_tmp.begin(), q_tmp.end());
        for (Node cur : q1) {
            if (visited.count(cur)) continue;
            // 出现重复，即有满足条件的最短路径，结束运行
            if (q2.count(cur)) return ...;
            // 将 cur 的相邻节点加入集合
            for (Node x : cur.adj()) { // cur.adj() 代表其所有邻居
                if (!visited.count(x)) {
                    q_tmp.insert(x);
                }
            } // for end
        } // for end
        // 交换 q1&q2
        q1 = q2;
        q2 = q_tmp;
    } // while end
    // 没有满足条件的路径
    return ...;
}

// 双向 BFS 优化版本
int Bi_BFS(Node start, Node target) {
    set<Node> q1, q2; // 核心数据结构
    set<Node> q_tmp; // q_tmp 用于交换 q1&q2，因此循环中只需要对 q1 进行扩展即可。
    
    q1.insert(start); // 将起点加入集合1
    q2.insert(target); // 将起点加入集合1

    while (!q1.empty() || !q2.empty()) {
        /* 将当前 q1 集合中的所有节点向四周扩散 */
        q_tmp.erase(q_tmp.begin(), q_tmp.end());
        
        // 交换 q1 和 q2
        if (q1.size() > q2.size()) q1.swap(q2);
        
        for (Node cur : q1) {
            if (visited.count(cur)) continue;
            // 出现重复，即有满足条件的最短路径，结束运行
            if (q2.count(cur)) return ...;
            // 将 cur 的相邻节点加入集合
            for (Node x : cur.adj()) { // cur.adj() 代表其所有邻居
                if (!visited.count(x)) {
                    q_tmp.insert(x);
                }
            } // for end
        } // for end
        // 更新并交换 q1&q2
        q1 = q2;
        q2 = q_tmp;
    } // while end
    // 没有满足条件的路径
    return ...;
}
```





例题

- [111. Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)
- [752. Open the Lock](https://leetcode.com/problems/open-the-lock/)

### 深度优先搜索 Depth First Search, DFS

- 利用栈，当前节点每一个变化、操作，压进栈进行处理（即递归）
- 本质是图的遍历，类似于树的先序遍历
- 适用于：寻找所有方案

```c++
// 递归版本
int DFS(int start, int end) {
    if (start == end): // 类似于访问树的根节点
        return ...;
    for (auto next_start : start.adj()): // 类似于访问根节点的子节点
        BFS(next_start, end);
    // 没有满足条件的路径
    return ...;
}

// 二叉树循环版本
int DFS(TreeNode* root, int target) {
    stack<TreeNode *> s;
    TreeNode *p;

    if (root) s.push(root);
    while (!s.empty()) {
		p = q.back();
		q.pop();
		// 判断是否到达终点
		if (root->val == target) return ...;
		// 将其所有的变化（子节点）压进队列
		if (p->left) s.push(p->left);
		if (p->right) s.push(p->right);
	}
    // 没有满足条件的路径
    return ...;
}
            
// 栈循环版本
int DFS(Node start, Node target) {
    stack<Node> s; // 核心数据结构
    set<Node> visited; // 避免走回头路
    
    s.push(start); // 将起点加入队列
    visited.insert(start);

    while (!s.empty()) {
        /* 将当前队列中的所有节点向四周扩散 */
        Node cur = q.top();
        q.pop();
        
        // 判断是否到达终点
        if (cur == target) return ...
        // 将 cur 的相邻节点加入队列
        for (Node x : cur.adj()) { // cur.adj() 代表其下一个邻居
           if (!visited.count(x)) {
               q.push(x);
               visited.insert(x);
           }
        }
    }
    // 没有满足条件的路径
    return ...;
}
```

详情见 [回溯法](./Back_Tracking_Method.md)