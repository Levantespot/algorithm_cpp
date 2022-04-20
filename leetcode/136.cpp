#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};

int main () {
    vector<int> arr1{2,2,1};
    vector<int> arr2{4,1,2,1,2};
    vector<int> arr3{1};
    vector<int> arr4{-1, 1, 1};
    Solution s;
    cout << s.singleNumber(arr1) << endl;
    cout << s.singleNumber(arr2) << endl;
    cout << s.singleNumber(arr3) << endl;
    cout << s.singleNumber(arr4) << endl;
    return 0;
}