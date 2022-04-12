// TLE
int maxEnvelopes(vector<vector<int>>& envelopes) {
	sort(envelopes.begin(), envelopes.end());
	
	int num, max_num = 1;
	int i, j;
	vector<int> memo(envelopes.size(), 1);
	
	for (i = 1; i < envelopes.size(); ++i) {
		for (j = i-1; j >= 0; --j){
			if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
				// We can Russian Doll here.
				memo[i] = (memo[j] + 1 > memo[i]) ? memo[j] + 1 : memo[i];
				if (memo[i] > max_num) max_num = memo[i];
			}
		}
	}
	
	return max_num;
}

// TLE
bool Comp(vector<int> &item1, vector<int> &item2) {
    return (item1[0] == item2[0]) ? (item1[1] > item2[1]) : (item1[0] < item2[0]);
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& E) {
        sort(E.begin(), E.end(), Comp);
        // 找最长递增子列
        vector<int> dp(E.size(), 1);
        int i, j;
        for (i = 1; i < E.size(); i++) {
            for (j = 0; j < i; j++) {
                if (E[i][1] > E[j][1]) {
                    dp[i] = (dp[j]+1 > dp[i]) ? dp[j]+1 : dp[i];
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};