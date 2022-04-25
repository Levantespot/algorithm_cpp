class Solution {
public:
    void backTrack(vector<int> &nums, vector<int> &route, int start_idx, int sum, int k, int target, vector<vector<int>> &res) {
        if (route.size() == k && sum == target) {
            res.push_back(route);
            return;
        } 
        if (route.size() == k) return;
        for (int idx = start_idx; idx < nums.size(); ++idx) {
            if (idx != start_idx && nums[idx-1] == nums[idx]) continue;
            if (sum + nums[idx] > target) break;
            route.push_back(nums[idx]);
            backTrack(nums, route, idx+1, sum+nums[idx], k, target, res);
            route.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> route;
        vector<int> nums;
        for (int i = 1; i < 10; ++i) nums.push_back(i);
        backTrack(nums, route, 0, 0, k, n, res);
        
        return res;
    }
};