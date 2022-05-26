class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        for(int i = 0; i < n; i++){
            
            for(int j = 0; j < m; j++){
                
                if(nums1[i] == nums2[j]){
                    
                    int k = j+1;
                    
                    while(k <= m){
                        
                        if(k == m)
                            nums1[i] = -1;
                        
                        else if(nums2[k] > nums2[j]){
                            nums1[i] = nums2[k];
                            break;
                        }
                        
                        k++;
                    }
                    
                    break;
                }
            }
        }
        
        return nums1;
        
    }
};   
