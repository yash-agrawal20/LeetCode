class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        map<int, int> m, count;
        
        for(int i = 0; i < nums.size(); i++){
            
            //Stores the number of times the integer occurs in the array
            count[nums[i]]++;
            
            if(count[nums[i]] >= 2 && abs(m[nums[i]] - i) <= k) return true;
            
            //Stores the index of the integer.
            m[nums[i]] = i;
        }
        
        return false;
    }
};