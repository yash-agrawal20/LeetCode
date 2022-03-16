class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        //As vector is given it becomes easy.
//         sort(nums.begin(), nums.end());
        
//         return nums[n - k];
        
        //Using min heap
        priority_queue<int, vector<int>, greater<int>> minh;
        
        for(int i = 0; i < n; i++){
            
            minh.push(nums[i]);
            
            if(minh.size() > k){
                minh.pop();
            }
        }
        
        return minh.top();
        
    }
};