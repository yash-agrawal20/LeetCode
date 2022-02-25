class Solution {
private:
    int maxMoney(int l, vector<int> &temp, vector<int> &dp){
        
        if(l == 0) return temp[0];
        else if(l < 0) return 0;
        
        else if(dp[l] != -1){
            return dp[l];
        }
        
        int pick = temp[l] + maxMoney(l-2, temp, dp);
        int notPick = maxMoney(l-1, temp, dp);
        
        return dp[l] = max(pick, notPick);
    }
    
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1) return nums[0];
        
        vector<int> temp1, temp2;
        for(int i = 0; i < n; i++){
            
            if(i != 0) temp1.push_back(nums[i]);
            if(i != (n-1)) temp2.push_back(nums[i]);
        }
        
        //Memoization Approach
        vector<int> dp1(n-1, -1), dp2(n-1, -1);
        return max(maxMoney(n-2, temp1, dp1), maxMoney(n-2, temp2, dp2));
        
    }
};