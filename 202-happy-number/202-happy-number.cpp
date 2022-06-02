class Solution {
public:
    bool isHappy(int n) {
        
        if(n == 1)
            return true;
        
        unordered_map<int, int> mp;
        
        while(n != 1){
            
            if(mp[n])
                return false;
            else
                mp[n] = 1;
            
            int sum = 0;
            while(n){
                
                int x = n % 10;
                
                sum += pow(x, 2);
                
                n = n/10;
            }       
            
            n = sum;
            
        }
        
        return true;
        
    }
};