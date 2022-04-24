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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode *left = head, *right = head->next, *pre_right = head;
        
        while (right) {
            if (pre_right->val != right->val) {
                left->next = right;
                left = left->next;
            }
            pre_right = right;
            right = right->next;
        }
        left->next = nullptr;
        return head;
    }
};