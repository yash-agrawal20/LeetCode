// { Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node* temp1 = head1;
    Node* temp2 = head2;
    int count1 = 0, count2 = 0;
    
    while(temp1){
        count1++;
        temp1 = temp1->next;
    }
    
    while(temp2){
        count2++;
        temp2 = temp2->next;
    }
    
    int diff = count1 - count2;
    Node* temp11 = head1;
    Node* temp12 = head2;
    
    if(diff > 0){
        
        while(diff--){
            temp11 = temp11->next;
        }
    }
    
    else if(diff < 0){
        
        diff *= -1;
        while(diff--){
            temp12 = temp12->next;
        }
    }
    
    while(temp11 && temp12){
        
        if(temp11 == temp12) return temp11->data;
        
        temp11 = temp11->next;
        temp12 = temp12->next;
    }
    
    return -1;
}

