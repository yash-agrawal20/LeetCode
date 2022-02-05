class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
//         //Brute Force approach
//         int count = 0;
        
//         for(int i = 0; i < time.size() - 1; i++){
        
//             for(int j = i + 1; j < time.size(); j++){
            
//                 if((time[i] + time[j]) % 60 == 0) count++;
//             }
//         }
        
//         return count;
        
        int map[60] = {};
        int result = 0;
        
        for(auto x:time){
            int t = x % 60;
            int y = (60 - t)%60;
            result += map[y];
            map[t]++;
        }
        
        return result;
    }
};
