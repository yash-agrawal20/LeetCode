class Solution {  
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        //Simple Approach: O(n), O(1);
//         int n = nums.size();
//         if(n < 3)
//             return 0;
        
//         int ans = 0, l = 0;
//         for(int i = 2; i < n; i++){
            
//             if((nums[i] - nums[i-1]) == (nums[i-1] - nums[i-2]))
//                 l++;
            
//             else{
//                 ans += l*(l+1)/2;
//                 l = 0;
//             }
//         }
        
//         if(l)
//             ans += l*(l+1)/2;
            
//         return ans;
        
        //2nd Method
        int n = nums.size();
        if(n < 3)
            return 0;
        
        vector<int> dp(n, 0);
        if((nums[2] - nums[1]) == (nums[1] - nums[0]))
            dp[2] = 1;
        
        int res = dp[2];
        
        for(int i = 3; i < n; i++){
            
            if((nums[i] - nums[i-1]) == (nums[i-1] - nums[i-2]))
                dp[i] = dp[i-1] + 1;
            
            res += dp[i];
        }
        
        return res;
        
    }
};