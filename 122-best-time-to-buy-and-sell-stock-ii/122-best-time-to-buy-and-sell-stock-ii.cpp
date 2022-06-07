//https://www.youtube.com/watch?v=nGJmxkUJQGs

class Solution {
private:
    int f(vector<int>& prices, int ind, int buy, vector<vector<int>>& dp){
        
        //Base case
        if(ind == prices.size())
            return 0;
        
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        
        //Stuff
        int profit = 0;
        if(buy){
            
            profit = max((-prices[ind] + f(prices, ind+1, 0, dp)), 
                         (0 + f(prices, ind+1, 1, dp)));
        }
        
        else{
            
            profit = max((prices[ind] + f(prices, ind+1, 1, dp)),
                        (0 + f(prices, ind+1, 0, dp)));
        }
        
        return dp[ind][buy] = profit;
    }
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
//         if(prices.size() == 1)
//             return 0;
        
//         int profit = 0;
//         for(int i = 1; i < prices.size(); i++){
            
//             if(prices[i] > prices[i-1])
//                 profit += prices[i] - prices[i-1];
//         }
        
//         return profit;
        
        //Approach 3
        //Using Recursion
        //TLE
        // return f(prices, 0, 1);
        
        //Using memoization
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return f(prices, 0, 1, dp);
    }
};