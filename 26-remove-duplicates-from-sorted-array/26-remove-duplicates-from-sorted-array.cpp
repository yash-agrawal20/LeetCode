class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //Interesting Solution
        
//         int n = nums.size();
        
//         int count = 0;
        
//         for(int i = 1; i < n; i++){
            
//             if(nums[i] == nums[i-1]) count++;
            
//             else nums[i-count] = nums[i];
//         }
        
//         return n - count;
        
        //2 Pointer Approach
        int n = nums.size();
        
        if(n < 2)
            return n;
        
        int l = 0;
        int r = 1;
        
        for(; r < n; r++){
            
            if(nums[l] != nums[r]){
                
                l++; //Counting the number of unique elements
                nums[l] = nums[r];
            }
        }
        //L is 0-based
        return l+1;        
        
    }
};