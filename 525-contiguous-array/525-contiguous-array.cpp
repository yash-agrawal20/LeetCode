class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
//         //Brute Force Method (TLE)
//         int maxLen = 0;
//         for(int i = 0; i < nums.size(); i++){
            
//             int zero = 0, one = 0;
//             for(int j = i; j < nums.size(); j++){
                
//                 if(nums[j] == 0) zero++;
//                 else one++;
                
//                 if(zero == one){
//                     maxLen = max(maxLen, j-i+1);
//                 }
//             }
//         }
        
//         return maxLen;
        
          //Using arrays (not 100% sure)
        vector<int> arr(2*nums.size() + 1, INT_MIN);
		arr[nums.size()] = -1;
        
        int maxLen = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 0 ? -1 : 1);
            
			if (arr[sum + nums.size()] >= -1)  
                maxLen = max(maxLen, i - arr[sum + nums.size()]);
			else  arr[sum + nums.size()] = i; 
        }
        return maxLen;
    }
};