// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

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

void reorderList(Node* head) {
    // Your code here
    if(!head || !head->next){
        return;
    }
    
    //Finding the Mid Point of the linked list;
    Node* slow = head;
    Node* fast = head;
    
    //Slow gives us the mid - point of the linked list
    while(fast && fast->next){
        
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node* curr = slow;
    Node* forward = NULL;
    Node* prev = NULL;
    
    //The second half of the list list is reversed
    //Prev gives us the pointer to the last node;
    while(curr){
        
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    
    Node* start = head;
    Node* end = prev;
    Node* temp;
    
    //Rearranging the nodes accordingly
    while(end->next){
        
        temp = start->next;
        start->next = end;
        start = temp;
        
        temp = end->next;
        end->next = start;
        end = temp;
    }
}