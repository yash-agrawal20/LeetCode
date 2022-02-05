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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.empty())
            return nullptr;
        
        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        
        return lists.front();
        
    }
    
    ListNode *mergeTwoLists(ListNode *L1, ListNode *L2){
        
        if(L1 == nullptr){
            return L2;
        }
        
        if(L2 == nullptr){
            return L1;
        }
        
        if( L1->val <= L2->val){
            L1->next = mergeTwoLists(L1->next, L2);
            return L1;
        }
        
        else{
            L2->next = mergeTwoLists(L1, L2->next);
            return L2;
        }
    }
    
};