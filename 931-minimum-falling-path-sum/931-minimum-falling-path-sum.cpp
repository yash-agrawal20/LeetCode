class Solution {
private:
    int minSum(int l, int b, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        
        if(b < 0 || b > (matrix.size()-1)) return 10000;
        
        if(l == 0 && (b >= 0 || b < matrix.size())) return matrix[l][b];
        
        else if(dp[l][b] != -1) return dp[l][b];
        
        int up = matrix[l][b] + minSum(l-1, b, matrix, dp);
        int dr = matrix[l][b] + minSum(l-1, b+1, matrix, dp);
        int dl = matrix[l][b] + minSum(l-1, b-1, matrix, dp);
        
        int x = min(dr, dl);
        
        return dp[l][b] = min(up, x);
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        //Memoization Approach
//         vector<vector<int>> dp(m, vector<int> (n, -1));
//         int min_num = 10000;
        
//         for(int i = 0; i < n; i++){
            
//             int x = minSum(m-1, i, matrix, dp);
//             min_num = min(min_num, x);
//         }
        
//         return min_num;
        
        //Tabulation Approach
        //Note: Tabulation Approaches are always faster than memoization
//         vector<vector<int>> dp(m, vector<int> (n, 0));
//         dp[0] = matrix[0];
        
//         for(int i = 1; i < m; i++){
            
//             for(int j = 0; j < n; j++){
                
//                 int down = 10000, dr = 10000, dl = 10000;
//                 down = matrix[i][j] + dp[i-1][j];
                
//                 if(j < (n-1))
//                     dl = matrix[i][j] + dp[i-1][j+1];
                    
//                 if(j > 0)
//                     dr = matrix[i][j] + dp[i-1][j-1];
                
//                 int x = min(dr, dl);
//                 dp[i][j] = min(down, x);
//             }
//         }
        
//         int min_num = 10000;
//         for(int i = 0; i < n; i++){
            
//             min_num = min(min_num, dp[m-1][i]);
//         }
        
//         return min_num;
        
        //Space Optimization solution;
        vector<int> prev(n, 0), dp(n, 0);
        prev = matrix[0];
        
        for(int i = 1; i < m; i++){
            
            for(int j = 0; j < n; j++){
                
                int down = 1e9, dr = 1e9, dl = 1e9;
                
                down = matrix[i][j] + prev[j];
                
                if(j > 0){
                    dl = matrix[i][j] + prev[j-1];
                }
                
                if(j < (n-1)){
                    dr = matrix[i][j] + prev[j+1];
                }
                
                int x = min(dl, dr);
                dp[j] = min(down, x);
            }
            
            prev = dp;
        }
        
        int min_num = 1e9;
        for(int i = 0; i < n; i++){
            
            min_num = min(min_num, prev[i]);
        }
        
        return min_num;      
        
        
        
    }
};