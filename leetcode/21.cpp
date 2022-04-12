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

// 复杂，但更快一点
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if (list2 == nullptr || (list1 == nullptr && list2 == nullptr)) {
//             return list1;
//         } else if (list1 == nullptr) {
//             return list2;
//         }
        
//         // 先找到小头的链表
//         ListNode *p1, *p2, *pHead, *pTemp, *pPrev;  // p1->val <= p2->val
//         if (list1->val <= list2->val) {
//             pHead = list1, p1 = list1; p2 = list2;
//         } else {
//             pHead = list2, p1 = list2; p2 = list1;
//         }
//         while (p1->next != nullptr && p2 != nullptr) {
//             if (p2->val <= p1->next->val) {
//                 // 将 p2 插入
//                 pTemp = p1->next;
//                 p1->next = p2;
//                 p2 = p2->next;
//                 p1 = p1->next;
//                 p1->next = pTemp;
//             } else {
//                 // 找下一个位置
//                 p1 = p1->next;
//             }
            
//         }
//         if (p1->next == nullptr) {
//             // p1 的 next 空了，直接连接 p2
//             p1->next = p2;
//         } else {
//             // p2 空了，表示完成
//         }
        
//         return pHead;
//     }
// };

// 简单，但更慢一点
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *pHead = new ListNode(-1);   // 虚拟头节点
        ListNode *p1 = list1, *p2 = list2, *pNow = pHead;
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                pNow->next = p1;
                p1 = p1->next;
            } else {
                pNow->next = p2;
                p2 = p2->next;
            }
            pNow = pNow->next;
        }
        
        if (p1) {
            pNow->next = p1;
        }
        if (p2) {
            pNow->next = p2;
        }
        return pHead->next;
    }
};