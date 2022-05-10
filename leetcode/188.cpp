class Solution {
public:
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    // special case
    if (n < 2 || k == 0) return 0;

    // mem[i-1][j-1] 表示在 j 天进行 i 次交易的最高利润, j >= i
    // i%2==0 表示买，i%2==1 表示卖
    // 状态转移方程
    // 买: mem[i][i] = mem[i-1][i-1] - prices[i];    j>i: mem[i][j] = max(mem[i-1][j-1] - prices[j], mem[i][j-1])
    // 卖: mem[i][i] = mem[i-1][i-1] + prices[i];    j>i: mem[i][j] = max(mem[i-1][j-1] + prices[j], mem[i][j-1])
    vector<vector<int>> mem(2*k, vector<int>(n, 0));

    int trans, day, profit=0;
    // base case
    mem[0][0] = -prices[0];
    for (day = 1; day < n; day++) mem[0][day] = (mem[0][day-1] > -prices[day]) ? mem[0][day-1] : -prices[day];
    
    for (trans = 0; trans+1 < 2*k && trans+1 < n; trans+=1) {
        // 以两次交易为一个单位，即：买一次 + 卖一次

        mem[trans][trans] = (trans == 0) ? -prices[0] : mem[trans-1][trans-1] - prices[trans];

        // 买 pass when trans == 0
        for (day = trans+1; trans && day < n; day++) {
            mem[trans][day] = max(mem[trans-1][day-1] - prices[day], mem[trans][day-1]);
        }
        // 卖
        trans += 1;
        mem[trans][trans] = mem[trans-1][trans-1] + prices[trans];
        profit = (profit > mem[trans][trans]) ? profit : mem[trans][trans];
        for (day = trans+1; day < n; day++) {
            mem[trans][day] = max(mem[trans-1][day-1] + prices[day], mem[trans][day-1]);
            profit = (profit > mem[trans][day]) ? profit : mem[trans][day];
        }
        // print_vv(mem);
    }
    return profit;
}
    
//     int maxProfit(int k, vector<int>& prices) {
        
//     }
};