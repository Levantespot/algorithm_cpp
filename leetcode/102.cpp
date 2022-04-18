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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        vector<int> tmp;
        deque<TreeNode*> q1, q2;
        TreeNode *p = nullptr;
        
        if (root) q1.push_back(root);
        
        while (!q1.empty() || !q2.empty()) {
            while(!q1.empty()) {
                p = q1.front();
                tmp.push_back(p->val);
                q1.pop_front();
                
                if (p->left) q2.push_back(p->left);
                if (p->right) q2.push_back(p->right);
            }
            if (!tmp.empty()) {
                results.push_back(tmp); 
                tmp.clear();
            }
            
            while(!q2.empty()) {
                p = q2.front();
                tmp.push_back(p->val);
                q2.pop_front();
                
                if (p->left) q1.push_back(p->left);
                if (p->right) q1.push_back(p->right);
            }
            if (!tmp.empty()) {
                results.push_back(tmp); 
                tmp.clear();
            }
        }
        return results;
    }
};