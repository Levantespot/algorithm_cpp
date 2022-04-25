class Solution {
public:
    // v1
    void backTrack(vector<int>& nums, vector<int> &route, int start_idx, set<vector<int>> &res_set) {
        // base case
        vector<int> new_route(route);
        sort(new_route.begin(), new_route.end());
        res_set.insert(new_route);
        
        for (int i = start_idx; i < nums.size(); ++i) {
            route.push_back(nums[i]);
            // backTrack
            backTrack(nums, route, i+1, res_set);
            // revert route
            route.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res_set;
        vector<vector<int>> res;
        vector<int> empty_route;
        
        backTrack(nums, empty_route, 0, res_set);
        
        for (auto &v : res_set) {
            res.push_back(v);
        }
        
        return res;
    }

    // v2
    const int IMPOSSIBLE = -11;
    void backTrack(vector<int>& nums, vector<int> &route, int start_idx, vector<vector<int>> &res) {
        // base case
        
        res.push_back(route);
        
        // int last_val = IMPOSSIBLE;
        
        for (int i = start_idx; i < nums.size(); ++i) {
            // pruning
            // if (nums[i] == last_val) continue;
            // or
            if (i > start_idx && nums[i] == nums[i-1]) continue;
            
            route.push_back(nums[i]);
            // last_val = nums[i];
            // backTrack
            backTrack(nums, route, i+1, res);
            // revert route
            route.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> empty_route;
        backTrack(nums, empty_route, 0, res);

        return res;
    }
};