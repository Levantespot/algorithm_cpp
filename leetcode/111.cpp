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
    int minDepth(TreeNode* root) {
        queue<TreeNode *> q;
        int count, height = 0;
        TreeNode *p;

        if (root) q.push(root);
        while (!q.empty()) {
            count = q.size();
            ++height;
            while (count--) {
                p = q.front();
                q.pop();
                
                if (!p->left && !p->right) return height;
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
        }
        
        return height;
    }
};