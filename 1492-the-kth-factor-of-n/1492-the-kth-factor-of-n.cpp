class Solution {
public:
    int kthFactor(int n, int k) {
        
        int factor;
        int count = 0;
        int i = 1;
        
        while(i <= n && count < k){
            
            if(n % i == 0){
                count++;
                factor = i;
            }
            
            i++;
        }
        
        if(count == k)
            return factor;
        else
            return -1;
        
        
    }
};