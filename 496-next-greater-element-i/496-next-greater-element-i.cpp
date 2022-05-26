class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
   
        //TC: O(nm)     
//         int n = nums1.size();
//         int m = nums2.size();
        
//         for(int i = 0; i < n; i++){
            
//             for(int j = 0; j < m; j++){
                
//                 if(nums1[i] == nums2[j]){
                    
//                     int k = j+1;
                    
//                     while(k <= m){
                        
//                         if(k == m)
//                             nums1[i] = -1;
                        
//                         else if(nums2[k] > nums2[j]){
//                             nums1[i] = nums2[k];
//                             break;
//                         }
                        
//                         k++;
//                     }
                    
//                     break;
//                 }
//             }
//         }
        
//         return nums1;
        
        //TC(n+m)
        int n = nums1.size();
        int m = nums2.size();
        
        vector<int> res(n, -1);
        stack<int> s;
        unordered_map<int, int> mp;
        
        //Preprossessing
        //IMP
        for(int i = 0; i < m; i++){
            
            while(s.size() && nums2[i] > s.top()){
                
                mp[s.top()] = nums2[i];
                s.pop();
            }
            
            s.push(nums2[i]);
        }
        
        for(int i = 0; i < n; i++){
            
            if(mp.find(nums1[i]) != mp.end())
                res[i] = mp[nums1[i]];
        }
        
        return res;
        
    }
};   
