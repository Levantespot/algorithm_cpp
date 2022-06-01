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
    TreeNode* build(int left, int right, vector<int>& nums) {
        if (left > right) return nullptr;
        if (left == right) return create(nums[left]);
        
        // find max element and index of max element
        int idx = left+1, max = nums[left], idx_max = left;
        while (idx <= right) {
            if (nums[idx] > max) {
                max = nums[idx];
                idx_max = idx;
            }
            idx++;
        }
        
        TreeNode* root = new TreeNode(max);
        root->left = build(left, idx_max-1, nums);
        root->right = build(idx_max+1, right, nums);
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(0, nums.size()-1, nums);
    }
};