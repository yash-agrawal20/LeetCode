class Solution {
private:
    //Recursion Approah
//     int maxMoney(int l, vector<int> &nums){
        
//         if(l == 0) return nums[0];
//         else if(l < 0) return 0;
        
//         int pick = nums[l] + maxMoney(l-2, nums);
//         int notPick = maxMoney(l-1, nums);
        
//         return max(pick, notPick);
//     }
    
    //Memoization Appraoch
    int maxMoney(int l, vector<int> &nums, vector<int> &dp){
        
        if(l == 0) return nums[0];
        else if(l < 0) return 0;
        
        else if(dp[l] != -1) return dp[l];
        
        int pick = nums[l] + maxMoney(l-2, nums, dp);
        int notPick = maxMoney(l-1, nums, dp);
        
        return dp[l] = max(pick, notPick);
    }
    
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        //Recursion Appraoch
        // return maxMoney(n-1, nums);
        
        //Memoization Appraoch
        // vector<int> dp(n, -1);
        // return maxMoney(n-1, nums, dp);
        
        //Tabulation approach
//         vector<int> dp(n, -1);
//         dp[0] = nums[0];
        
//         for(int i = 1; i < n; i++){
            
//             int pick = nums[i];
//             if(i > 1) pick += dp[i-2];
            
//             int notPick = dp[i-1];
            
//             dp[i] = max(pick, notPick);
//         }
        
//         return dp[n-1];     
        
        //Space Optimization Approach
        int prev = nums[0];
        int prev2 = 0;
        
        for(int i = 1; i < n; i++){
            
            int pick = nums[i];
            if(i > 1) pick += prev2;
            
            int notPick = prev;
            
            int curr = max(pick, notPick);
            
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};