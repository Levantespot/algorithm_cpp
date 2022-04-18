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
    ListNode* reverse_iteratively (ListNode* head) {
        ListNode *p1 = head, *p2 = head->next, *p3;
        p1->next = nullptr;
        while (p2) {
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        return p1;
    }
    
    ListNode* reverse_recursively (ListNode* head) {
        if (!head->next) return head;
        // else
        ListNode *new_head = reverse_recursively(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
    
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        
        // iteratively
        // return reverse_iteratively(head);
        
        // recursively
        return reverse_recursively(head);
    }
};