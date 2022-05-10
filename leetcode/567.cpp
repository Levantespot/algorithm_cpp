class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m_t, m_s; // m_t for s1. m_s for s2
        int valid_cnt = 0, max_valid = 0;
        char c_cur; // current char
        
        for (auto c : s1) {
            ++m_t[c];
        }
        for (auto p : m_t) max_valid++;
        
        int left = 0, right = 0; // [left, right)
        while (right < s2.size()) {
            // expand right
            c_cur = s2[right];
            if (m_t.count(c_cur)) {
                m_s[c_cur]++;
                if (m_s[c_cur] == m_t[c_cur]) valid_cnt++;
            }
            right++;
            
            // shrink left
            while (valid_cnt == max_valid) {
                // check
                if (right - left == s1.size()) return true;
                
                c_cur = s2[left];
                if (m_t.count(c_cur)) {
                    if (m_s[c_cur] == m_t[c_cur]) valid_cnt--;
                    m_s[c_cur]--;    
                }
                left++;    
            }
            
        }
        
        return false;
    }
};