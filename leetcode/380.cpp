// 不用哈希的方法，没写完，思路应该没问题，但是特别占空间
// const long MAX_SIZE = 1 << 31;
// #define INVALID -1
// #define VALID 1
// class RandomizedSet {
// public:
//     RandomizedSet() {
        
//     }
    
//     bool insert(int val) {
//         if (val >= 0) {
//             if (pos_set[0][val] != VALID) {
//                 pos_set[0][val] = VALID;
//                 pos_set[1][val] = unique.size();
//                 unique.push_back(val);
//                 return true;
//             }
//             return false;
//         } else {
//             if (neg_set[0][val] != VALID) {
//                 pos_set[0][val] = VALID;
//                 pos_set[1][val] = unique.size();
//                 unique.push_back(val);
//                 return true;
//             }
//             return false;
//         }
//     }
    
//     bool remove(int val) {
//         if (m_set[0][val] != INVALID) {
//             m_set[0][val] = INVALID;
//             auto it = unique.begin();
//             advance(it, m_set[1][val]);
//             unique.erase(it);
//             unique true;
//         }
//         return false;
//     }
//     int getRandom() {
//         int r = rand() % unique.size();
//         r = (r == 0) ? 1 : r;
//         auto it = unique.begin();
//         advance(it, r);
//         return (m_set[2][*it] > 0) ? *it : -*it;
//     }
//     int pos_val;
//     list<int> unique; // 使 getRandom() 复杂度为 O(1)
//     // 第 0 行代表是否有效，第 1 行代表该数在 unique 中的位置
//     vector<vector<int>> pos_set{vector<int>(MAX_SIZE, INVALID), vector<int>(MAX_SIZE, INVALID)}; 
//     vector<vector<int>> neg_set{vector<int>(MAX_SIZE, INVALID), vector<int>(MAX_SIZE, INVALID)};
    
// };

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

class RandomizedSet {
public:
    // 存储元素的值
    vector<int> nums;
    // 记录每个元素对应在 nums 中的索引
    unordered_map<int,int> valToIndex;
    
    bool insert(int val) {
        // 若 val 已存在，不用再插入
        if (valToIndex.count(val)) {
            return false;
        }
        // 若 val 不存在，插入到 nums 尾部，
        // 并记录 val 对应的索引值
        valToIndex[val] = nums.size();
        nums.push_back(val);
        return true;
    }
     
    bool remove(int val) {
        // 若 val 不存在，不用再删除
        if (!valToIndex.count(val)) {
            return false;
        }
        // 先拿到 val 的索引
        int index = valToIndex[val];
        // 将最后一个元素对应的索引修改为 index
        valToIndex[nums.back()] = index;
        // 交换 val 和最后一个元素
        swap(nums[index], nums.back());
        // 在数组中删除元素 val
        nums.pop_back();
        // 删除元素 val 对应的索引
        valToIndex.erase(val);
        return true;
    }
    
    int getRandom() {
        // 随机获取 nums 中的一个元素
        return nums[rand() % nums.size()];
    }
};