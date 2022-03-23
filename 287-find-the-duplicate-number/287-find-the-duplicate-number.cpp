class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int m = nums.size();
        
        unordered_set<int> s;
        
        s.insert(nums[0]);
        
        for(int i = 1; i < m; i++){
            
            if(s.find(nums[i]) != s.end()) return nums[i];
            
            s.insert(nums[i]);
        }
        
        return -1;        
    }
};