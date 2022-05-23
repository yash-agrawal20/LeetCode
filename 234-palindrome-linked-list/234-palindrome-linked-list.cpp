//https://leetcode.com/problems/palindrome-linked-list/discuss/1137696/Short-and-Easy-w-Explanation-or-T-%3A-O(N)-S-%3A-O(1)-Solution-using-Fast-and-Slow

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
        
        //TC: O(n); SC: O(n)
//         ListNode* temp = head;
//         vector<int> s;
        
//         while(temp){
//             s.push_back(temp->val);
//             temp = temp->next;
//         }
        
//         int low = 0;
//         int high = s.size() - 1;
        
//         while(low <= high){
            
//             if(s[low] != s[high])
//                 return false;
            
//             low++;
//             high--;
//         }
        
//         return true;
        
        //TC: O(n); SC: O(1)
        ListNode *slow = head, *fast = head;
        ListNode *tmp, *prev = NULL;
        
        while(fast && fast->next){
            
            fast = fast->next->next;
            //Reversing a Linked list
            tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        
        //For odd length linked list
        if(fast)
            slow = slow->next;
        
        while(slow){
            
            if(slow->val != prev->val)
                return false;
            
            slow = slow->next;
            prev = prev->next;
        }
        
        return true;
        
    }
};