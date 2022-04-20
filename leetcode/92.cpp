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
    
//     ListNode *recursion(ListNode *head) {
//         // 将当前 head 指向的链表反转，并返回头节点
//         // base case 只有一个节点，不用反转，直接返回
//         if (!head->next) return head;

//         // 转化为递归后续的链表
//         ListNode *new_head = recursion(head->next);
//         head->next->next = head;
//         head->next = nullptr;
//         return new_head;
//     }

//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         if (!head->next || left == right) return head;
//         // 找到并记录不需要反转的部分
//         ListNode *p1, *p2, *p_re;
//         int i, size;
//         for (size = 0, p1 = head; p1; p1 = p1->next) size++;

//         if (left == 1 && right == size) {
//             return recursion(head);
//         } else if (left == 1) {
//             for (i = 1, p2 = head; i != right && p2; i++) p2 = p2->next; // 找到反转末尾
//             p_re = p2;
//             p2 = p2->next; // 记录不变的后边
//             p_re->next = nullptr;
//             p_re = head; // 记录一下头，因为头反转后会变成尾
//             head = recursion(head);
//             p_re->next = p2;
//             return head;
//         } else if (right == size) {
//             for (i = 1, p1 = head; i != left-1 && p1; i++) p1 = p1->next; // 找到反转头部的前一个
//             p1->next = recursion(p1->next);
//             return head;
//         } else {
//             for (i = 1, p1 = head; i != left-1 && p1; i++) p1 = p1->next; // 找到反转头部的前一个
//             for (i = 1, p2 = head; i != right && p2; i++) p2 = p2->next; // 找到反转末尾
//             // 改造一下反转末尾，将其 next 指针置为 null
//             p_re = p2;  // 暂时存储
//             p2 = p2->next; // 反转尾部的下一个
//             p_re->next = nullptr; // 截断
//             // 反转中间部分
//             p_re = recursion(p1->next);
//             // 拼接头和尾
//             p1->next->next = p2;
//             p1->next = p_re;

//             return head;
//         }
    
    // 修改 small_recursion，不把末尾置为 nullptr，还可以再优化，
    
    ListNode *small_recursion(ListNode *head) {
        // 将当前 head 指向的链表反转，并返回头节点
        // base case 只有一个节点，不用反转，直接返回
        if (!head->next) return head;

        // 转化为递归后续的链表
        ListNode *new_head = small_recursion(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
    ListNode *recursion(ListNode *head, int left, int right) {
        // 将当前 head 指向的 left 到 right 范围内的链表反转，并返回头节点
        // base case
        if (left == 1) {
            // 1. 找到 right，看看后面有没有，还有的话就记录，等反转后接上
            // 2. 反转从头到 right 的部分
            // 3. 接上后面部分，如果还有的话
            ListNode *p1 = head, *p2 = nullptr, *pHead;
            for (int i = 1; i != right; i++) p1 = p1->next; 
            if (p1->next) p2 = p1->next;
            p1->next = nullptr; // 截断
            pHead = head; // 记录一下头，反转后就变成尾
            head = small_recursion(head);
            if (p2) pHead->next = p2;
            return head;
        }
        // else
        ListNode *new_head = head;
        new_head->next = recursion(head->next, left-1, right-1);
        return new_head;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head->next || left == right) return head;
        
        return recursion(head, left, right);
    }
};