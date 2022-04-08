#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while (n > 0) {
            sum += n & 1;
            n = n >> 1;
        }
        return sum;
    }
    int hammingWeight_slower(uint32_t n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n = n >> 1;
        }
        return sum;
    }
};

int main () {
    Solution s;
    
    cout << s.hammingWeight_slower(00000000000000000000000000001011) << endl;
    cout << s.hammingWeight_slower(00000000000000000000000010000000) << endl;
    // cout << s.hammingWeight(11111111111111111111111111111101) << endl; // error, constant too big c++
    return 0;
}