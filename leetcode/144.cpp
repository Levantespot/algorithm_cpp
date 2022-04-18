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
    /* Recursive way */
    void preOrder(TreeNode* root, vector<int> &result){
        if (!root) return;
        result.push_back(root->val);
        
        preOrder(root->left, result);
        preOrder(root->right, result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preOrder(root, result);
        
        return result;
    }
    
    /* Iterative way 1 */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        stack<TreeNode*> s;
        
        TreeNode *p;
        s.push(root);
        while (!s.empty()) {
            p = s.top();
            s.pop();
            
            result.push_back(p->val);
            
            if (p->right) s.push(p->right);
            if (p->left) s.push(p->left);
        }
        return result;
    }
    
    /* Iterative way 2 */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode *p;
        
        p = root;
        while (p || !s.empty()) {
            if (p) {
                s.push(p);
                result.push_back(p->val);
                p = p->left;
            } else {
                p = s.top()->right;
                s.pop();
            }
        }
        return result;
    }
};