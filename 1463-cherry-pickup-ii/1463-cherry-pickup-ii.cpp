//https://www.youtube.com/watch?v=QGfn7JeXK54&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=14

class Solution {
private:
    int maxCherry(int i, int j1, int j2, int l, int b, vector<vector<int>>& grid){
        
        //Base Condition
        if(j1 < 0 || j2 < 0 || j1 > (b-1) || j2 > (b-1)){
            return -1e8;
        }
        
        if(i == (l-1)){
            if(j1 == j2) return grid[i][j1];
            
            else return (grid[i][j1] + grid[i][j2]);
        }
        
        //Explore
        int maxi = -1e8;
        for(int del1 = -1; del1 <= 1; del1++){
            
            for(int del2 = -1; del2 <= 1; del2++){
                
                if(j1 == j2) maxi = max(maxi, grid[i][j1] + maxCherry(i+1, j1 + del1, j2 + del2, l, b, grid));
                
                else maxi = max(maxi, grid[i][j1] + grid[i][j2] + maxCherry(i+1, j1 + del1, j2 + del2, l, b, grid));
            }
        }
        
        return maxi;
        
    }
    
    int maxCherrym(int i, int j1, int j2, int l, int b, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        
        //Base Condition
        if(j1 < 0 || j2 < 0 || j1 > (b-1) || j2 > (b-1)){
            return -1e8;
        }
        
        if(i == (l-1)){
            if(j1 == j2) return grid[i][j1];
            
            else return (grid[i][j1] + grid[i][j2]);
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        //Explore
        int maxi = -1e8;
        for(int del1 = -1; del1 <= 1; del1++){
            
            for(int del2 = -1; del2 <= 1; del2++){
                
                if(j1 == j2) maxi = max(maxi, grid[i][j1] + maxCherrym(i+1, j1 + del1, j2 + del2, l, b, grid, dp));
                
                else maxi = max(maxi, grid[i][j1] + grid[i][j2] + maxCherrym(i+1, j1 + del1, j2 + del2, l, b, grid, dp));
            }
        }
        
        return dp[i][j1][j2] = maxi;
        
    }
    
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        //Recursion Approach
        // return maxCherry(0, 0, n-1, m, n, grid);
        
        //Memoization Approach
        //3d vector dp[m][n][n];
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (n, -1)));
        
        return maxCherrym(0, 0, n-1, m, n, grid, dp);
        
    }
};