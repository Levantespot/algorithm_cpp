/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)  return root;
        queue<Node*> q;
        
        q.push(root);
        
        int size;
        Node *cur, *last;
        while (!q.empty()) {
            size = q.size();
            last = nullptr;
            while (size--) {
                cur = q.front();
                q.pop();
                cur->next = last;
                last = cur;
                if (cur->right) q.push(cur->right);
                if (cur->left) q.push(cur->left);
            }
        }
        
        return root;
    }
};