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
    ListNode *lastTail;
    
    ListNode *reverse(ListNode *start, ListNode *end) {
        // 反转 start 到 end 范围内的部分，并返回新的 head
        if (start == end) return start;
        ListNode *p1, *p2, *p3;
        for(p1 = start, p2 = p1->next; p1 != end; ) {
            // 反转两个节点
            p3 = (p2->next) ? p2->next : nullptr;
            p2->next = p1;
            // advance
            p1 = p2;
            p2 = p3;
        }
        start->next = nullptr;
        return p1;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *p1 = head, *p2 = head, *p2_next, *new_head;
        int idx;
        
        for (idx = 1; idx != k && p2->next; ++idx) p2 = p2->next;
        p2_next = p2->next;
        head = reverse(p1, p2);
        lastTail = p1;
        
        while (p2_next) {
            p1 = p2_next; p2 = p2_next;
            for (idx = 1; idx != k && p2->next; ++idx) p2 = p2->next;
            if (idx != k) break; // 不够 k 个，结束
            p2_next = p2->next;
            new_head = reverse(p1, p2);
            lastTail->next = new_head;
            lastTail = p1;
        }
        if (idx != k) {
            lastTail->next = p1;
        }
        
        return head;
    }
};