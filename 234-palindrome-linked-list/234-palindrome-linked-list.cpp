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
    bool isPalindrome(ListNode* head) {
        
        ListNode* temp = head;
        vector<int> s;
        
        while(temp){
            s.push_back(temp->val);
            temp = temp->next;
        }
        
        int low = 0;
        int high = s.size() - 1;
        
        while(low <= high){
            
            if(s[low] != s[high])
                return false;
            
            low++;
            high--;
        }
        
        return true;
    }
};