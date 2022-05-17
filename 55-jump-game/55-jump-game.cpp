//https://leetcode.com/problems/jump-game/discuss/520481/C%2B%2B-easy-O(n)-solution-with-detailed-explanation

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        
        //Iterate from right to left;
        int minJump = 0;
        for(int i = nums.size() - 2; i >= 0; i--){
            
            minJump++;
            if(nums[i] >= minJump)
                minJump = 0;
        }
        
        return minJump == 0;
    }
};