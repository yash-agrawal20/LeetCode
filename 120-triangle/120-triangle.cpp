class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        //Tabulation Approach
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int i = 0; i < n; i++){
            
            for(int j = 0; j < (i+1); j++){
                
                if(i == 0 && j == 0) dp[i][j] = triangle[0][0];
                
                else{
                    int down = 2000000, right = 2000000;
                    
                    if(i != j)
                        down = triangle[i][j] + dp[i-1][j];
                    
                    if(j > 0){
                        right = triangle[i][j] + dp[i-1][j-1];
                    }
                    
                    dp[i][j] = min(down, right);
                }
            }
        }
        
        int min_num = dp[n-1][0];
        for(int i = 0; i < n; i++){
            min_num = min(min_num, dp[n-1][i]);
        }
        
        return min_num;        
    }
};