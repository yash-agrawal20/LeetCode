class Solution {
private:
    int numberArr(int ind, int size, vector<int>& nums, vector<vector<int>>& dp, int& rep){
        
        if(dp[ind][size] != -1){
            
            rep += dp[ind][size];
            return dp[ind][size];
        }
        
        if(size == 3){
            
            if((nums[ind] - nums[ind+1]) == (nums[ind+1] - nums[ind+2]))
                return dp[ind][size] = 1;
            else
                return dp[ind][size] = 0;
        }
        
        int arr1 = numberArr(ind, size-1, nums, dp, rep);
        int arr2 = numberArr(ind + 1, size-1, nums, dp, rep);
        
        if(arr1 != 0 && arr2 != 0)
            return dp[ind][size] = 1 + arr1 + arr2;
        else
            return dp[ind][size] = arr1 + arr2;     
    }
    
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        //Simple Approach: O(n), O(1);
        int n = nums.size();
        if(n < 3)
            return 0;
        
        int ans = 0, l = 0;
        for(int i = 2; i < n; i++){
            
            if((nums[i] - nums[i-1]) == (nums[i-1] - nums[i-2]))
                l++;
            
            else{
                ans += l*(l+1)/2;
                l = 0;
            }
        }
        
        if(l)
            ans += l*(l+1)/2;
            
        return ans;
        
//         //Memoization method
//         int n = nums.size();
        
//         if(n < 3)
//             return 0;
        
//         vector<vector<int>> dp(n, vector<int> (n+1, -1));
        
//         int rep = 0;
//         int total = numberArr(0, n, nums, dp, rep);
        
//         return (total - rep);
        
    }
};