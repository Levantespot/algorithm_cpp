/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void postOrder(TreeNode* root, vector<int> &results) {
        if (!root) return;
        postOrder(root->left, results);
        postOrder(root->right, results);
        results.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> results;
        postOrder(root, results);
        return results;
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> results;
        stack<TreeNode*> s;
        TreeNode *p = root, *r = nullptr; // r 指向刚才访问过的右孩子
        
        while(p || !s.empty()) {
            if (p) { // 向左
                s.push(p);
                p = p->left;
            } else { // 向右
                p = s.top();    
                if (p->right && r != p->right) {
                    p = p->right;
                } else {
                    results.push_back(p->val);
                    r = p;
                    s.pop();
                    p = nullptr;
                }
            }
        }
        return results;
    }
};