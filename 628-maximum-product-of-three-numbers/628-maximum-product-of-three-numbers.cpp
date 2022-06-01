class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int max_int  = INT_MIN;
        
        //Case: 1
        max_int = max(max_int, nums[n-1]*nums[n-2]*nums[n-3]);
        
        //Case: 2
        max_int = max(max_int, nums[0]*nums[1]*nums[n-1]);
        
        return max_int;        
    }
};