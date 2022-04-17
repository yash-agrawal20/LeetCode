class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 1)
            return 0;
        
        int i = 0, j = 0;
        int minval = prices[0], maxval = prices[0];
        int maxdiff = 0;
        int k = 1;
        
        while(k < prices.size()){
            
            if(prices[k] < minval){
                i = k;
                minval = prices[k];
            }
            
            else if(prices[k] > minval){
                j = k;
                maxval = prices[k];
            }
            
            if(j > i){
                int diff = maxval - minval;
                
                if(diff > maxdiff)
                    maxdiff = diff;
            }
            
            k++;
        }
        
        return maxdiff;
        
    }
};