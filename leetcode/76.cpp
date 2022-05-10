// v1, > O(N)
class Solution {
public:
    const int MAX_NUM = 100001;
    bool check(unordered_map<char, int> &need, unordered_map<char, int> &window) {
        // check if t is in window(s)
        for (auto &p : need) {
            if (p.second > window[p.first]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int size_win_min = MAX_NUM, i, j;
        string s_min("");
        unordered_map<char, int> need, window;
        
        for (auto c : t) ++need[c];
        const int size_win_init = t.size(); // minimal size of window
        
        int left = 0, right = left+size_win_init-1;
        for (i = left; i <= right; ++i) ++window[s[i]];
        
        while(right < s.size()) {
            // if we need to shrink the size of window 
            if (check(need, window)) {
                // t is in s[left, right]
                if (right-left+1 < size_win_min) {
                    size_win_min = right-left+1;
                    s_min.assign(s, left, size_win_min);
                }
                --window[s[left++]];
            } else {
                // t is not in s[left, right]
                ++window[s[++right]];
            }
        }

        return s_min;
    }
};

// v2 = O(N)
class Solution {
public:
    const int MAX_NUM = 100001;
    string minWindow(string s, string t) {
        int size_win_min = MAX_NUM, valid = 0, left_res;
        int left = 0, right = 0; // valid range of string
        unordered_map<char, int> need, window;

        for (auto c : t) ++need[c];

        while(right < s.size()) {
            if (need.count(s[right])) {
                // only processing character if in "need"
                ++window[s[right]];
                if (window[s[right]] == need[s[right]]) ++valid;
            }
            // if we need to shrink the size of window 
            while (valid == need.size()) {
                if (right-left+1 < size_win_min) {
                    size_win_min = right-left+1;
                    left_res = left;
                }
                if (need.count(s[left])) {
                    // only processing character if in "need"
                    if (window[s[left]] == need[s[left]]) --valid;
                    --window[s[left]];
                }
                ++left;
            }
            ++right;
        }
        return (size_win_min == MAX_NUM) ? "" : s.substr(left_res, size_win_min);
    }
};