// 用例都过了但是超时
// class Solution {
// public:
//     vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
//         sort(nums1.begin(), nums1.end());
//         vector<int> res;

//         int left, right, mid, target;
//         for(int idx = 0; idx < nums2.size(); idx++) {

//             target = nums2[idx];
//             left = 0, right = nums1.size()-1;
//             while(left <= right) {
//                 mid = left + (right-left) / 2;
//                 if (nums1[mid] > target) {
//                     right = mid-1;
//                 } else if (nums1[mid] == target) {
//                     left = mid+1;
//                 } else if (nums1[mid] < target){
//                     left = mid+1;
//                 }
//             }

//             if (left == nums1.size()) left=0;
//             res.push_back(nums1[left]);
//             nums1.erase(nums1.begin()+left);
//         }

//         return res;
//     }
// };

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        vector<int> res(nums2);
        sort(nums2.begin(), nums2.end());
        unordered_map<int, vector<int>> m;
        vector<int> unused;

        int p1, p2;
        for (p1 = p2 = 0; p1 < nums1.size(); p1++) {
            if (nums1[p1] > nums2[p2]) {
                m[nums2[p2]].push_back(nums1[p1]);
                p2++;
            } else {
                unused.push_back(nums1[p1]);
            }
        }

        int num;
        for (p2 = 0; p2 < nums2.size(); p2++) {
            if (!m[res[p2]].empty()){
                num = m[res[p2]].back();
                m[res[p2]].pop_back();
                res[p2] = num;
            } else {
                res[p2] = unused.back();
                unused.pop_back();
            }
        }
        return res;
    }
};