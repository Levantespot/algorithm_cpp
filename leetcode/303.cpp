// class NumArray {
// public:
//     NumArray(vector<int>& nums) : data(nums) {
        
//     }
    
//     int sumRange(int left, int right) {
//         int sum = 0;
//         while (left <= right) {
//             sum += data[left];
//             ++left;
//         }
//         return sum;
//     }
    
//     vector<int> data;
// };


// 前缀和
class NumArray {
public:
    vector<int> sums; // 当前元素前序之和
    
    NumArray(vector<int>& nums) {
        sums.push_back(0); // 哨兵
        for (auto num : nums) {
            sums.push_back(sums.back() + num);
        }
    }
    
    int sumRange(int left, int right) {
        return sums[right+1] - sums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */