class Solution {
public:
    const int N_USED = -1; // not used
    
    vector<vector<string>> results;
    
    void update_used (vector<vector<int>> &used, int row, int col, int n) {
        for (int offset = 0; offset < n; offset++) {
            if (row+offset<n && col+offset<n && used[row+offset][col+offset] == N_USED) used[row+offset][col+offset] = row;
            if (row+offset<n && col-offset>=0 && used[row+offset][col-offset] == N_USED) used[row+offset][col-offset] = row;
            if (row-offset>=0 && col+offset<n && used[row-offset][col+offset] == N_USED) used[row-offset][col+offset] = row;
            if (row-offset>=0 && col-offset>=0 && used[row-offset][col-offset] == N_USED) used[row-offset][col-offset] = row;

            if (row+offset<n && used[row+offset][col] == N_USED) used[row+offset][col] = row;
            if (row-offset>=0 && used[row-offset][col] == N_USED) used[row-offset][col] = row;
            if (col+offset<n && used[row][col+offset] == N_USED) used[row][col+offset] = row;
            if (col-offset>=0 && used[row][col-offset] == N_USED) used[row][col-offset] = row;
        }
    }

    void revoke_used (vector<vector<int>> &used, int row, int col, int n) {
        for (int offset = 0; offset < n; offset++) {
            if (row+offset<n && col+offset<n && used[row+offset][col+offset] == row) used[row+offset][col+offset] = N_USED;
            if (row+offset<n && col-offset>=0 && used[row+offset][col-offset] == row) used[row+offset][col-offset] = N_USED;
            if (row-offset>=0 && col+offset<n && used[row-offset][col+offset] == row) used[row-offset][col+offset] = N_USED;
            if (row-offset>=0 && col-offset>=0 && used[row-offset][col-offset] == row) used[row-offset][col-offset] = N_USED;

            if (row+offset<n && used[row+offset][col] == row) used[row+offset][col] = N_USED;
            if (row-offset>=0 && used[row-offset][col] == row) used[row-offset][col] = N_USED;
            if (col+offset<n && used[row][col+offset] == row) used[row][col+offset] = N_USED;
            if (col-offset>=0 && used[row][col-offset] == row) used[row][col-offset] = N_USED;
        }
    }
    
    void backTrack(vector<vector<int>> &used, vector<string> &track, int row, int n) {
        if (row == n) {
            results.push_back(track);
            return;
        }
        // else
        for (int col = 0; col < n; ++col) {
            if (used[row][col] == N_USED) {
                // update
                update_used(used, row, col, n);
                string _track(n, '.');
                _track[col] = 'Q';
                track.push_back(_track);
                // backTrack
                backTrack(used, track, row+1, n);
                // revoke updates
                track.pop_back();
                revoke_used(used, row, col, n);
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> used(n, vector<int>(n, N_USED));
        vector<string> empty_track;
        backTrack(used, empty_track, 0, n);
        return results;
    }
};