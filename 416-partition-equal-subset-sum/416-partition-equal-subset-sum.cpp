class Solution {
    //Recursion (TLE)
//     bool sumEqualK(int l, int target, vector<int>& nums){
        
//         //Base Case
//         if(target == 0) return true;
        
// //         if(n == 0){
// //             if(target == nums[0]) return true;
            
// //             else false;
// //         } (or)
//         if(l == 0) return (target == nums[0]);
        
//         bool notTake = sumEqualK(l-1, target, nums);
        
//         int take = false;
//         if(target >= nums[l])
//             take = sumEqualK(l-1, target-nums[l], nums);
        
//         return take | notTake;
//     }
    
    //Memoization approach
    bool sumEqualK(int l, int target, vector<int>& nums, vector<vector<int>>& dp){
        
        //Base Case:
        if(target == 0) return true;
        
        if(l == 0){
            return (target == nums[0]);
        }
        
        if(dp[l][target] != -1) return dp[l][target];
        
        bool notTake = sumEqualK(l-1, target, nums, dp);
        
        bool take = false;
        if(target >= nums[l]) take = sumEqualK(l-1, target-nums[l], nums, dp);
            
        return dp[l][target] = take | notTake;
    }
    
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        
        vector<vector<int>> dp(n, vector<int> (sum/2 + 1, -1)); 
        
        //If sum is odd, it cannot be devided into two equal subsets
        if(sum % 2)
            return false;
            
        else
            // return sumEqualK(n-1, sum/2, nums);
            return sumEqualK(n-1, sum/2, nums, dp);
            
        
    }
};