// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

Node* subLinkedList(Node* l1, Node* l2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* Structure of linked list Node

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

//You are required to complete this method

//Reversing a linked list
Node* rev(Node* head){
    
    Node* forward = NULL;
    Node* curr = head;
    Node* prev = NULL;
    
    while(curr){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    
    return prev;
}


//Subtracting the bigger number from the smaller number
Node* sub(Node* g, Node* l){
    
    //g->greater;
    //l->lower
    g = rev(g);
    l = rev(l);
    Node* temp1 = g;
    Node* temp2 = l;
    Node* ans = new Node(0);
    Node* temp3 = ans;
    
    while(temp1->next && temp2->next){
        
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    while(temp1->next){
        
        Node* n = new Node(0);
        temp2->next = n;
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
    
    int rem = 0;
    temp1 = g;
    temp2 = l;
    
    while(temp1 && temp2){
        
        int x = temp1->data - temp2->data;
        if(x - rem >= 0){
            Node* n = new Node(x-rem);
            temp3->next = n;
            temp3 = temp3->next;
            rem = 0;
        }
        else{
            Node* n = new Node(x-rem+10);
            temp3->next = n;
            temp3 = temp3->next;
            rem = 1;
        }
        
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    Node* res = ans->next;
    
    res = rev(res);
    
    //Removing the leading zeroes
    while(res->data == 0){
        res = res->next;
    }
    
    return res;
}

Node* subLinkedList(Node* l1, Node* l2)
{
    //Your code here
    //Check if l1 or l2 is 0 or not
    if(l1->next == NULL && l1->data == 0){
        return l2;
    }
    
    if(l2->next == NULL && l2->data == 0){
        return l1;
    }
    
    //Remove the leading 0's
    while(l1->data == 0){
        l1 = l1->next;
    }
    while(l2->data == 0){
        l2 = l2->next;
    }
    
    //Finding which number is greater
    Node* temp1 = l1;
    Node* temp2 = l2;
    int count1 = 0;
    int count2 = 0;
    
    while(temp1){
        count1++;
        temp1 = temp1->next;
    }
    
    while(temp2){
        count2++;
        temp2 = temp2->next;
    }
    
    if(count1 > count2){
        return sub(l1, l2);
    }
    else if(count2 > count1){
        return sub(l2, l1);
    }
    else{
        while(l1 && l2){
            
            if(l1->data > l2->data) return sub(l1, l2);
            
            else if(l2->data > l1->data) return sub(l2, l1);
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        //If both the numbers are equal
        Node* n = new Node(0);
        n->next = NULL;
        return n;
    }
    
    return NULL;
}