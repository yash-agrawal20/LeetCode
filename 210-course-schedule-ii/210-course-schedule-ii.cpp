class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        
        //Kahn Algorithm
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        for(auto &it : prerequisites){
            
            indegree[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }
        
        queue<int> q;
        vector<int> topo;
        int count = 0;
        
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            
            auto node = q.front();
            q.pop();
            count++;
            topo.push_back(node);
            
            for(auto it1: adj[node]){
                
                indegree[it1]--;
                if(indegree[it1] == 0){
                    q.push(it1);
                }
            }
            
        }
        
        if(count == n) return topo;
        else return {};
        
    }
};