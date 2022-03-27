class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size() - 1, p = -1, pv = 0;
        
        for(int i = (n-1); i >= 0; i--){
            
            if(nums[i] < nums[i+1]){
                
                p = i;
                pv = nums[i];
                break;
            }
        }
        
        if(p == -1){
            reverse(nums, 0, n);
            return;
        }
        
        for(int i = n; i >= 0; i--){
            
            if(nums[i] > pv){
                swap(nums, p, i);
                break;
            }
        }
        
        reverse(nums, p+1, n);
        
    }
    
    void reverse(vector<int> &nums, int s, int e){
        
        while(s < e){
            
            swap(nums, s, e);
            s++;
            e--;
        }
    }
    
    void swap(vector<int> &nums, int s, int e){
        
        int t = nums[s];
        nums[s] = nums[e];
        nums[e] = t;
    }
};