/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        //for traversing through the linked list
//         Node* temp = head;
//         unordered_map<Node*, int> node;
//         unordered_map<int, int> random;
        
//         //Dummy Node
        
        
//         int i = 0;
//         //Unordered map of address along with index
//         while(temp){
//             node[temp] = i;
//             temp = temp->next;
//             i++;
//         }
        
//         temp = head;
//         i = 0;
//         //Unordered map of random index and actual index
//         while(temp){
            
//             if(temp->random == NULL)
//                 random[i] = -1;
            
//             else
//                 random[i] = node[temp->random];
            
//             i++;
//             temp = temp->next;
//         }
        
        map<Node*, Node*> mp;
        Node* temp = head;
        
        while(temp){
            
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        
        while(temp){
            
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }
        
        return mp[head];
        
    }
};