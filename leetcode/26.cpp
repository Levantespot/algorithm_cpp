class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 1, right = 1, valid_num = 1;
        while (right < nums.size()) {
            if (nums[right] != nums[right-1]) {
                nums[left] = nums[right];
                ++left;
                ++valid_num;
            }
            ++right;
        }
        
        return valid_num;
    }
};