class Solution {
public:
    void backTrack(vector<int>& nums, vector<int> &route, vector<int> &used, vector<vector<int>> &res) {
        if (route.size() == nums.size()) {
            res.push_back(route);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] != 0) continue;
            // used[i] == 0
            if (i != 0 && nums[i-1] == nums[i] && used[i-1] == 0) continue;
            used[i] = 1;
            route.push_back(nums[i]);
            
            backTrack(nums, route, used, res);
            
            used[i] = 0;
            route.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> route;
        vector<vector<int>> res;
        vector<int> used(nums.size(), 0);
        
        backTrack(nums, route, used, res);
        
        return res;
    }
};