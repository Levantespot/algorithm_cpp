class Solution {
public:
    int min_max_sum = 1e9;
    // return nums of splitted subarrays with `thresh` threshould 
    bool split(int thresh, vector<int> &nums, int m) {
        int tmp_max_sum = 0, tmp_sum = 0, piles = 0;
        for(auto num : nums) {
            if (num > thresh) {
                tmp_sum = (tmp_sum > num) ? tmp_sum : num;
                tmp_max_sum = (tmp_sum > tmp_max_sum) ? tmp_sum : tmp_max_sum;
                piles+=2; // splitting 2 piles
                tmp_sum = 0;
            } else {
                tmp_sum += num;
                if(tmp_sum > thresh) {
                    tmp_sum -= num;
                    tmp_max_sum = (tmp_sum > tmp_max_sum) ? tmp_sum : tmp_max_sum;
                    tmp_sum = num;
                    piles++; // splitting 1 piles
                } 
            }
        }

        if (tmp_sum != 0) {
            tmp_max_sum = (tmp_sum > tmp_max_sum) ? tmp_sum : tmp_max_sum;
            piles++;
        }
        // 相等时才更新最小的区块最大和
        min_max_sum = tmp_max_sum;
        return (piles <= m) ? true : false;
    }

    int splitArray(vector<int>& nums, int m) { // right-hand boundary
        int left = 1, right = accumulate(nums.begin(), nums.end(), 0), mid;
        bool nog;
        while (left <= right) {
            mid = left + (right-left) / 2;
            nog = split(mid, nums, m);
            if (nog) { // pile 少了，说明 mid 大了 || 尝试使用更小的 mid，以此降低 min_max_sum；
                right = mid-1;
            } else { // pile 多了，说明 mid 大了
                left = mid+1;
            }
        }
        split(left, nums, m);
        return min_max_sum;
    }
};