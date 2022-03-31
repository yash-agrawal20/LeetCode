class Solution {
private:
    typedef pair<int, char> pairs;
public:
    string restoreString(string s, vector<int>& indices) {
        
        int size = s.length();
        set<pairs> all;
        
        for(int i = 0; i < size; i++){
            
            pairs x = make_pair(indices[i], s[i]);
            all.insert(x);
        }
        
        string res = "";
        for(auto it: all){
            res += it.second;
        }
        
        return res;
        
    }
};