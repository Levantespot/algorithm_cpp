class Solution {
public:
    int MAX = 10001;
    
    // f(amount) = f(amount - particular_coin) + 1
    // from top to down, but exceed the time limit.
//     int Re_top2down(vector<int>& coins, int amount, vector<int> &memo) {
//         // base
//         if (amount < 0) return -1;
//         if (amount == 0) return 0;
//         if (memo[amount] != -1) return memo[amount];

//         int num_tmp, min_coins = MAX;
//         for (int coin : coins) {
//             num_tmp = Re_top2down(coins, amount-coin, memo);
//             if (num_tmp >= 0 && num_tmp < min_coins) {
//                 min_coins = num_tmp;
//             }
//         }
//         memo[amount] = (min_coins != MAX) ? min_coins + 1 : -1;
//         return memo[amount];
//     }
    
    // from down to top
    int Re_down2top(vector<int>& coins, int amount, vector<int> &memo) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;
        if (memo[amount] != -1) return memo[amount];    // already calculated
        return -1;  // impossible
    }
    
    int coinChange(vector<int>& coins, int amount) {
        /* from top to down version */
        // vector<int> memo(amount+1, -1);
        // return Re_top2down(coins, amount, memo);
        
        
        /* DP version */
        vector<int> memo(amount+1, -1);   // store min times for the index which stands for amount. -1 denotes impossible (never accessed)
        // base
        memo[0] = 0;
        
        // dp
        int tmp_min, cur_num;
        for (int am = 1; am <= amount; am++) {
            tmp_min = MAX;
            for (int coin : coins) {
                cur_num = Re_down2top(coins, am-coin, memo) + 1;
                if (cur_num > 0) {
                    tmp_min = (cur_num < tmp_min) ? cur_num : tmp_min;
                }
            }
            memo[am] = (tmp_min < MAX) ? tmp_min : -1;  // -1 denotes impossible
        }
        
        return memo[amount];
    }
    

};