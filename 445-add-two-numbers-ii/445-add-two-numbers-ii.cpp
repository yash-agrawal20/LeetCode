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

//Reference:
// https://leetcode.com/problems/reverse-linked-list/
// https://leetcode.com/problems/add-two-numbers/
// https://leetcode.com/problems/add-two-numbers-ii/discuss/798754/Easy-C%2B%2B-solution-without-using-stack-or-reversing-the-inputoutput-list.

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
        
//         ListNode* head_l1 = reverseList(l1);
//         ListNode* head_l2 = reverseList(l2);
        
//         ListNode dummy(0);
//         ListNode* currNode = &dummy;
//         int carry = 0;
        
//         while(head_l1 || head_l2 || carry){
            
//             if(head_l1){
//                 carry += head_l1->val;
//             }
            
//             if(head_l2){
//                 carry += head_l2->val;
//             }
            
//             currNode->next = new ListNode(carry % 10);
//             currNode = currNode->next;
            
//             carry /= 10;
            
//             if(head_l1){
//                 head_l1 = head_l1->next;
//             }
            
//             if(head_l2){
//                 head_l2 = head_l2->next;
//             }
//         }
        
//         //IMP dummy.next
//         return reverseList(dummy.next);
        
        //Using Deque Data Structure to store the numbers of the Linked List and
        //addding them
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        
        //For storing the values of nodes in linked list
        deque<int> d1;
        deque<int> d2;
        
        while(temp1 || temp2){
            
            if(temp1){
                d1.push_back(temp1->val);
                temp1 = temp1->next;
            }
            if(temp2){
                d2.push_back(temp2->val);
                temp2 = temp2->next;
            }
        }
        
        int i = d1.size()-1;
        int j = d2.size()-1;
        int carry = 0;
        
        //For storing the values of the sum
        deque<int> d3;
        
        //Adding from the back
        while(i >= 0 || j >= 0){
            
            if(i >= 0)
                carry += d1[i];
            if(j >= 0)
                carry += d2[j];
            
            d3.push_front(carry % 10);
            carry = carry / 10;
            
            i--;
            j--;
        }
        
        if(carry > 0)
            d3.push_front(carry);
        
        //New Linked List
        ListNode dummy(0);
        ListNode* l = &dummy;
        
        while(!d3.empty()){
            
            l->next = new ListNode(d3.front());
            l = l->next;
            d3.pop_front();
        }
        
        return dummy.next;        
        
    }
};