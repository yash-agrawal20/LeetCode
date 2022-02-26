class Solution {
private:
    int f(int l, int b, vector<vector<int>> &Grid){
        
        if(l == 0 && b == 0) return 1;
        
        else if(l < 0 || b < 0 || Grid[l][b] == 1) return 0;
        
        int up = f(l-1, b, Grid);
        int left = f(l, b-1, Grid);
        
        return up + left;
    }
    
    int fm(int l, int b, vector<vector<int>> &Grid, vector<vector<int>>& dp){
        
        if(l == 0 && b == 0) return 1;
        
        else if(l < 0 || b < 0 || Grid[l][b] == 1) return 0;
        
        else if(dp[l][b] != -1) return dp[l][b];
        
        int up = fm(l-1, b, Grid, dp);
        int left = fm(l, b-1, Grid, dp);
        
        return dp[l][b] = up + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        
        //Recursion approach (TLE)
        // return f(m-1, n-1, obstacleGrid);
        
        //Memoization Approach
        vector<vector<int>> dp(m, vector<int> (n, -1));
        
        return fm(m-1, n-1, obstacleGrid, dp);
        
    }
};