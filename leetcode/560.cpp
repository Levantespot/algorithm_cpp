class Solution {
public:
	// O(N^2)
//     int subarraySum(vector<int>& nums, int k) {
//         vector<int> sums; // sums[i] notes sum(nums[0], ... , nums[i])
        
//         int last_sum = 0, count = 0;
//         for (auto num : nums) {
//             last_sum = last_sum + num;
//             sums.push_back(last_sum);
//         }
//         for (auto iter1 = sums.begin(); iter1 != sums.end(); ++iter1) {
//             for (auto iter2 = iter1; iter2 != sums.end(); ++iter2) {
//                 if (*iter2 - *iter1 + nums[iter1 - sums.begin()] == k) ++count;
//             }
//         }
        
//         return count;
//     }

	int subarraySum(vector<int>& nums, int k) {
        vector<int> sums; // sums[i] notes sum(nums[0], ... , nums[i-1])
        map<int, int> m;
        int last_sum = 0, count = 0;
        
        sums.push_back(0); // sums[0] = 0
        m.insert({0, 1});
        
        for (int idx = 1; idx <= nums.size(); ++idx) {
            sums.push_back(sums[idx-1] + nums[idx-1]); // sums[i] = sums[idx-1] + nums[idx-1]
            if (m.count(sums.back() - k)) {
                count += m.find(sums.back() - k)->second; 
            }
            if (m.count(sums.back())) {
                m.find(sums.back())->second += 1;
            } else {
                m.insert({sums.back(), 1});
            }
        }
        return count;
    }
};