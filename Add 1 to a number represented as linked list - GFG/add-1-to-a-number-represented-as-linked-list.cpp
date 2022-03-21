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
        cout << node->data; 
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

class Solution
{
    private:
    Node* reverse(Node* head){
        
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        
        while(curr != NULL){
            
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    void insertatail(Node* &head, Node* &tail, int digit){
        
        Node* node = new Node(digit);
        
        if(head == NULL){
            
            head = node;
            tail = node;
        }
        
        else{
            tail->next = node;
            tail = node;
        }
    }
    
    Node* addto1(Node* temp){
        
        Node* head = NULL;
        Node* tail = NULL;
        int carry = 0;
        
        while(temp != NULL){
            
            if(head == NULL){
                
                int sum = temp->data + 1 + carry;
                int digit = sum % 10;
                carry = sum / 10;
                insertatail(head, tail, digit);
                digit = 0;
            }
            
            else{
                
                int sum = temp->data + carry;
                int digit = sum % 10;
                carry = sum / 10;
                insertatail(head, tail, digit);
            }
            
            temp = temp->next;
        }
        
        if(carry != 0){
            
            insertatail(head, tail, carry);
        }
        
        return head;
    }
    
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* temp = reverse(head);
        Node* ans = addto1(temp);
        Node* prev = reverse(ans);
        
        return prev;
    }
}; 

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends