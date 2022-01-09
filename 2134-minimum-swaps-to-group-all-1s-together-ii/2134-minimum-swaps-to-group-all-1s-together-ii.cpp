class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);
        int x = 0, ones_window =  0;
        
        vector<int> nums2(n*2);
        
        //Fow circular array problem, append the array into otself.
        for(int i = 0; i < n*2; i++){
            
            nums2[i] = nums[i % n];
        }
        
        //Sliding Window Technique
        for(int i = 0; i < n*2; i++){
            
            if( i >= ones && nums2[i - ones] == 1) x--;
            if(nums2[i] == 1) x++;
            
            ones_window = max(x, ones_window);
        }
        
        return ones - ones_window;        
        
    }
};