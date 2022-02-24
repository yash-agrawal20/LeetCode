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
    
//     //Quick Sort Algorithm
//     ListNode* sortList(ListNode* head, ListNode* tail = nullptr) {
        
//         if(head != tail){
            
//             ListNode* smaller;
//             ListNode** smaller_next = &smaller;
//             for(ListNode** prev = &head->next; *prev != tail;){
                
//                 if(head->val > (**prev).val){
                    
//                     *smaller_next = *prev;
//                     smaller_next = &((**smaller_next).next);
//                     *prev = (**prev).next;
//                 }
                
//                 else{
//                     prev = &(**prev).next;
//                 }
//             }
            
//             *smaller_next = head;
//             head->next = sortList(head->next, tail);
//             head = sortList(smaller, head);
//         }
        
//         return head;
//     }
    
    //Merge Sort Algorithm
    ListNode* sortList(ListNode* head){
        
        bool done = (!head);
        
        for(int step = 1; !done; step *= 2){
            
            done = true;
            ListNode** next_ptr = &head;
            ListNode* remaining = head;
            ListNode* list[2];
            
            do{
                
                for(auto& sub_head : list){
                    
                    sub_head = remaining;
                    ListNode* tail = nullptr;
                    for(int i=0; i < step && remaining; ++i, remaining = remaining->next){
                        tail = remaining;
                    }
                    
                    if(tail){
                        tail->next = nullptr;
                    }
                }
                
                done &= !remaining;
            
                if(list[1]){
                
                while(list[0] || list[1]){
                    
                    int idx = (!list[1] || list[0] && list[0] -> val <= list[1]->val) ? 0 : 1;
                    *next_ptr = list[idx];
                    list[idx] = list[idx]->next;
                    next_ptr = &(**next_ptr).next;
                }
                    
                *next_ptr = nullptr;
                }
                
                else{
                    *next_ptr = list[0];
                }
            }while(remaining);
            
        }
        
        return head;
    }
};