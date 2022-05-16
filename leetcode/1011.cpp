class Solution {
public:
    const int _max = 500+1;
    bool load_time(long max_weight, int max_days, vector<int> weights) {
        if (max_weight == 0) return _max; // impossible
        
        int day_use = 0, i, j;
        for (i = 0; i < weights.size(); i++) {
            int tmp = 0;
            for(j = i; j < weights.size(); j++) {
                if (tmp + weights[j] > max_weight) {
                    if (j != i) j--;
                    break;
                }
                tmp += weights[j];
            }
            i = j;
            
            day_use++;
        }
        return (day_use <= max_days) ? true : false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()), right = accumulate(weights.begin(), weights.end(), 0), mid;
        bool res;
        while (left <= right) {
            mid = left + (right - left) / 2;
            res = load_time(mid, days, weights);
            if (res) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        
        return left;
    }
};