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
    TreeNode* create(int val) {
        TreeNode* root = new TreeNode();
        root->val = val;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    TreeNode* build(int left1, int left2, int size, vector<int>& inorder, vector<int>& postorder) {
        if (size == 0) return nullptr;
        if (size == 1) return create(inorder[left1]);
        
        TreeNode* root = create(postorder[left2+size-1]);
        
        int idx, left_size, right_size;
        for (idx = left1; inorder[idx] != root->val; idx++) ; // empty statement
        left_size = idx-left1;
        right_size = size - 1 - left_size;
        root->left = build(left1, left2, left_size, inorder, postorder);
        root->right = build(left1+1+left_size, left2+left_size, right_size, inorder, postorder);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(0, 0, inorder.size(), inorder, postorder);
    }
};