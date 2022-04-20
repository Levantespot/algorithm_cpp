class NumMatrix {
public:
    vector<vector<int>> sums; // sums[i][j] == 以 (0,0) 为左上角，(i,j) 为右下角所有元素之和
    int max_row, max_col;
    NumMatrix(vector<vector<int>>& matrix) : sums(matrix) {
        max_row = matrix.size();
        max_col = matrix[0].size();
        for (int row = 0; row < max_row; ++row) {
            for (int col = 0; col < max_col; ++col) {
                sums[row][col] = get_val(row, col-1) + get_val(row-1, col) - get_val(row-1, col-1) + matrix[row][col];
            }
        }
    }
    int get_val(int row, int col) {
        if (row < 0 || row >= max_row || col < 0 || col >= max_col) return 0;
        // else
        return sums[row][col];
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return get_val(row2, col2) - get_val(row2, col1-1) - get_val(row1-1, col2) + get_val(row1-1, col1-1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */