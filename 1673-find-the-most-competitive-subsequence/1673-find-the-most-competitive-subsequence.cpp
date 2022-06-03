class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        
        //Stack
//         vector<int> st;
//         int n = nums.size();
        
//         for(int i = 0; i < n; i++){
            
//             while(!st.empty() && st.back() > nums[i] && (st.size() - 1 + n - i >= k))
//                 st.pop_back();
            
//             if(st.size() < k)
//                 st.push_back(nums[i]);
//         }
        
//         return st;
        
        //Array
        vector<int> st(k);
        int j = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            
            while(j && st[j-1] > nums[i] && (j-1+n-i) >= k)
                j--;
            
            if(j < k){
                st[j] = nums[i];
                j++;
            }
        }
        
        return st;
        
    }
};