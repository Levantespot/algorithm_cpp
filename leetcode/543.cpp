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
    int max_d = 0;
    int traverse(TreeNode* root) {
        // if (!root->right && !root->left) return 1;
        if (!root) return 0;
        size_t l_depth, r_depth;
        l_depth = traverse(root->left);
        r_depth = traverse(root->right);
        if (l_depth + r_depth > max_d) max_d = l_depth + r_depth;
        return (l_depth > r_depth) ? l_depth+1 : r_depth+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root);
        return max_d;
    }
};