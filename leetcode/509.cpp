class Solution {
public:
    // 递归思路
    // int fib(int n) {
    //     if (n == 0) return 0;
    //     if (n == 1) return 1;
    //     return fib(n-1) + fib(n-2);
    // }
    
    // DP
    int fib(int n) { 
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        int f_n_2 = 0, f_n_1 = 1, f_n;
        for(int i = 2; i <= n; i++) {
            f_n = f_n_2 + f_n_1;
            f_n_2 = f_n_1;
            f_n_1 = f_n;
        }
        return f_n;
    }
};