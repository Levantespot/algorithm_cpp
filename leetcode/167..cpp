class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> table; // <num, idx>
        vector<int> res(2);
        for (auto iter = numbers.begin(); iter != numbers.end(); ++iter) {
            if (table.find(target - *iter) != table.end()) {
                res[0] = table.find(target - *iter)->second + 1;
                res[1] = iter-numbers.begin() + 1;
                break;
            }
            table.insert({*iter, iter-numbers.begin()});
        }
        return res;
    }
};