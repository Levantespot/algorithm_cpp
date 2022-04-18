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
//     void inOrder(TreeNode* root, vector<int> &results) {
//         if (!root) return;
//         inOrder(root->left, results);
//         results.push_back(root->val);
//         inOrder(root->right, results);
//     }
    
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> results;
//         inOrder(root, results);
//         return results;
//     }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> results;
        stack<TreeNode*> s;
        TreeNode *p = root;
        
        while(p || !s.empty()){
            if (p) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                results.push_back(p->val);
                s.pop();
                p = p->right;
            }
        }
        
        return results;
    }
};