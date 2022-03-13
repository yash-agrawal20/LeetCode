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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        
        //Iterative Approach
        while(curr != NULL){
            
            //Store curr->next
            forward = curr->next;
            
            //Reverse the link
            curr->next = prev;
            
            //Move the pointers forward
            prev = curr;
            curr = forward;
        }
        
        return prev;
        
    }
};