//https://leetcode.com/problems/find-all-duplicates-in-an-array/discuss/775798/c%2B%2B-Four-Solution-or-O-(N*N)-to-greater-O(N)-or-Explain-All

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
//         int n = nums.size();
//         map<int, int> mp; //Space depends on the size of the vector O(n)
//         vector<int> res;
        
//         for(int i = 0; i < n; i++){
            
//             mp[nums[i]]++;
            
//             if(mp[nums[i]] == 2){
//                 res.push_back(nums[i]);
//             }
//         }
        
//         return res;
        
        //Doing the solution in O(1) S.C.
        
        int n = nums.size();
        vector<int> res;
        
        for(int i = 0; i < n; i++){
            
            if(nums[abs(nums[i]) - 1] < 0)
                res.push_back(abs(nums[i]));
                              
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
        
        return res;
        
    }
};