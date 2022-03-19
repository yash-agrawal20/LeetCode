class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        k = k % n;
        
        nums.insert(nums.end(), nums.begin(), nums.end());
        
        vector<int> res;
        
        int index = n - k;
        
        for(int i = 0; i < n; i++){
            
            res.push_back(nums[index + i]);
        }
        
        nums = res;
    }
};