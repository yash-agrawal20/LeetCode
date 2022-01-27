class Solution {
    //Using DFS
    void total_group(vector<vector<int>> isConnected, vector<int> &visited, int i){
        
        visited[i] = 1;
        
        for(int j = 0; j < isConnected.size(); j++){
            
            if(i != j && isConnected[i][j] && !visited[j]){
                
                total_group(isConnected, visited, j);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        if(isConnected.empty()) return 0;
        
        int n = isConnected.size();
        vector<int> visited(n,0);
        int group = 0;
        
        for(int i = 0; i < n; i++){
            
            if(!visited[i]){
                
                group++;
                total_group(isConnected, visited, i);
            }
        }
        
        return group;
        
    }
};