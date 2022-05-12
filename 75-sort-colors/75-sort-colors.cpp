class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        //Using Bubble - Swap operation (in-place sorting)
        int n = nums.size();
        
        for(int i = 0; i < n-1; i++){
            
            bool swapped = false;
            
            //IMP (n-i-1)
            for(int j = 0; j < n-i-1; j++){
                
                if(nums[j] > nums[j+1]){
                    swap(nums[j], nums[j+1]);
                    swapped = true;
                }
            }
            
            if(swapped == false)
                break;
        }
        
    }
};