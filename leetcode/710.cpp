class Solution {
public:
    Solution(int _n, vector<int>& blacklist) {
        n = _n;
        bl.insert(blacklist.begin(), blacklist.end());
        if (blacklist.size() > _n/2) {
            for (int i = 0; i < _n; i++) {
                if (!bl.count(i)) wl.insert(i);
            }
        }
    }
    
    int pick() {
        int r;
        
        if (!wl.empty()) {
            r = rand() % wl.size();
            auto it = wl.begin();
            advance(it, r);
            return *it;
        }
        
        do {
            r = rand() % n;
        } while (bl.count(r));
        return r;
    }
    int n;
    set<int> bl; // backlist
    set<int> wl; // whitelist
};