//https://leetcode.com/problems/minimum-number-of-refueling-stops/discuss/149839/DP-O(N2)-and-Priority-Queue-O(NlogN)

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        //Greedy Approach
        //Priority queue solution
        
//         int i = 0;
//         int res;
        
//         priority_queue<int> pq;
        
//         for(res = 0; startFuel < target; res++){
            
//             while(i < stations.size() && startFuel >= stations[i][0]){
//                 pq.push(stations[i][1]);
//                 i++;
//             }
            
//             if(pq.empty()) 
//                 return -1;
            
//             startFuel += pq.top();
//             pq.pop();
//         }
        
//         return res;
        
        //DP solution
        int n = stations.size();
        long dp[501] = {startFuel};
        
        for(int i = 0; i < n; i++){
            
            for(int j = i; j >= 0 && dp[j] >= stations[i][0]; j--){
                
                dp[j+1] = max(dp[j+1], dp[j] + stations[i][1]);
            }
        }
        
        for(int i = 0; i <= n; i++){
            
            if(dp[i] >= target)
                return i;
        }
        
        return -1;
    }
};