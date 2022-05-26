/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        Node* temp = head;
        
        while(temp){
            
            if(temp->child){
                
                Node* forward = temp->next;
                temp->next = temp->child;
                temp->next->prev = temp;
                temp->child = NULL;
                
                Node* cnext = temp->next;
                while(cnext->next)
                    cnext = cnext->next;
                
                cnext->next = forward;
                if(forward)
                    forward->prev = cnext;
            }
            
            
            temp = temp->next;
        }
        
        return head;
        
    }
};