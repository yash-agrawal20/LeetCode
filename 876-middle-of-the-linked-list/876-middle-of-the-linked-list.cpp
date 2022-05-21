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
    ListNode* middleNode(ListNode* head) {
        
        //Returns the total number of nodes present in Linked List
        //O(n)
//         int count = 0;
//         ListNode* temp = head;
        
//         while(temp){
//             count++;
//             temp = temp->next;
//         }
        
//         int req = count/2;
//         ListNode* res = head;
        
//         while(req--){
//             res = res->next;
//         }       
        
//         return res;  
        
        //Using slow ans fast pointers
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};