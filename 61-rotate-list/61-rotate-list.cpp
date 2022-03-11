/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head)
            return head;
        
        int length = 1;
        ListNode* tail = head;
        while(tail->next){
            length++;
            tail = tail->next;
        }
        
        //IMP
        k = k % length;
        
        if(k == 0)
            return head;
    
        
        ListNode* curr = head;
        for(int i = 0; i < (length-k-1); i++){
            curr = curr->next;
        }
        
        ListNode* new_head = curr->next;
        curr->next = NULL;
        
        //Making the Linked-List a circular linked list
        tail->next = head;
        
        return new_head;
        
        
    }
};