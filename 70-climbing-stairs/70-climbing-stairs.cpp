class Solution {
private:
    int f(int n){
        
        if(n <= 1) return 1;
        
        return f(n-1) + f(n-2);
    }
    
    int fm(int n, vector<int>& dp){
        
        if(n <= 1 ) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = fm(n-1, dp) + fm(n-2, dp);
    } 
    
public:
    int climbStairs(int n) {
        
        //Recurion Approach
        //return f(n);
        
        //Memoization Approach
        vector<int> dp(n+1, -1);
        return fm(n, dp);
        
    }
};