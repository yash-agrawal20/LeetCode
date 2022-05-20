class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        //Using sorting algorithm
        unordered_map<string, vector<string>> mp;
        
        for(int i = 0; i < strs.size(); i++){
            
            string t = strs[i];
            sort(t.begin(), t.end());
            mp[t].push_back(strs[i]);
        }
        
        vector<vector<string>> res;
        
        for(auto p : mp){
            res.push_back(p.second);
        }
        
        return res;
    }
};