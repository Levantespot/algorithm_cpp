# 思考与总结



**使用递归的算法中：DFS 、动态规划、回溯法、贪心、分治之间的关系**

- 递归就是自我调用，经常作为一种编程的实现方式。
- 在 DFS，你要退一步，就必然需要保存你走过每个点的所有信息，而且是又先后顺序的，符合后进先出的规则，那么就需要用一个栈，而递归过程中函数调用会自动产生栈帧。而在退一步的过程中，你需要从当前状态回到之前的状态，那么这步操作就是回溯中的撤销选择操作，回溯是递归的时候一定会产生的很自然的操作，只不过大部分情况下不需要回溯。
- 动态规划是用来处理具有最优子结构问题的方法，具有此性质的问题均可以使用分治来解决
- 贪心则是使用递归的方式（可以不用递归）每一次取当前最优值。
- 分治强调将原问题分成几部分，对每一部分递归处理。动态规划与贪心可以看作分治的特例：
  - 动态规划：先将原问题分成两部分，直接解决第一部分，再递归治理第二部分
  - 贪心：先将原问题分成几部分，取局部最优的部分先解决，再递归治理剩余部分
- 回溯法本质是穷举，把问题分步解决，在每一步都试验所有的可能，当发现已经找到一种方式或者目前这种方式不可能是结果的时候，退回上一步继续尝试其他可能。很多时候每一步的处理都是一致的，这时候用递归来实现就很自然。当回溯用于树和图的时候，就是 DFS。

Ref

- [DFS 、动态规划、回溯法、递归之间的关系是什么？- 知乎](https://www.zhihu.com/question/266403334)