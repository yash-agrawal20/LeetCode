/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/


class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        //BFS
//         if(!node)
//             return NULL;
        
//         Node *copy = new Node(node->val, {});
//         //Unordered Map
//         copies[node] = copy;
//         queue<Node*> todo;
//         todo.push(node);
        
//         while(!todo.empty()){
            
//             Node* cur = todo.front();
//             todo.pop();
            
//             for(Node* neighbor: cur-> neighbors){
//                 if(copies.find(neighbor) == copies.end()){
                    
//                     copies[neighbor] = new Node(neighbor->val, {});
//                     todo.push(neighbor);
//                 }
                
//                 copies[cur] -> neighbors.push_back(copies[neighbor]);
//             }
//         }
        
//         return copy;
        
        //DFS
        if(!node)
            return NULL;
        
        if(copies.find(node) == copies.end()){
            
            copies[node] = new Node(node-> val, {});
            for(Node* neighbor: node-> neighbors){
                
                copies[node] -> neighbors.push_back(cloneGraph(neighbor));
            }
        }
        
        return copies[node];
    }
    
private:
    unordered_map<Node*, Node*> copies;
};