class Solution {
public:
    // 考虑某个元素，最大递增子列 = each 左边（小于该元素）的递增子列 + 该元素
    const int MAX = 10001;
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> max_sub_len(nums.size(), 1);
        
        // base case
        max_sub_len[0] = 1;
        
        int i, j;
        for (i = 1; i < nums.size(); ++i) {
            for (j = 0; j < i; j++) {
                if (nums[i] > nums[j]){
                    max_sub_len[i] = (max_sub_len[j] + 1 > max_sub_len[i]) ? max_sub_len[j] + 1 : max_sub_len[i];
                }
            }
        }
        
        return *max_element(max_sub_len.begin(), max_sub_len.end());
    }
};