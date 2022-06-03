class Solution {
public:
    bool isPalindrome(int x) {
        
        //Solution: 1
        //Convert to string
        
        string s = to_string(x);
        int l = 0;
        int r = s.size() - 1;
        
        while(l <= r){
            
            if(s[l] != s[r])
                return false;
            
            l++;
            r--;
        }
        
        return true;        
    }
};