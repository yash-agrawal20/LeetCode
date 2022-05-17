class Solution {
private:
    bool isPalindrome(string s, int i, int j){
        
        while(i < j){
            
            if(s[i] != s[j]) return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    
public:
    bool validPalindrome(string s) {
        
//         int n = s.size();
        
//         if(n <= 2) return true;
        
//         bool palindrome = true;
//         int left = 0, right = n-1;
//         int count = 0;
        
//         //Two - Pointer approach
//         while(left <= right){
            
//             if(s[left] != s[right]){
                
//                 count++;
//                 if(count > 1) return false;
                
//                 if(s[left + 1] == s[right]) left++;
//                 else if(s[left] == s[right - 1]) right--;
//                 else{
//                     palindrome = false;
//                     break;
//                 }
//             }
            
//             left++;
//             right--;
//         }
        
//         return palindrome;
        
        int n = s.size();
        int left = 0;
        int right = n-1;
        
        while(left < right){
            
            if(s[left] != s[right]){
                
                return (isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1));
            }
            
            left++;
            right--;            
        }
        
        return true;
        
    }
};