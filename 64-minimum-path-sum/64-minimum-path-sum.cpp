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
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return f(m-1, n-1, grid, dp);
        
        //Tabulation Approach
        // vector<vector<int>> dp(m,  vector<int> (n, -1))
    }
};