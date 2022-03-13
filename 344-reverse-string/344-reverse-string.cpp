class Solution {
    void reversal(vector<char>& s, int start, int end){
        
        if(start >= end)
            return;
        
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        
        reversal(s, start+1, end-1);
    }
    
public:
    void reverseString(vector<char>& s) {
        
        //Recursive Approach
        int start = 0;
        int end = s.size() - 1;
        
        reversal(s, start, end);
        
        //Iterative Approach
//         int start = 0;
//         int end = s.size() -1;
        
//         while(start < end){
            
//             char temp = s[start];
//             s[start] = s[end];
//             s[end] = temp;
//             start++;
//             end--;
//         }
    }
};