/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 是否有重复元素的思路
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         std::set<ListNode *> p_set;
//         ListNode *p = head;
//         while (p && p->next) {
//             auto ret = p_set.insert(p);
//             if (!ret.second) {
//                 return p;
//             }
//             p = p->next;
//         }
//         return nullptr;
//     }
// };

// 快慢指针思路
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *pFast = head, *pSlow = head;
        // first time to encounter
        while (pFast && pFast->next) {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
            if (pSlow == pFast) {
                break;
            }
        }
        if (!pFast || !pFast->next) return nullptr;
        // second time to encounter
        pSlow = head;
        while (pSlow != pFast) {
            pSlow = pSlow->next;
            pFast = pFast->next;
            if (pSlow == pFast) {
                break;
            }
        }
        return pFast;
    }
};