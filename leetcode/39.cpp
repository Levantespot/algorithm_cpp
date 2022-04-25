class Solution {
public:
    void backTrack(vector<int> &candidates, vector<int> route, int start_idx, int sum, int target, vector<vector<int>> &res) {
        if (sum == target) {
            res.push_back(route);
            return;
        } 
        // else if (sum > target) return;
        // else if (sum < target)
        for (int idx = start_idx; idx < candidates.size(); ++idx) {
            // If "candidates" is sorted, "continue" can be replace with "break"
            if (sum + candidates[idx] > target) continue; // same meaning as the first "else if". 
            route.push_back(candidates[idx]);
            backTrack(candidates, route, idx, sum+candidates[idx], target, res);
            route.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> route;
        
        backTrack(candidates, route, 0, 0, target, res);
        
        return res;
    }
};