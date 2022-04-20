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
    bool isPalindrome(ListNode* head) {
        if (!head->next) return head;
        ListNode *p;
        stack<int> s;
        int size, half_size, idx;
        for (size = 0, p = head; p; ++size) p = p->next;
        half_size = size / 2;
        for (idx = 0, p = head; idx < half_size; ++idx) {
            s.push(p->val);
            p = p->next;
        }
        if (size % 2) p = p->next; // 奇数个，跳过中间部分
        for (idx = 0; !s.empty() && p->val == s.top(); p=p->next) s.pop();
        
        return s.empty() ? true : false;
    }
};