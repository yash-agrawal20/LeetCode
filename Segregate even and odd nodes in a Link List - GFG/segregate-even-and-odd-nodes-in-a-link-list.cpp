// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        
        Node* end = head;
        Node* prev = NULL;
        Node* curr = head;
        
        while(end->next != NULL){
            end = end->next;
        }
        
        Node* new_end = end;
        
        //Pushing all the odd nodes of the linked list to the end
        while(curr->data % 2 != 0 && curr != end){
            
            new_end->next = curr;
            curr = curr->next;
            new_end->next->next = NULL;
            new_end = new_end->next;
            
        }
        
        //Segregating the odd and even nodes;
        if(curr->data % 2 == 0){
            
            head = curr;
            
            while(curr != end){
                
                if(curr->data % 2 == 0){
                    
                    prev = curr;
                    curr = curr->next;
                }
                
                else{
                    
                    prev->next = curr->next;
                    curr->next = NULL;
                    new_end->next = curr;
                    new_end = curr;
                    curr = prev->next;
                }
            }
        }
        
        else{
            prev = curr;
        }
        
        if(new_end != end && end->data % 2 != 0){
            
            prev->next = end->next;
            end->next = NULL;
            new_end->next = end;
        }
        
        return head;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends