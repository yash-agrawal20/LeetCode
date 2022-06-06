class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        if(nums.size() == 1 || nums[0] > nums[1])
            return 0;
        
        nums.push_back(INT_MIN); //nums[n]
        
        for(int i = 1; i < nums.size()-1; i++){
            
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
                return i;
        }
        
        return -1;        
    }
};