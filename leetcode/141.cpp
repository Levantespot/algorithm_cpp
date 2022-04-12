/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 检查是否有重复元素的思路
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         std::set<ListNode *> p_set;
//         ListNode *p = head;
//         bool tag = false;   // no cycle
//         while (p && p->next) {
//             auto ret = p_set.insert(p);
//             if (!ret.second) {
//                 tag = true; // has cycle
//                 break;
//             }
//             p = p->next;
//         }
//         return tag;
//     }
// };

//快慢指针思路
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *pSlow = head, *pFast = head;
        bool tag = false;   // no cycle
        while (pFast && pFast->next) {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
            if (pFast == pSlow) {
                tag = true;
                break;
            }
        }
        return tag;
    }
};