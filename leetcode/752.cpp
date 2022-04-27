class Solution {
public:
    void add(string &s, int idx) {
        if (s[idx] == '9') s[idx] = '0';
        else s[idx] += 1;
    }
    void sub(string &s, int idx) {
        if (s[idx] == '0') s[idx] = '9';
        else s[idx] -= 1;
    }

    // v1 BFS
    int openLock(vector<string>& deadends, string target) {
        set<string> set_accessed(deadends.begin(), deadends.end());
        queue<string> Q;
        string s = string("0000");
        int count, idx; // tmp
        int times = 0;
        
        // base case
        if (set_accessed.count(s)) return -1; // impossible

        Q.push(s);
        set_accessed.insert(s);
        
        // BFS
        while(!Q.empty()) {
            count = Q.size();
            while(count--) {
                s = Q.front();
                Q.pop();
                
                if (s == target) return times;
                
                for (idx = 0; idx < s.size(); ++idx) {
                    add(s, idx);
                    if (!set_accessed.count(s)){
                        Q.push(s);
                        set_accessed.insert(s);
                    }
                    sub(s, idx);
                    
                    sub(s, idx);
                    if (!set_accessed.count(s)){
                        Q.push(s);
                        set_accessed.insert(s);
                    }
                    add(s, idx);
                }
            }
            ++times;
        }
        
        // impossible
        return -1;
    }

    // v2 bi-BFS
    int openLock(vector<string>& deadends, string target) {
        set<string> visited(deadends.begin(), deadends.end());
        
        set<string> q1, q2, q_tmp; // q1 存储当前需要扩展的结果，q2 存储从另一个方向扩展的结果
        
        int times = 0;
        q1.insert(string("0000"));
        q2.insert(target);
        
        // Bi-BFS
        while(!q1.empty() && !q2.empty()) {
            q_tmp.erase(q_tmp.begin(), q_tmp.end());
            // 将 q1 所有元素变化一次
            for(auto &_s : q1) {
                if (visited.count(_s)) continue;
                if (q2.count(_s)) return times;
                string s(_s);
                visited.insert(s);
                
                for (int idx = 0; idx < s.size(); ++idx) {
                    add(s, idx);
                    if (!visited.count(s)){
                        q_tmp.insert(s);
                    }
                    sub(s, idx);
                    
                    sub(s, idx);
                    if (!visited.count(s)){
                        q_tmp.insert(s);
                    }
                    add(s, idx);
                }
            }
            ++times;
            q1 = q2;
            q2 = q_tmp;
        }
        
        // impossible
        return -1;
    }
};