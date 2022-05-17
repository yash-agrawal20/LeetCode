class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int m = haystack.size();
        int n = needle.size();
        
        //Iterating through haystack
        for(int i = 0; i < m; i++){
            
            bool check = true;
            
            if(haystack[i] == needle[0]){
                
                int k = i;
                //Iterating through needle
                for(int j = 0; k < m, j < n; j++){
                    
                    if(needle[j] != haystack[k]){
                        check = false;
                        break;
                    }
                    
                    k++;
                }
                
                if(check) return i;
            }
        }
        
        return -1;
        
    }
};