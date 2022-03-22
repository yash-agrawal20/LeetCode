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
private:
    ListNode* reverseList(ListNode* head){
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        
        while(curr){
            
            forward = curr->next;
            
            curr->next = prev;
            
            prev = curr;
            curr = forward;
        }
        
        return prev;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        //Reversing both the linked list
        
        ListNode* head_l1 = reverseList(l1);
        ListNode* head_l2 = reverseList(l2);
        
        ListNode dummy(0);
        ListNode* currNode = &dummy;
        int carry = 0;
        
        while(head_l1 || head_l2 || carry){
            
            if(head_l1){
                carry += head_l1->val;
            }
            
            if(head_l2){
                carry += head_l2->val;
            }
            
            currNode->next = new ListNode(carry % 10);
            currNode = currNode->next;
            
            carry /= 10;
            
            if(head_l1){
                head_l1 = head_l1->next;
            }
            
            if(head_l2){
                head_l2 = head_l2->next;
            }
        }
        
        return reverseList(dummy.next);
        
        
    }
};