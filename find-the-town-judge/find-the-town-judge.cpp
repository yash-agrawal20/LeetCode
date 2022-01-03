// class Solution {
// public:
//     int findJudge(int n, vector<vector<int>>& trust) {
        
//     map<int, int> m;
//     for(int i = 0; i < trust.size(); i++){

//         m[trust[i][0]]--;
//         m[trust[i][1]]++;
//     }
        
//     for( auto j : m){
         
//         if(j.second == (n-1)) return j.first;
//     }
        
//     return -1;
        
//     }
// };

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> Trusted(N + 1, 0);
        for(auto person : trust){
            Trusted[person[0]]--;
            Trusted[person[1]]++;
        }
        for(int i = 1;i <= N;i++){
            if(Trusted[i] == N - 1)
                return i;
        }
        return -1;
    }
};