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
    TreeNode* build(int left1, int left2, int size, vector<int>& preorder, vector<int>& inorder) {
        if (size == 0) return nullptr;
        if (size == 1) return create(preorder[left1]);
        
        TreeNode* root = create(preorder[left1]);
        
        int idx, left_size, right_size;
        for (idx = left2; idx < left2+size; idx++) {
            if (inorder[idx] == root->val) break;
        }
        left_size = idx-left2;
        right_size = size - 1 - left_size;
        root->left = build(left1+1, left2, left_size, preorder, inorder);
        root->right = build(left1+1+left_size, left2+1+left_size, right_size, preorder, inorder);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(0, 0, preorder.size(), preorder, inorder);
    }
};