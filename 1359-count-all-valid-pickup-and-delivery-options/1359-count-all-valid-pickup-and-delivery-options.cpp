class Solution {
public:
    int countOrders(int n) {
        
        int mod = 1e9 + 7;
        
        int long long ans = 1;
        for(int i = 1; i <=n; i++){
            
            //For Pickups
            ans = ans*(i) % mod;
            //For Delivery;
            ans = ans*(2*i-1) % mod;
        }
        
        return ans;        
    }
};