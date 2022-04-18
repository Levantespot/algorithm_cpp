class Solution {
public:
    const int MAX = 100 * 100 + 1;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> sums(matrix);
        int rows = matrix.size(), cols = matrix[0].size();
        int row, col, col_last_row;
        int tmp_min_sum;
        for (row = 1; row < rows; ++row) {
            for (col = 0; col < cols; ++col) {
                // 对该行每一列的数字计算到它的最小 falling path 之和
                tmp_min_sum = MAX;
                for (col_last_row = col-1; col_last_row < col+2 && col_last_row < cols; col_last_row++) {   // 三个位置计算最小值
                    if (col_last_row < 0) continue;
                    if (sums[row][col] + sums[row-1][col_last_row] < tmp_min_sum) tmp_min_sum = sums[row][col] + sums[row-1][col_last_row];
                }
                sums[row][col] = tmp_min_sum;
            }
        }
        return *min_element(sums[rows-1].begin(), sums[rows-1].end());
    }
};