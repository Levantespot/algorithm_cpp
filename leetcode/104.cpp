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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        // if (!root->left && !root->right) return 1;
        size_t left_depth = maxDepth(root->left);
        size_t right_depth = maxDepth(root->right);
        return (left_depth >= right_depth) ? left_depth+1 : right_depth+1;
    }
};