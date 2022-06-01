class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        //By Observation;
        //WRONG
//         int maxNum = INT_MIN;
        
//         for(int i = 0; i < nums.size(); i++){
            
//             maxNum = max(maxNum, nums[i]);
//         }
        
//         int moves = 0;
        
//         for(int i = 0; i < nums.size(); i++){
            
//             moves += maxNum - nums[i];
//         }
        
//         return moves;   
        
        //Adding 1 to n-1 elements is same as subtracting 1 from 1 element;
        
        int min_num = INT_MAX;
        long sum = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            
            min_num = min(min_num, nums[i]);
            sum += nums[i];
        }
        
        return sum - long(n)*long(min_num);
        
    }
};