class Solution {
private:
    //Brute Force Method
//     int countOne(int n){
        
//         int count = 0;
//         while(n){
//             if(n & 1) count++;
            
//             n >>= 1;//Right Shift by 1;          
//         }
        
//         return count;
//     }
    
    //Recursive Solution
//     int countOne(int n){
        
//         if(n == 0) return 0;
        
//         else return (n & 1) + countOne(n >> 1);
//     }
    
    //Brian Kerninghans Algorithm TC = O(logn)
    int countOne(int n){
        
        int count = 0;
        while(n){
            n &= (n-1);
            count++;
        }
        
        return count;
    }
    
public:
    vector<int> countBits(int n) {
        
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            int x = countOne(i);
            ans.push_back(x);
        }
        
        return ans;
        
    }
};