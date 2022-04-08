// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.


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