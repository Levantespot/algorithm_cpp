# 树 Tree

## 二叉树 Binary Tree



### 前序遍历

- 先访问根节点，且只在第一次访问时访问值；
- 可以使用栈代替递归方法

```c++
/* Recursive way */
void preorderHelper(TreeNode *node){
    if(node == nullptr) return;
    result.push_back(node->val);
    preorderHelper(node->left);
    preorderHelper(node->right);
}

/* Iterative way 1 */
// 思路是，只要当前节点非空，就把其左孩子依次入栈；空则转向空节点的父亲节点的右孩子，重复之前的操作。
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode *p;

    p = root; // 首先指向根节点
    while (p || !s.empty()) {
        if (p) { // 当 p 非空，才入栈、输出、并指向左节点，通过这一步可以把左节点全压入栈
            s.push(p);
            result.push_back(p->val);
            p = p->left;
        } else { // p 为空了，说明父亲节点没有左孩子了，转向其右孩子，并弹出父节点
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
    return result;
}

/* Iterative way 2 */
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    stack<TreeNode*> s;

    TreeNode *p;
    s.push(root);
    while (!s.empty()) {
        p = s.top();
        s.pop();

        result.push_back(p->val);
        // 先压入右节点，再压入左节点，非常巧妙。
        if (p->right) s.push(p->right);
        if (p->left) s.push(p->left);
    }
    return result;
}
```



### 中序遍历

- 先左节点，再根节点，最后右节点
- 在第二次访问节点时才访问值
- 可以用栈实现非递归算法

```c++
/* 递归算法 */
void inOrder(TreeNode* root, vector<int> &results) {
    if (!root) return;
    inOrder(root->left, results);
    results.push_back(root->val);
    inOrder(root->right, results);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> results;
    inOrder(root, results);
    return results;
}

/* 循环算法 1 */
// 和先序的区别在于访问节点值的时机、
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> results;
    stack<TreeNode*> s;
    TreeNode *p = root;

    while(p || !s.empty()){
        if (p) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            results.push_back(p->val);
            s.pop();
            p = p->right;
        }
    }

    return results;
}
```



### 后序遍历

- 先左节点，再右节点，最后根节点
- 在第三次访问节点时才访问值
- 可以用栈实现非递归算法

```c++
/* 递归算法 */
void postOrder(TreeNode* root, vector<int> &results) {
    if (!root) return;
    postOrder(root->left, results);
    postOrder(root->right, results);
    results.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> results;
    postOrder(root, results);
    return results;
}

/* 循环算法 1 */
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> results;
    stack<TreeNode*> s;
    TreeNode *p = root, *r = nullptr; // r 指向刚才访问过的右孩子

    while(p || !s.empty()) {
        if (p) { // 向左
            s.push(p);
            p = p->left;
        } else { // 向右
            p = s.top();    
            if (p->right && r != p->right) {
                p = p->right;
            } else {
                results.push_back(p->val);
                r = p;
                s.pop();
                p = nullptr;
            }
        }
    }
    return results;
}
```



### 层序遍历

- 不用区分层级
  - 可以用一个队列实现循环算法

- 需要区分层级
  - 可以用一个队列+记录每一层个数的方法实现循环算法
  - 两个队列实现循环算法


```c++
vector<int> levelOrder(TreeNode* root) {
    vector<int> results;
    deque<TreeNode*> q;
    TreeNode *p = nullptr;
    while (!q.empty()) {
        p = q.front();
        q.pop_front();
        if (p) {
            if (p->left) q.push_back(p->left);
            if (p->right) q.push_back(p->right);
            results.push_back(p->val);
        }
    }

    return results;
}

vector<int> levelOrder(TreeNode* root) {
    vector<int> results;
    deque<TreeNode*> q;
    int count;
    TreeNode *p = nullptr;
    
    if (root) q.push_back(root);
    
    while (!q.empty()) {
        count = q.size(); // 当前层的节点个数
        while (count--) {
            p = q.front();
            results.push_back(p->val);
            q.pop_front();
            if (p->left) q.push_back(p->left);
            if (p->right) q.push_back(p->right);
        }
    }

    return results;
}
```



## 二叉堆 Binary Heap

二叉堆 (binary heap) 是一种特殊的堆，二叉堆是完全二叉树或者是近似完全二叉树。二叉堆满足堆特性：父节点的键值总是保持固定的序关系于任何一个子节点的键值，且每个节点的左子树和右子树都是一个二叉堆。

当父节点的键值总是大于或等于任何一个子节点的键值时为“最大堆”。当父节点的键值总是小于或等于任何一个子节点的键值时为“最小堆”。

适用情形：

- 需要很方便地获取最大、最小值
- 增删元素后，重排序代价小

### 创建堆

有两种方式创建堆

- `std::make_heap` 需要手动可以访问堆中的任意元素，可以改变有序状态，可以在任何提供随机访问迭代器的序列容器中创建堆
- `std::priority_queue` 优先级队列，可以自动保持元素的顺序，只能访问第一个元素，不能改变有序状态

```c++
/* 使用 make_heap 创建堆 */

std::vector<double> heap{2.5,10.0,3.5,6.5,8.0,12.0,1.5,6.0};
std::vector<double> min_heap(heap);
std::vector<double> max_heap(heap);
// 默认大顶堆 12 10 3.5 6.5 8 2.5 1.5 6
std::make_heap(max_heap.begin(), max_heap.end());
// 大顶堆 12 10 3.5 6.5 8 2.5 1.5 6
std::make_heap(max_heap.begin(), max_heap.end(), std::less<double>());
// 小顶堆 1.5 6 2.5 6.5 8 12 3.5 10
std::make_heap(min_heap.begin(), min_heap.end(), std::greater<double>());

// 字符串
std::vector<std::string> heap{"B", "C", "A", "D"};
std::vector<std::string> min_heap(heap);
std::vector<std::string> max_heap(heap);
// 大顶堆 D C A B
std::make_heap(max_heap.begin(), max_heap.end());
// 小顶堆 A C B D
std::make_heap(min_heap.begin(), min_heap.end(), std::greater<std::string>());
```

```c++
/* 使用 priority_queue 创建堆 */

pass
```

### 堆操作

```c++
/* make_heap 创建的堆 */

// 插入元素
max_heap.push_heap(11); // 在序列末尾添加元素 {12 10 3.5 6.5 8 2.5 1.5 6 11}
std::push_heap(max_heap.begin(), max_heap.end()); // 恢复堆的排序 {12 11 3.5 10 8 2.5 1.5 6 6.5}
std::push_heap(max_heap.begin(), max_heap.end(), std::less<double>()); // 恢复堆的排序 {12 11 3.5 10 8 2.5 1.5 6 6.5}

// 删除元素
std::pop_heap(max_heap.begin(), max_heap.end()); // 将第一个元素移到最后，并保证剩下的元素仍然是一个堆 {10 8 3.5 6.5 6 2.5 1.5 12}
std::pop_heap(max_heap.begin(), max_heap.end(), std::less<double>());  // 将第一个元素移到最后，并保证剩下的元素仍然是一个堆 {10 8 3.5 6.5 6 2.5 1.5 12}
max_heap.pop_back(); // 移除最后一个元素 {10 8 3.5 6.5 6 2.5 1.5}

// 检查是否是堆
std::is_heap(max_heap.begin(), max_heap.end(), std::less<double>());
```

