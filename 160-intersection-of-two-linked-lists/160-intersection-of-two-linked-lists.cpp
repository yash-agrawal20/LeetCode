/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_set<ListNode*> st;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        
        while(tempA){
            st.insert(tempA);
            tempA = tempA->next;
        }
        
        while(tempB){
            if(st.find(tempB) != st.end())
                return tempB;
            
            tempB = tempB->next;
        }
        
        return NULL;       
        
    }
};