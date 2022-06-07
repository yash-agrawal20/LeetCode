class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        //Approach 1
//         int n = prices.size();
//         int buy = prices[0];
//         int sell = prices[0];
//         int diff = 0;
//         int total = 0;
        
//         for(int i = 1; i < n; i++){
            
//             diff = prices[i] - prices[i-1];
            
//             if(diff < 0){
//                 total += sell - buy;
//                 buy = prices[i];
//                 sell = prices[i];
//             }
            
//             else if(diff >= 0){
                
//                 sell = prices[i];
//             }
            
//             if(i == (n-1)){
//                 total += sell - buy;
//             }
//         }
        
//         return total;
        
        //Approach 2
        if(prices.size() == 1)
            return 0;
        
        int profit = 0;
        for(int i = 1; i < prices.size(); i++){
            
            if(prices[i] > prices[i-1])
                profit += prices[i] - prices[i-1];
        }
        
        return profit;
    }
};