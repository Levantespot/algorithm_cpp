class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = 0, valid_num = 0;
        while (right < nums.size()) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                ++left;
                ++valid_num;
            }
            ++right;
        }
        
        return valid_num;
    }
};