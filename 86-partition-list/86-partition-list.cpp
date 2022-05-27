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
    ListNode* partition(ListNode* head, int x) {
        
        //Approach 1: Using Dummy Nodes
        ListNode dummy1(-1);
        ListNode* temp1 = &dummy1;
        
        ListNode dummy2(-1);
        ListNode* temp2 = &dummy2;
        
        ListNode* temp = head;
        
        while(temp){
            
            if(temp->val < x){
                temp1->next = temp;
                temp1 = temp1->next;
            }
            
            else{
                temp2->next = temp;
                temp2 = temp2->next;
            }
            
            temp = temp->next;
        }
        
        //Last Node
        temp2->next = NULL;
        
        //Adding second linked list after the first linked list;
        temp1->next = dummy2.next;
        
        return dummy1.next;
        
    }
};