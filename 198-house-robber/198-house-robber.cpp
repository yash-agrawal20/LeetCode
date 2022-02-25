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
        vector<int> dp(n, -1);
        return maxMoney(n-1, nums, dp);
        
    }
};