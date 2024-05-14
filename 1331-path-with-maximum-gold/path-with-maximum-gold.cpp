class Solution {
public:
    // int collectGold(vector<vector<int>> grid, int x, int y, int n, int m, vector<vector<int>> &dp) {
 
    //     // Base condition.
    //     if ((x < 0) || (x == n) || (y == m)) {  
    //         return 0;
    //     }
    
    //     if(dp[x][y] != -1){
    //         return dp[x][y] ;
    //     }
    
    //     // Right upper diagonal
    //     int rightUpperDiagonal = collectGold(grid, x - 1, y + 1, n, m, dp); 
    
    //     // right
    //     int right = collectGold(grid, x, y + 1, n, m, dp);
    
    //     // Lower right diagonal
    //     int rightLowerDiagonal = collectGold(grid, x + 1, y + 1, n, m, dp);  
    
    //     // Return the maximum and store the value
    //     return dp[x][y] = gold[x][y] + max(max(rightUpperDiagonal, rightLowerDiagonal), right);  
    // }
    // int getMaxGold(vector<vector<int>> grid, int n, int m)
    // {
    //     int maxGold = 0;
    //     // Initialize the dp vector
    //     vector<vector<int>> dp(n, vector<int>(m, -1)) ;
    //     for (int i = 0; i < n; i++) {
    
    //         // Recursive function call for  ith row.
    //         int goldCollected = collectGold(grid, i, 0, n, m, dp);  
    //         maxGold = max(maxGold, goldCollected);
    //     }
    
    //     return maxGold;
    // }


    int solve(vector<vector<int>>&grid , int row , int col){
        if(row <0 or col <0 || row >=grid.size() || col >=grid[0].size() || grid[row][col] <= 0){
            return 0;
        }
        grid[row][col] =- grid[row][col];

        int down = solve(grid , row+1 , col);
        int up =   solve(grid , row-1 , col);
        int right =solve(grid , row , col+1);
        int left = solve(grid , row , col-1);

        grid[row][col] =- grid[row][col];

        return grid[row][col] + max(max(left , right) , max(up , down));
    }


    int getMaximumGold(vector<vector<int>>& grid) {
        // int n= grid.size();
        // int m=grid[0].size();
        // return get maxgold((grid , n ,m));

        int ans=0;
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                if(grid[i][j])  ans = max(ans , solve(grid , i , j));
            }
        }
        return ans;
    }
};

