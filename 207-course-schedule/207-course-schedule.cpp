// class Solution {
    
//     bool topo_sort_bfs(vector<int> &vis, vector<int> adj, int n){
        
//         vector<int> indegree(n, 0);
//         queue<int> q;
        
//         for(int i = 0; i < n; i++){
            
//             for(int it1 : adj[i]){
                
//                 indegree[it1]++;
//             }
//         }
        
//         for(int j = 0; j < n; j++){
            
//             if(indegree[i] == 0)
//                 q.push(i);
//         }
        
//         int count = 0
//         while(!q.empty()){
            
//             int node = q.front();
//             q.pop();
//             vis[node] = 1;
//             count++;
            
//             for(auto it: adj[node]){
//                 indegree[it]--;
                
//                 if(indgree[it] == 0){
//                     q.push(it);
//                 }
//             }
//         }
        
//         if(count == n) return true;
//         else return false;
        
//     }
    
// public:
//     bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
//         //Zero Based indexing
//         vector<int> vis(n, 0);
//         vector<int> adj[n];
            
//         for(auto &it: prerequisites){

//             adj[it[1]].push_back(it[0]);
//         }
        
//         for(int i = 0; i < n; i++){
            
//             if(!vis[i]){
//                 if(!topo_sort_bfs(vis, adj, n))
//                     return false;
//             }
//         }
        
//         return true;
        
//     }
// };

class Solution{
    
public:

bool canFinish(int n, vector<vector<int>>& prerequisites) {
    
    vector<vector<int>> G(n); //Adjacency Matrix

    vector<int> degree(n, 0), bfs; //Indegree and queue

    for (auto& e : prerequisites){
        G[e[1]].push_back(e[0]); 
        degree[e[0]]++;
    }

    for (int i = 0; i < n; ++i) 
        if (!degree[i]) bfs.push_back(i); //If degree index is zero push it in the queue

    for (int i = 0; i < bfs.size(); ++i)
        for (int j: G[bfs[i]])
            if (--degree[j] == 0) bfs.push_back(j);
        
    return bfs.size() == n;
}
    
};