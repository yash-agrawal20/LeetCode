class Solution {
private:
    int f(int l, int b, vector<vector<int>>& grid, vector<vector<int>>& dp){
        
        if(l == 0 && b == 0) return grid[0][0];
        
        else if(l < 0 || b < 0) return 20000;//MAX Value according to constraints
        
        else if(dp[l][b] != -1) return dp[l][b];
        
        int up = grid[l][b] + f(l-1, b, grid, dp);
        int left = grid[l][b] + f(l, b-1, grid, dp);
        
        return dp[l][b] = min(up, left);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        //Memoization Approach
        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return f(m-1, n-1, grid, dp);
        
        //Tabulation Approach
        vector<vector<int>> dp(m,  vector<int> (n, -1));
        
        for(int i = 0; i < m; i++){
            
            for(int j = 0; j < n; j++){
                
                int down = 20000, right = 20000;
                if(i > 0){
                    down = grid[i][j] + dp[i-1][j];
                }
                
                if(j > 0){
                    right = grid[i][j] + dp[i][j-1]; 
                }
                
                dp[i][j] = min(down, right);
                if(i == 0 && j == 0) dp[0][0] = grid[0][0];
            }
        }
        
        return dp[m-1][n-1];
    }
};