void initPrefixSum(vector<vector<int>> &matrix) {
    if(matrix.size() == 0) return;
    mat = matrix;
    for(int i=1; i<matrix.size(); i++) mat[i][0] += mat[i-1][0];
    for(int j=1; j<matrix[0].size(); j++) mat[0][j] += mat[0][j-1];
        
    for(int i=1; i<matrix.size(); i++)
    for(int j=1; j<matrix[0].size(); j++) mat[i][j] += (mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1]);
}

int sumRegion(int row1, int col1, int row2, int col2) {
    if(mat.size() == 0) return 0;
    int num = mat[row2][col2];
    int left=0, upper=0, leftupper=0;
        
    if(col1 > 0 && row1 > 0) leftupper = mat[row1-1][col1-1];
    if(col1 > 0) left = mat[row2][col1-1];
    if(row1 > 0) upper = mat[row1-1][col2];
        
    return num - left - upper + leftupper;
}
