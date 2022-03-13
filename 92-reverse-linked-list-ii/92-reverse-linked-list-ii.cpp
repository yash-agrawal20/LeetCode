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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left == right)
            return head;
        
        //Storing the left ans the right address
        ListNode* leftA = NULL;
        ListNode* rightA = NULL;
        ListNode* leftA_prev = NULL;
        
        ListNode* temp = head;
        int count = 1;
        
        while(leftA == NULL || rightA == NULL){
            
            if(count == left)
                leftA = temp;
            
            if(count == (left-1))
                leftA_prev = temp;
            
            if(count == right)
                rightA = temp->next;
            
            if(temp == NULL)
                break;
            
            temp = temp->next;
            count++;
        }
        
        //Iterative Approach
        ListNode* prev = NULL;
        ListNode* curr = leftA;
        ListNode* forward = NULL;
        
        while(curr != rightA){
            
            forward = curr->next;
            
            curr->next = prev;
            
            prev = curr;
            curr = forward;
        }
        
        if(leftA_prev != NULL)
            leftA_prev->next = prev;
        
        leftA->next = rightA;
        
        if(left == 1)
            return prev;
        
        return head;
    }
};