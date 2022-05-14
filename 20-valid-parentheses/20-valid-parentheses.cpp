class Solution {
public:
    bool isValid(string s) {
        
        vector<char> ans;
        int l = s.length();
        
        if(l == 1) return false;
        
        for(int i = 0; i < l; i++){
            
            if(ans.empty()){
                ans.push_back(s[i]);
            }
            
            else if(s[i] == ')' && ans.back() == '(')
                ans.pop_back();
            
            else if(s[i] == ']' && ans.back() == '[')
                ans.pop_back();
            
            else if(s[i] == '}' && ans.back() == '{')
                ans.pop_back();
            
            else{
                ans.push_back(s[i]);
            }
        }
        
        if(ans.empty()) return true;
        else return false;
        
    }
};