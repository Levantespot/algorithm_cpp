/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


// // 返回成员变量 val 最小的 ListNode 的指针
// size_t get_Min(vector<ListNode*>& lists) {
//     size_t loc = -1;
//     int val_min = -10001;
//     for (auto it = lists.begin(); it != lists.end(); ++it) {\
//         if (*it && (loc == -1 || (val_min > (*it)->val))) {
//             // 还没有找到最小的位置，或者当前的值比「记录的最小值」小，更新「记录的最小值」
//             loc = it-lists.begin(); val_min = (*it)->val;
//         }
//     }
//     return loc;
// }

// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode *pHead = new ListNode(-1); // 虚拟头节点
//         ListNode *pNow = pHead;
//         size_t loc = -1;
//         while ((loc = get_Min(lists)) != -1) {
//             pNow->next = lists[loc];
//             pNow = pNow->next;
//             lists[loc] = lists[loc]->next;
//         }
//         pNow = pHead->next;
//         delete pHead;
//         return pNow;
//     }
// };

// 返回成员变量 val 最小的 ListNode 的指针
size_t get_Min(vector<ListNode*>& lists) {
    size_t loc = -1;
    int val_min = -10001;
    for (auto it = lists.begin(); it != lists.end(); ++it) {\
        if (*it && (loc == -1 || (val_min > (*it)->val))) {
            // 还没有找到最小的位置，或者当前的值比「记录的最小值」小，更新「记录的最小值」
            loc = it-lists.begin(); val_min = (*it)->val;
        }
    }
    return loc;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *pHead = new ListNode(-1); // 虚拟头节点
        ListNode *pNow = pHead;
        size_t loc = -1;
        while ((loc = get_Min(lists)) != -1) {
            pNow->next = lists[loc];
            pNow = pNow->next;
            lists[loc] = lists[loc]->next;
        }
        pNow = pHead->next;
        delete pHead;
        return pNow;
    }
};