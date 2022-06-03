class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
//         int len = nums.size();
//         int sum_all = len*(len + 1) / 2;
        
//         for(int i = 0; i < len; i++){
//             sum_all -= nums[i];
//         }
        
//         return sum_all;
        
        //Using XOR
        //Doubt
        int n = nums.size();
        int i = 0;
        
        for(int num : nums){
            
            n ^= num;
            n ^= i;
            i++;
        }
        
        return n;            
    }
};