class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
   
//Using set data structure        
//         set<int> st;
//         vector<int> res;
        
//         for(int i = 0; i < nums1.size(); i++){
            
//             st.insert(nums1[i]);
//         }
        
//         for(int i = 0; i < nums2.size(); i++){
            
//             auto it = st.find(nums2[i]);
            
//             if(it != st.end()){
                
//                 res.push_back(nums2[i]);
//                 st.erase(it);
//             }
//         }
        
//         return res;  
        
        unordered_set<int> st(nums1.begin(), nums1.end());
        vector<int> res;
        
        for(auto it: nums2){
            
            if(st.count(it)){
                
                res.push_back(it);
                st.erase(it);
            }
        }
        
        return res;
    }
};