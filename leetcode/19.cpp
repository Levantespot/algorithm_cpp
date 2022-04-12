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

// 单指针遍历两次
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         if (!head) return head;
        
//         size_t size = 0, prev_loc = 0, pos = -1;
//         ListNode *p = head, *tmp;
        
//         // calculate size
//         while (p) {
//             ++size;
//             p = p->next;
//         }
        
//         // reach to previous one
//         prev_loc = size-n;
//         if (prev_loc == 0) {
//             // delete first node
//             return head->next;
//         }
//         // else
//         p = head;
//         for (pos = 1; pos != prev_loc; ++pos) {
//             p = p->next;
//         }
//         if (n == 1) {
//             // delete last node
//             p->next = nullptr;
//         } else {
//             // delete common node
//             p->next = p->next->next;
//         }
//         return head;
//     }
// };

// 双指针同时遍历一次
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        if (!head->next) return head->next;
        
        ListNode *pFast = head, *pSlow = head;
        
        for (int tmp = 0; tmp < n; ++tmp) {
            pFast = pFast->next;
        }
        if (!pFast) {
            // delete first node
            return head->next;
        }
        while (pFast->next) {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        pSlow->next = pSlow->next->next;
        
        return head;
    }
};