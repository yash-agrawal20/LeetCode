
class Solution {
    
    bool bipartiteBFS(int src, vector<int> adj[], int color[]){
        
        queue<int> q;
        q.push(src);
        color[src] = 1;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]){
                
                if(color[it] == -1){
                    
                    color[it] = 1 - color[node];
                    q.push(it);
                }
                
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        
        return true;
        
    }
    
    bool checkBipartite(vector<int> adj[], int n){
        
        int color[n];
        memset(color, -1, sizeof color);
        
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                
                if(!bipartiteBFS(i, adj, color)){
                    return false;
                }
            }
        }
        
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> adj[n];
        
        for(int i = 0; i < n; i++){
            
            for(auto it : graph[i]){
                adj[i].push_back(it);
            }
        }
        
        if(checkBipartite(adj, n)) return true;
        
        else return false;        
    }
};