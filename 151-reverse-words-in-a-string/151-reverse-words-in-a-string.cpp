class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.size();
        string res = "";
        vector<string> ans;
        int i = 0;
        
        while(i < n){
            
            while(s[i] == ' ' && i < n)
                i++;
            
            string sub = "";
            while(s[i] != ' ' && i < n){
                sub += s[i];
                i++;
            }
            
            if(sub != "")
                ans.push_back(sub);
        }
        
        for(int j = ans.size() - 1; j >= 0; j--){
            
            res += ans[j];
            if(j != 0)
                res += ' ';
        }
        
        return res;      
    }
};