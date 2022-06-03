//https://leetcode.com/problems/reverse-integer/discuss/4124/8-ms-simple-C%2B%2B-solution-which-checks-overflow

class Solution {
public:
int reverse(int x) {
    
       int rev = 0;
    
       while (x){
           
           int digit = x % 10;
           
           x /= 10;
           if ((rev > 0 && rev > (INT_MAX - digit)/10) | (rev < 0 && rev < (INT_MIN - digit)/10)) 
               return 0;
           
           rev = rev * 10 + digit;
       }
       return rev;
   }
};