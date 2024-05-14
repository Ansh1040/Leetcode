class Solution {
public:
    int matrixScore(vector<vector<int>>& a) {
        int row = a.size();
        int col = a[0].size();
        int res = (1<<(col-1))*row;
        for(int i=1;i<col;i++) {
            int curr=0;
            for(int j=0;j<row;j++) {
                if(a[j][i]==a[j][0])curr++;
            }
            res += (1<<(col-i-1))*max(curr, row-curr);
        }
        return res;
    }
};