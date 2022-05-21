class Solution {
public:
    bool isNumber(string s) {
        
        int n = s.size();
        int i = 0, digits = 0, dots = 0;
        
        for(; i < n && isspace(s[i]); i++);
        
        if(s[i] == '+' || s[i] == '-')
            i++;
        
        for(; i < n && isdigit(s[i]) || s[i] == '.'; i++){
            if(isdigit(s[i]))
                digits++;
            
            else
                dots++;
        }
        
        if(!digits || dots > 1)
            return false;
        
        if(s[i] == 'e' || s[i] == 'E'){
            
            i++;
            if(s[i] == '+' || s[i] == '-')
                i++;
            
            digits = 0;
            for(; i < n && isdigit(s[i]); i++)
                digits++;
            
            if(!digits)
                return false;
        }
        
        for(; i < n && isspace(s[i]); i++);
        
        return i == n;
        
                
    }
};