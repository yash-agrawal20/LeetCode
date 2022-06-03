class Solution {
public:
    bool isPowerOfTwo(int n) {
        
//         bool val = true;
        
//         if(n > 0 && n < 1){
//             n = 1 / n;
//         }
        
//         while(val == true){
//             if(n == 1) return true;
//             else if(n%2 != 0 || n <= 0) val = false;
//             else n = n/2;
//         }
        
//         return val;
        
        if(n <= 0)
            return false;
        
        if(n > 0 && n < 1)
            n = 1/n;
        
        int count  = 0;
        //Bit manipulation
        while(n){
            
            count += n & 1;
            n >>= 1;
            
            if(count > 1)
                return false;
        }
        
        return true;
            
    }
};