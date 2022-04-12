/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        int sizeA = 0, sizeB = 0, skip;
        while (pA) {
            pA = pA->next;
            ++sizeA;
        }
        while (pB) {
            pB = pB->next;
            ++sizeB;
        }
        
        skip = sizeA - sizeB;
        pA = headA;
        pB = headB;
        
        if (skip >= 0) { // A is longer than B
            while (skip--) {
                pA = pA->next;
            }
        } else {
            skip = -skip;
            while (skip--) {
                pB = pB->next;
            }
        }
        
        while (pA && pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        if (!pA) {
            return nullptr;
        } else {
            return pA;
        }
    }
};