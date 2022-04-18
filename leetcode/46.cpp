class Solution {
public:
    vector<vector<int>> result;
//     void backTrack (vector<int> &choices, vector<int> &track) {
//         if (choices.size() == 1) {
//             track.push_back(choices[0]);
//             result.push_back(track);
//             return;
//         }
        
//         for (auto c : choices) {
//             // create a new choices set without the current choice
//             vector<int> new_choices;
//             for (auto i : choices) {
//                 if (i != c) new_choices.push_back(i);
//             }
//             // create a new track appending the current choice
//             vector<int> new_track(track);
//             new_track.push_back(c);
            
//             backTrack(new_choices, new_track);
//         }
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<int> full_choices(nums);
//         vector<int> empty_track;
//         backTrack(full_choices, empty_track);
        
//         return result;
//     }
    
    // V2
    // Add a used parameter to track which member in choices are used
    // Add canceling choice part
    void backTrack (vector<int> &choices, vector<int> &track, vector<bool> &used) {
        // update result when satisfied
        if (choices.size() == track.size()) {
            result.push_back(track);
            return;
        }
        
        int i;  // idx
        for (i = 0; i < choices.size(); ++i) {
            if (used[i]) continue;
            
            // update "track" and "used"
            track.push_back(choices[i]);
            used[i] = true;
            backTrack(choices, track, used);
            
            // canceling choice
            track.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> empty_track;
        vector<bool> used(nums.size(), false);
        backTrack(nums, empty_track, used);
        
        return result;
    }
};