class Solution {
public:
    void backTrack(vector<int>& nums, vector<int> &route, int start_idx, int max_len, vector<vector<int>> &res) {
        // base case
        if (route.size() == max_len) {
            res.push_back(route);
            return;
        }
        for (int i = start_idx; i < nums.size(); ++i) {
            route.push_back(nums[i]);
            // backTrack
            backTrack(nums, route, i+1, max_len, res);
            // revert route
            route.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> empty_route;
        
        for (int max_len = 0; max_len <= nums.size(); ++max_len)
            backTrack(nums, empty_route, 0, max_len, res);
        
        return res;
    }
};

// V2
class Solution {
public:
    void backTrack(vector<int>& nums, vector<int> &route, int start_idx, vector<vector<int>> &res) {
        // base case
        res.push_back(route);
        
        for (int i = start_idx; i < nums.size(); ++i) {
            route.push_back(nums[i]);
            // backTrack
            backTrack(nums, route, i+1, res);
            // revert route
            route.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> empty_route;
        
        backTrack(nums, empty_route, 0, res);
        
        return res;
    }
};