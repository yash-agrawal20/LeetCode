class Solution {
public:
    string longestPalindrome(string s) {
        
        int reslen = 0;
        string res = "";
        
        for(int i = 0; i < (s.size()); i++){
            
            //Odd length Palindrome
            int l1 = i, r1 = i;
            while(l1 >= 0 && r1 < s.size() && s[l1] == s[r1]){
                
                if((r1-l1+1) > reslen){
                    reslen = r1-l1+1;
                    res = s.substr(l1, reslen);
                }
                
                l1--;
                r1++;
            }
            
            //Even length Palindrome
            int l2 = i, r2 = i+1;
            while(l2 >= 0 && r2 < s.size() && s[l2] == s[r2]){
                
                if((r2-l2+1) > reslen){
                    reslen = r2-l2+1;
                    res = s.substr(l2, reslen);
                }
                
                l2--;
                r2++;
            }
        }
        
        return res;
        
    }
};