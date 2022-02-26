class Solution {
private:
    int totalPaths(int l, int b){
        
        //Base Case
        if(l == 0 && b == 0) return 1;
        
        else if(l < 0 || b < 0) return 0;
        
        //Stuff
        int up = totalPaths(l-1, b);
        int left = totalPaths(l, b-1);
        
        return up + left;
    }
    
    int totalPathsm(int l, int b, vector<vector<int>> &dp){
        
        if(l == 0 && b == 0) return 1;
        
        else if(l < 0 || b < 0) return 0;
        
        else if(dp[l][b] != -1) return dp[l][b];
        
        int up = totalPathsm(l-1, b, dp);
        int left = totalPathsm(l, b-1, dp);
        
        return dp[l][b] = up + left;
    }

public:
    int uniquePaths(int m, int n) {
        
        //Recursion Approach
        // return totalPaths(m-1, n-1);
        
        //Memoization Approach
        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return totalPathsm(m-1, n-1, dp);
        
        //Tabulation Approach
        vector<vector<int>> dp(m, vector<int> (n, -1));
        
        for(int i = 0; i < m; i++){
            
            for(int j = 0; j < n; j++){
                
                if(i == 0 && j == 0) dp[0][0] = 1;
                
                else{
                    
                    int down = 0, right = 0;
                    if(i > 0)
                        down = dp[i-1][j];
                    
                    if(j > 0)
                        right = dp[i][j-1];
                    
                    dp[i][j] = down + right;
                }
            }
        }
        
        return dp[m-1][n-1];
        
    }
};