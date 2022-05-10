class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> m_p, m_s;
        int valid_cnt = 0, max_valid = 0;
        char c_cur; // current char
        vector<int> res;
        
        for (auto c : p) {
            ++m_p[c];
        }
        for (auto p : m_p) max_valid++;
        
        int left = 0, right = 0; // [left, right)
        while (right < s.size()) {
            // expand right
            c_cur = s[right];
            if (m_p.count(c_cur)) {
                m_s[c_cur]++;
                if (m_s[c_cur] == m_p[c_cur]) valid_cnt++;
            }
            right++;
            
            // shrink left
            while (valid_cnt == max_valid) {
                // check
                if (right - left == p.size()) res.push_back(left);
                
                c_cur = s[left];
                if (m_p.count(c_cur)) {
                    if (m_s[c_cur] == m_p[c_cur]) valid_cnt--;
                    m_s[c_cur]--;
                }
                left++;
            }
            
        }
        
        return res;
    }
};