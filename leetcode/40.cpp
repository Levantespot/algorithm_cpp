class Solution {
public:
    void backTrack(vector<int> &candidates, vector<int> route, int start_idx, int sum, int target, vector<vector<int>> &res) {
        if (sum == target) {
            res.push_back(route);
            return;
        } 
        
        for (int idx = start_idx; idx < candidates.size(); ++idx) {
            if (idx != start_idx && candidates[idx-1] == candidates[idx]) continue;
            if (sum + candidates[idx] > target) break;
            route.push_back(candidates[idx]);
            backTrack(candidates, route, idx+1, sum+candidates[idx], target, res);
            route.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> route;
        sort(candidates.begin(), candidates.end());
        backTrack(candidates, route, 0, 0, target, res);
        
        return res;
    }
};