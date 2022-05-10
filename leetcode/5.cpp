class Solution {
public:
    string Palindrome(const string &s, int left, int right) {
        string s_tmp(s, left, right-left+1);
        while (left > -1 && right < s.size()) {
            if (s[left] != s[right]) break;
            --left;
            ++right;
        }
        if (right-left-1 < 1) {return string("");}
        string res(s, left+1, right-left-1);
        return res;
    }
    string longestPalindrome(string s) {
        string s_max(s, 0, 1), s_tmp;
        for(int i = 1; i < s.size(); ++i) {
            s_tmp = Palindrome(s, i-1, i);
            if (s_tmp.size() > s_max.size()) s_max = s_tmp;
            s_tmp = Palindrome(s, i, i);
            if (s_tmp.size() > s_max.size()) s_max = s_tmp;
        }

        return s_max;
    }
};