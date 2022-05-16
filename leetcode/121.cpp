class Solution {
public:
    int maxProfit_k(int k, vector<int>& prices) {
        // memory optimization version
        int n = prices.size();
        // special case
        if (n < 2 || k == 0) return 0;

        // mem[i-1][j-1] 表示在 j 天进行 i 次交易的最高利润, j >= i
        // i%2==0 表示买，i%2==1 表示卖
        // 状态转移方程
        // 买: mem[i][i] = mem[i-1][i-1] - prices[i];    j>i: mem[i][j] = max(mem[i-1][j-1] - prices[j], mem[i][j-1])
        // 卖: mem[i][i] = mem[i-1][i-1] + prices[i];    j>i: mem[i][j] = max(mem[i-1][j-1] + prices[j], mem[i][j-1])
        vector<vector<int>> mem(2, vector<int>(n, 0)); // 只保存两行，后续依次覆盖

        int trans, day, profit=0;
        // base case
        mem[0][0] = -prices[0];
        for (day = 1; day < n; day++) mem[0][day] = (mem[0][day-1] > -prices[day]) ? mem[0][day-1] : -prices[day];

        for (trans = 0; trans+1 < 2*k && trans+1 < n; trans+=1) {
            // 以两次交易为一个单位，即：买一次 + 卖一次

            mem[0][trans] = (trans == 0) ? -prices[0] : mem[1][trans-1] - prices[trans];

            // 买 pass when trans == 0
            for (day = trans+1; trans && day < n; day++) {
                mem[0][day] = max(mem[1][day-1] - prices[day], mem[0][day-1]);
            }
            // 卖
            trans += 1;
            mem[1][trans] = mem[0][trans-1] + prices[trans];
            profit = (profit > mem[1][trans]) ? profit : mem[1][trans];
            for (day = trans+1; day < n; day++) {
                mem[1][day] = max(mem[0][day-1] + prices[day], mem[1][day-1]);
                profit = (profit > mem[1][day]) ? profit : mem[1][day];
            }
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return maxProfit_k(1, prices);
    }
};