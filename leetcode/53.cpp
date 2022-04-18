class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
    //     vector<int> sums(nums); // 存储当前位置最大的子数组之和
    //     for (int i = 1; i < sums.size(); i++) {
    //         sums[i] = (sums[i-1] > 0) ? sums[i] + sums[i-1] : sums[i];
    //         if sums
    //     }
    //     return *max_element(sums.begin(), sums.end());
    // }
    
    // faster and less memory usage
    int maxSubArray(vector<int>& nums) {
        int max_len = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = (nums[i-1] > 0) ? nums[i] + nums[i-1] : nums[i];
            if (nums[i] > max_len) max_len = nums[i];
        }
        return max_len;
    }
};