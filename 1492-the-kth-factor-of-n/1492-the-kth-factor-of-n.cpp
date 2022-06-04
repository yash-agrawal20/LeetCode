class Solution {
public:
    int kthFactor(int n, int k) {
        
        //Time complexity: O(n)
        int factor;
        int count = 0;
        int i = 1; 
        
        while(i <= n/2 && count < k){
            
            if(n % i == 0){
                count++;
                factor = i;
            }
            
            i++;
        }
        
        if(count == k-1)
            return n;        
        if(count == k)
            return factor;
        else
            return -1;
        
        
    }
};