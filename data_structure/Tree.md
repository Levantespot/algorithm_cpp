# 树 Tree

## 二叉树 Binary Tree



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

