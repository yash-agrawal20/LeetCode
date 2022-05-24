class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        //Using deque data structure
        deque<int> qs;
        deque<int> qt;
        
        for(int i= 0; i < s.size(); i++){
            
            if(s[i] == '#'){
                if(!qs.empty())
                    qs.pop_back();
            }
            
            else
                qs.push_back(s[i]);
        }
        
        for(int i= 0; i < t.size(); i++){
            
            if(t[i] == '#'){
                if(!qt.empty())
                    qt.pop_back();
            }
            
            else
                qt.push_back(t[i]);
        }
        
        if(qs == qt)
            return true;
        else
            return false;
        
    }
};