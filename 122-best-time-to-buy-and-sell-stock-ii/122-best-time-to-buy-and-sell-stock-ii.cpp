class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int buy = prices[0];
        int sell = prices[0];
        int diff = 0;
        int total = 0;
        
        for(int i = 1; i < n; i++){
            
            diff = prices[i] - prices[i-1];
            
            if(diff < 0){
                total += sell - buy;
                buy = prices[i];
                sell = prices[i];
            }
            
            else if(diff >= 0){
                
                sell = prices[i];
            }
            
            if(i == (n-1)){
                total += sell - buy;
            }
        }
        
        return total;
        
    }
};