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
        vector<vector<int>> dp(m, vector<int> (n, -1));
        int min_num = 10000;
        
        for(int i = 0; i < n; i++){
            
            int x = minSum(m-1, i, matrix, dp);
            min_num = min(min_num, x);
        }
        
        return min_num;
        
    }
};