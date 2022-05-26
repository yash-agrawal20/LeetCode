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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
//         unordered_map<int, ListNode*> mp;
//         int m = 0;
//         ListNode* temp = head;
        
//         while(temp){
            
//             mp[m] = temp;
//             m++;
//             temp = temp->next;
//         }
        
//         if((m - n) == 0)
//             head = head->next;
        
//         else
//             mp[m-n-1]->next = mp[m-n]->next;
        
//         return head;
        
        //Using dummy node
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = head;
        
        while(n > 0 && right){
            right = right->next;
            n -= 1;
        }
        
        while(right){
            right = right->next;
            left = left->next;
        }
        
        left->next = left->next->next;
        
        return dummy->next;
        
    }
};