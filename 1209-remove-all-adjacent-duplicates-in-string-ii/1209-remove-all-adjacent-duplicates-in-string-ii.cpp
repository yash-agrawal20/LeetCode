class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char, int>> stk;
        
        for(int i = 0; i < s.size(); i++){
            
            if(!stk.empty()){
                
                int count = 1;
                if(stk.top().first == s[i])
                    count += stk.top().second;
                
                if(count == k){
                    
                    while(count > 1){
                        count--;
                        stk.pop();
                    }
                }
                
                else{
                    
                    stk.push({s[i], count});
                }
                
            }
            else{
                stk.push({s[i], 1});
            }
        }
            
        string res;
        
        while(!stk.empty()){
            res += stk.top().first;
            stk.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
        
    }
};