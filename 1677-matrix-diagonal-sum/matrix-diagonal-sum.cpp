class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size();
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += mat[i][i];  // add element on primary diagonal
        if(i != n-i-1) {
            sum += mat[i][n-i-1];  // add element on secondary diagonal (if not part of primary diagonal)
        }
    }
    return sum;
}

};