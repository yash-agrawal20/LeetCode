class Solution {
public:
    bool isPalindrome(int x) {
        
        //Solution: 1
        //Convert to string
        
//         string s = to_string(x);
//         int l = 0;
//         int r = s.size() - 1;
        
//         while(l <= r){
            
//             if(s[l] != s[r])
//                 return false;
            
//             l++;
//             r--;
//         }
        
//         return true;
        
        //Solution 2
        //Using vectors
        
        if(x < 0)
            return false;
        
        deque<int> num;
        
        while(x){
            
            int n = x % 10;
            
            num.push_back(n);
            
            x = x/10;
        }
        
        while(num.size() > 1){
            
            if(num.front() != num.back())
                return false;
            
            num.pop_front();
            num.pop_back();
        }
        
        return true;          
            
    }
};