class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        //TC: O(n), SC: O(1)
//         if(nums.size() == 1 || nums[0] > nums[1])
//             return 0;
        
//         nums.push_back(INT_MIN); //nums[n]
        
//         for(int i = 1; i < nums.size()-1; i++){
            
//             if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
//                 return i;
//         }
        
//         return -1;   
         
        //Binary Search
        int low = 0;
        int high = nums.size() - 1;
        
        while(low < high){
            
            int mid = low + (high - low)/2;
            
            if(nums[mid] < nums[mid+1])
                low = mid + 1;
            else
                high = mid;
        }
        
        return low;
    }
};