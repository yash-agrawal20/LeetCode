class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(size(nums) == 0) return 0;
        
        int longest = 0, max_len = 1;
        sort(nums.begin(), nums.end());
        
        for(int i = 1; i < nums.size(); i++){
            
            if(nums[i] == nums[i-1]) continue;
            
            else if(nums[i] - nums[i-1] == 1) max_len++;
            
            else{
                longest = max(longest, max_len);
                max_len = 1;
            }
        }
        
        return max(longest, max_len);
        
    }
};