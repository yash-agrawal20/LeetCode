class Solution {
private:
    int countOne(int n){
        
        int count = 0;
        while(n){
            if(n & 1) count++;
            
            n >>= 1;//Right Shift by 1;          
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