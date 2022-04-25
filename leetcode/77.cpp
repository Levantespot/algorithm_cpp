class Solution {
public:
    void backTrack(vector<int> &nums, int start_idx, vector<int> &route, vector<vector<int>> &res, int k) {
        if (route.size() == k) {
            res.push_back(route);
            return;
        }
        
        for (int idx = start_idx; idx < nums.size(); ++idx) {
            route.push_back(nums[idx]);
            
            backTrack(nums, idx+1, route, res, k);
            
            route.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; ++i) nums.push_back(i);
        
        vector<int> empty_route;
        vector<vector<int>> res;
        
        backTrack(nums, 0, empty_route, res, k);
        
        return res;
    }
};